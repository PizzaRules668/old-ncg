#include <algorithm>
#include <vector>
#include <random>
#include <string>

#include "Card.h"
#include "Hand.h"

#pragma once

class Deck : public sf::Drawable
{
public:
	Deck();
	Deck(int maxSize);
	Deck(std::vector<Card*> cards, std::string filePath);

	void shuffle();
	void shuffle(int seed);

	bool addCard(Card* card);

	void removeCard();
	void removeCard(int index);

	Card* getCard();
	Card* getCard(int index);
	std::vector<Card*> getCards();

	void setMaxSize(int maxSize);
	int getMaxSize();

	void setTexture(std::string filepath);
	void setTexture(sf::Texture texture);
	sf::Texture getTexture();

	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();

	float getX();
	float getY();
	sf::Vector2f getPosition();

	void setX(float x);
	void setY(float y);
	void setPosition(sf::Vector2f location);
	void setPosition(float x, float y);

	void update(sf::Event event, Hand* hand);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<Card*> cards;
	int maxSize;

	sf::Vector2f position;
	sf::Texture tex;
	sf::Sprite sprite;
};

