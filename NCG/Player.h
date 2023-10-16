#include <SFML/Graphics/Drawable.hpp>

#include "Energy.hpp"
#include "Deck.h"
#include "Hand.h"

#pragma once

class Player : public sf::Drawable
{
public:
	Player();

	Hand* getHand();
	void setHand(Hand* hand);

	void start();
	void update(sf::Event event, std::vector<Lane*> lanes, float targetSize);

	Deck* getDeck1();
	Deck* getDeck2();

	void setDeck1(Deck *deck);
	void setDeck1(Deck* deck, int x, int y);
	void setDeck1(Deck* deck, sf::Vector2f pos);
	void setDeck2(Deck* deck);
	void setDeck2(Deck* deck, int x, int y);
	void setDeck2(Deck* deck, sf::Vector2f pos);

	void setEnergy(Energy* energy);
	Energy* getEnergy();

	int getHP();
	void setHP(int hp);
	void heal(int amount);
	void takeDamage(int amount);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	int hp = 20;

	Energy* energy;

	Hand *hand;

	Deck *deck1;
	Deck *deck2;
};