#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Lane.h"

#pragma once

class Game : public sf::Drawable
{
public:
	Game();

	void setPlayerOne(Player* player);
	void setPlayerTwo(Player* player);
	Player* getPlayerOne();
	Player* getPlayerTwo();

	void setLanes(std::vector<Lane*> lanes);
	void setDecks(std::vector<Deck*> lanes);
	std::vector<Lane*> getLanes();
	std::vector<Deck*> getDecks();

	void start();
	void update(sf::Event event, int targetSize);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<Lane*> lanes;
	std::vector<Deck*> decks;

	Player *player1;
	Player *player2;
};

