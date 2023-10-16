#include "Lane.h"

Lane::Lane()
{
	this->initText();

	this->floaty = false;
}
Lane::Lane(std::string filePath)
{
	this->initText();

	this->setTexture(filePath);
	this->floaty = floaty;
}
Lane::Lane(bool floaty, std::string filePath)
{
	this->initText();

	this->setTexture(filePath);
	this->floaty = floaty;
}

void Lane::initText()
{
	this->comicSans.loadFromFile("assets/ComicSans.TTF");
	this->infoDisplay.setFont(this->comicSans);
	this->infoDisplay.setFillColor(sf::Color::White);
	this->infoDisplay.setScale(0.5f, 0.5f);
	this->infoDisplay.setOutlineColor(sf::Color::Black);
	this->infoDisplay.setOutlineThickness(3);

	this->AblityButtonText.setFont(this->comicSans);
	this->AblityButtonText.setFillColor(sf::Color::White);
	this->AblityButtonText.setScale(0.5f, 0.5f);
	this->AblityButtonText.setOutlineColor(sf::Color::Black);
	this->AblityButtonText.setOutlineThickness(3);

	this->AttackButtonText.setFont(this->comicSans);
	this->AttackButtonText.setFillColor(sf::Color::White);
	this->AttackButtonText.setScale(0.5f, 0.5f);
	this->AttackButtonText.setOutlineColor(sf::Color::Black);
	this->AttackButtonText.setOutlineThickness(3);
}

bool Lane::addCard(Card* card)
{
	if (this->cards.size() == 0)
	{
		if (this->floaty)
			if (card->abilities.getAbilities() & Floaty)
				return false;
	}

	else if (this->cards.size() == 1)
	{
		if (this->floaty)
			if (!(card->abilities.getAbilities() & Floaty) && !((card->abilities.getAbilities() & TeamUp) || (cards.at(0)->abilities.getAbilities() & TeamUp)))
				return false;
	}

	card->setPosition(this->position.x, this->position.y + 200);
	card->onPlay();
	cards.push_back(card);

	return true;
}

void Lane::removeCard()
{
	this->cards.erase(cards.begin(), cards.begin()+1);
}

void Lane::removeCard(int index)
{
	this->cards.erase(cards.begin(), cards.begin()+index);
}

void Lane::update(sf::Event event)
{
	if (this->cards.size() == 1)
	{
		for (int i = 0; i < this->cards.size(); i++)
		{
			if (this->cards.at(i)->getHP() == 0)
			{
				this->cards.at(i)->onDestroy();
				this->removeCard(i);
			}

			if (this->cards.at(i)->getPosition() == this->position)
				this->cards.at(i)->setPosition(this->position);

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				if (this->cards.at(i)->getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					this->infoDisplay.setString(this->cards.at(i)->getInfo());
					this->infoDisplay.setOrigin(this->infoDisplay.getLocalBounds().width, this->infoDisplay.getLocalBounds().height);
					this->infoDisplay.setPosition(event.mouseButton.x, event.mouseButton.y);
				}

				else if (!this->cards.at(i)->getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					this->infoDisplay.setString("");
			}

			else if (!this->cards.at(i)->getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
				this->infoDisplay.setString("");

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (this->AblityButtonText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					std::cout << "Ablity" << std::endl;
				}
				else if (this->AttackButtonText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				{
					std::cout << "Attack" << std::endl;
				}

				this->click = !click;
				if (this->click)
				{
					std::cout << this->yourCards.size() << std::endl;
					if (this->yourCards.at(i)->getSprite().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
					{
						if (this->yourCards.at(i)->abilities.getSize() != 0)
						{
							this->AblityButtonText.setPosition(event.mouseButton.x, event.mouseButton.y-20);
							this->AblityButtonText.setString("Use Ablities");
							this->AblityButtonRender = true;
						}
						else
						{
							this->AblityButtonText.setString("");
							this->AblityButtonRender = false;
						}

						if (this->yourCards.at(i)->getAttack() != 0)
						{
							this->AttackButtonText.setPosition(event.mouseButton.x, event.mouseButton.y);
							this->AttackButtonText.setString("Attack");
							this->AttackButtonRender = true;
						}
						else
						{
							this->AttackButtonText.setString("");
							this->AttackButtonRender = false;
						}
					}
				}

				if (!this->click)
				{
					this->AttackButtonText.setString("");
					this->AblityButtonText.setString("");
					this->AttackButtonRender = false;
					this->AblityButtonRender = false;
				}
			}
		}
	}
}

void Lane::setTexture(std::string filepath)
{
	this->tex.loadFromFile(filepath);
	this->sprite.setTexture(this->tex);
}

void Lane::setTexture(sf::Texture texture)
{
	this->tex = texture;
	this->sprite.setTexture(this->tex);
}

sf::Texture Lane::getTexture()
{
	return this->tex;
}

void Lane::setSprite(sf::Sprite sprite)
{
	this->sprite = sprite;
}

sf::Sprite Lane::getSprite()
{
	return this->sprite;
}

void Lane::attack(Lane *defendingLane)
{
	this->yourCards.at(0)->attackCard(defendingLane->getCards().at(0));
}

void Lane::attack(Card* defendingCreature)
{
	this->yourCards.at(0)->attackCard(defendingCreature);
}

float Lane::getX()
{
	return this->position.x;
}

float Lane::getY()
{
	return this->position.y;
}

sf::Vector2f Lane::getPosition()
{
	return this->position;
}

void Lane::setX(float x)
{
	this->position.x = x;
	this->sprite.setPosition(this->position);
}

void Lane::setY(float y)
{
	this->position.y = y;
	this->sprite.setPosition(this->position);
}

void Lane::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	this->sprite.setPosition(this->position);
}

void Lane::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->sprite.setPosition(this->position);
}

std::vector<Card*> Lane::getCards()
{
	return this->cards;
}

std::string Lane::log()
{
	std::string log;

	log.append("Floaty: " + std::to_string(this->floaty) + "\n");
	log.append("Number of Cards: " + std::to_string(this->cards.size()) + "\n");

	return log;
}

void Lane::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);

	for (int i = 0; i < this->cards.size(); i++)
		this->cards.at(i)->draw(target, states);

	if (this->AblityButtonRender)
		target.draw(this->AblityButtonText);

	if (this->AttackButtonRender)
		target.draw(this->AttackButtonText);

	target.draw(this->infoDisplay, states);
}