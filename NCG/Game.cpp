#include "Game.h"

Game::Game()
{
	this->player1 = new Player();
	player1->getHand()->setMaxY(650.0f);
	player1->getHand()->setMinY(580.0f);
	player1->getHand()->setY(650.0f);

	this->player2 = new Player();
	player2->getHand()->setMaxY(-80.0f);
	player2->getHand()->setMinY(-80.0f);
	player2->getHand()->setY(-80.0f);
}

void Game::setPlayerOne(Player* player)
{
	this->player1 = player;
}

void Game::setPlayerTwo(Player* player)
{
	this->player1 = player;
}

Player* Game::getPlayerOne()
{
	return this->player1;
}

Player* Game::getPlayerTwo()
{
	return this->player2;
}

void Game::setLanes(std::vector<Lane*> lanes)
{
	this->lanes = lanes;
}

void Game::setDecks(std::vector<Deck*> lanes)
{
	this->decks = decks;
}

std::vector<Lane*> Game::getLanes()
{
	return this->lanes;
}

std::vector<Deck*> Game::getDecks()
{
	return this->decks;
}

void Game::start()
{
	if (player1 != nullptr)
		player1->start();

	if (player2 != nullptr)
		player2->start();
}

void Game::update(sf::Event event, int targetSize)
{
	if (player1 != nullptr)
		player1->update(event, this->lanes, targetSize);

	if (player2 != nullptr)
		player2->update(event, this->lanes, targetSize);

	for (Lane* lane : this->lanes)
		lane->update(event);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (Lane *lane : this->lanes)
		lane->draw(target, states);

	if (player1 != nullptr)
		player1->draw(target, states);
	
	if (player2 != nullptr)
		player2->draw(target, states);
}
