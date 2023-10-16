#include <vector>
#include <iostream>
#include <fstream>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System.hpp>

#include "Lane.h"

#pragma once

class Hand : public sf::Drawable
{
public:
	Hand();

	void setY(int y);
	void setMaxY(int y);
	void setMinY(int y);

	int getY();
	int getMaxY();
	int getMinY();
	
	int cardAtXY(float x, float y);
	int cardAtXY(sf::Vector2f location);

	void update(sf::Event event, std::vector<Lane*> lanes, float targetSize);

	void setMaxSize(int maxSize);
	int getMaxSize();

	bool addCard(Card* card);
	void removeCard(int index);

	int getCard(Card* card);
	Card* getCard();
	Card* getCard(int index);
	std::vector<Card*> getCards();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	std::vector<Card*> cards;

	sf::Vector2f mouseOffset;
	bool mouseClicked = false;
	bool mouseInside = false;
	bool dragging = false;
	int mouseX = 0;
	int mouseY = 0;
	int card;

	sf::Vector2f mouseClickPos;

	int yPos;
	int maxY;
	int minY;

	int maxSize = 7;

	mutable std::ofstream loggingFile;

	sf::Text infoDisplay;
	sf::Font comicSans;
};

