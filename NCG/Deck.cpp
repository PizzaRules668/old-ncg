#include "Deck.h"

Deck::Deck()
{
	this->maxSize = 7;
}

Deck::Deck(int maxSize)
{
	this->maxSize = maxSize;
}

Deck::Deck(std::vector<Card*> cards, std::string filePath)
{
	this->cards = cards;

	this->setTexture(filePath);
}

void Deck::shuffle()
{
	std::default_random_engine rnd;
	std::shuffle(this->cards.begin(), this->cards.end(), rnd);
}

void Deck::shuffle(int seed)
{
	std::default_random_engine rnd(seed);
	std::shuffle(this->cards.begin(), this->cards.end(), rnd);
}

bool Deck::addCard(Card* card)
{
	if (this->cards.size() == this->maxSize)
		return false;

	cards.push_back(card);
	return true;
}

void Deck::removeCard()
{
	if (cards.size() <= 1)
		cards.erase(cards.begin());
}

void Deck::removeCard(int index)
{
	if (cards.size() <= 1)
		cards.erase(cards.begin() + index);
}

Card* Deck::getCard()
{
	return this->cards.at(0);
}

Card* Deck::getCard(int index)
{
	return this->cards.at(index);
}

std::vector<Card*> Deck::getCards()
{
	return this->cards;
}

void Deck::setTexture(std::string filePath)
{
	if (!this->tex.loadFromFile(filePath))
		throw "Could not load texture";
	this->sprite.setTexture(this->tex);
}

void Deck::setTexture(sf::Texture texture)
{
	this->tex = texture;
	this->sprite.setTexture(this->tex);
}

sf::Texture Deck::getTexture()
{
	return this->tex;
}

void Deck::setSprite(sf::Sprite sprite)
{
	this->sprite = sprite;
}

sf::Sprite Deck::getSprite()
{
	return this->sprite;
}

float Deck::getX()
{
	return this->position.x;
	this->sprite.setPosition(this->position);
}

float Deck::getY()
{
	return this->position.y;
	this->sprite.setPosition(this->position);
}

sf::Vector2f Deck::getPosition()
{
	return this->position;
}

void Deck::setX(float x)
{
	this->position.x = x;
	this->sprite.setPosition(this->position);
}

void Deck::setY(float y)
{
	this->position.y = y;
	this->sprite.setPosition(this->position);
}

void Deck::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->sprite.setPosition(this->position);
}

void Deck::setPosition(float x, float y)
{
	this->position = sf::Vector2f(x, y);
	this->sprite.setPosition(this->position);
}

void Deck::update(sf::Event event, Hand* hand)
{
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		if (this->sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			if (this->getCards().size() != 0)
				if (hand->addCard(this->getCard(0)))
					this->cards.erase(this->cards.begin());
}

void Deck::setMaxSize(int maxSize)
{
	this->maxSize = maxSize;
}

int Deck::getMaxSize()
{
	return this->maxSize;
}

void Deck::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}