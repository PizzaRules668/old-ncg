#include "Hand.h"

Hand::Hand()
{
	this->comicSans.loadFromFile("assets/ComicSans.TTF");
	this->infoDisplay.setFont(this->comicSans);
	this->infoDisplay.setFillColor(sf::Color::White);
	this->infoDisplay.setScale(0.5f, 0.5f);
	this->infoDisplay.setOutlineColor(sf::Color::Black);
	this->infoDisplay.setOutlineThickness(3);

	this->loggingFile.open("../log.txt");
}

float calculatePos(int id, int numOfCards, float windowWidth, float imageWidth)
{
	return (windowWidth / numOfCards * id) - imageWidth;
}

void Hand::setY(int y)
{
	this->yPos = y;

	for (int i = 0; i < this->getCards().size(); i++)
		getCard(i)->setY(this->yPos);
}

void Hand::setMaxY(int y)
{
	this->maxY = y;
}

void Hand::setMinY(int y)
{
	this->minY = y;
}

int Hand::getY()
{
	return this->yPos;
}

int Hand::getMaxY()
{
	return this->maxY;
}

int Hand::getMinY()
{
	return this->minY;
}

int Hand::cardAtXY(float x, float y)
{
	for (int i = 0; i < this->cards.size(); i++)
		if (getCard(i)->getSprite().getGlobalBounds().contains(x, y))
			return i;

	return -1;
}

int Hand::cardAtXY(sf::Vector2f location)
{
	for (int i = 0; i < this->cards.size(); i++)
		if (getCard(i)->getSprite().getGlobalBounds().contains(location))
			return i;

	return -1;
}

void Hand::update(sf::Event event, std::vector<Lane*> lanes, float targetSize)
{
	if (event.MouseMoved)
	{
		mouseX = event.mouseMove.x;
		mouseY = event.mouseMove.y;
	}

	//this->loggingFile << "X" << std::endl;
	for (int i = 0; i < this->getCards().size(); i++)
	{
		this->loggingFile << "I: " << i << std::endl;
		if (getCard(i)->getSprite().getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
		{
			getCard(i)->setY(this->minY);

			this->infoDisplay.setString(getCard(i)->getInfo());
			this->infoDisplay.setOrigin(this->infoDisplay.getLocalBounds().width, this->infoDisplay.getLocalBounds().height);
			this->infoDisplay.setPosition(event.mouseMove.x, event.mouseMove.y);
		}

		else
		{
			getCard(i)->setY(this->maxY);
			this->infoDisplay.setString("");
		}

		if (dragging)
		{
			this->loggingFile << "Dragging Card" << std::endl;
			this->loggingFile << "Card: " << this->card << std::endl;
			if (this->card != -1)
			{
				this->loggingFile << "Not -1" << std::endl;
				getCard(this->card)->setPosition(mouseX - mouseOffset.x, mouseY - mouseOffset.y);
				this->loggingFile << "Moving Card" << std::endl;
			}
		}

		if (!dragging)
		{
			getCard(i)->setX(calculatePos(i + 2, this->cards.size() + 2, targetSize, getCard(i)->getTexture().getSize().x) - 50.0f);
			this->loggingFile << "Not Dragging" << std::endl;
			this->card = -1;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		mouseClicked = true;

		this->card = cardAtXY(event.mouseButton.x, event.mouseButton.y);
		if (this->card != -1)
		{
			this->loggingFile << "Card: " << this->card << std::endl;
			this->loggingFile << "Card Name: " << this->getCard(this->card)->getName() << std::endl;
			dragging = true;
			this->loggingFile << "Dragging Start" << std::endl;

			mouseOffset.x = event.mouseButton.x - getCard(this->card)->getSprite().getGlobalBounds().left - getCard(this->card)->getSprite().getOrigin().x;
			this->loggingFile << "Get X" << std::endl;
			mouseOffset.y = event.mouseButton.y - getCard(this->card)->getSprite().getGlobalBounds().top - getCard(this->card)->getSprite().getOrigin().y;
			this->loggingFile << "Get Y" << std::endl;
		}
	}

	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
	{
		this->mouseClickPos.x = event.mouseButton.x;
		this->mouseClickPos.y = event.mouseButton.y;

		if (this->dragging)
		{
			this->loggingFile << "Dragging" << std::endl;
			if (this->card != -1)
			{
				this->loggingFile << "Dragging Card: " << this->card << std::endl;
				this->loggingFile << "Not -1" << std::endl;
				if (lanes.at(this->card)->getSprite().getGlobalBounds().contains(this->mouseClickPos))
				{
					this->loggingFile << "Let Go At Lane" << std::endl;
					if (lanes.at(this->card)->addCard(getCard(this->card)))
					{
						this->loggingFile << "Added Card to Lane" << std::endl;
						removeCard(this->card);
						this->loggingFile << "Removed Card From hand" << std::endl;
					}
				}
			}
		}

		mouseClicked = false;
		dragging = false;
	}
}

bool Hand::addCard(Card* card)
{
	if (this->cards.size() == this->maxSize)
		return false;

	cards.push_back(card);
	card->onDraw();
	card->setX(calculatePos(this->getCard(card)+1, this->cards.size()+2, 1280.0f, card->getTexture().getSize().x)-50.0f);
	return true;
}

void Hand::removeCard(int index)
{
	cards.erase(cards.begin() + index);
}

Card* Hand::getCard()
{
	return this->cards.at(0);
}

int Hand::getCard(Card* card)
{
	for (int i = 0; i < this->cards.size(); i++)
		if (this->cards.at(i) == card)
			return i;

	return -1;
}

Card* Hand::getCard(int index)
{
	this->loggingFile << "Size: " << this->cards.size() << std::endl;
	return this->cards.at(index);
}

std::vector<Card*> Hand::getCards()
{
	return this->cards;
}

void Hand::setMaxSize(int maxSize)
{
	this->maxSize = maxSize;
}

int Hand::getMaxSize()
{
	return this->maxSize;
}

void Hand::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < cards.size(); i++)
	{
		this->loggingFile << "Drawing Size: " << this->cards.size() << std::endl;
		this->loggingFile << "Drawing I: " << i << std::endl;
		cards.at(i)->draw(target, states);
	}

	target.draw(this->infoDisplay);
}