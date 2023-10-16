#include "Player.h"

Player::Player()
{
	this->deck1 = new Deck();
	this->deck2 = new Deck();

	this->hand = new Hand();

	this->energy = new Energy();
}

Hand* Player::getHand()
{
	return this->hand;
}

void Player::setHand(Hand* hand)
{
	this->hand = hand;
}

Deck* Player::getDeck1()
{
	return this->deck1;
}

Deck* Player::getDeck2()
{
	return this->deck2;
}

void Player::start()
{
	this->deck1->shuffle();
	this->deck2->shuffle();
}

void Player::update(sf::Event event, std::vector<Lane*> lanes, float targetSize)
{
	this->deck1->update(event, this->hand);
	this->deck2->update(event, this->hand);

	this->energy->update(event, targetSize);
	this->hand->update(event, lanes, targetSize);
}

void Player::setDeck1(Deck* deck)
{
	this->deck1 = deck;
}

void Player::setDeck1(Deck* deck, int x, int y)
{
	this->deck1 = deck;
	this->deck1->setPosition(x, y);
}

void Player::setDeck1(Deck* deck, sf::Vector2f pos)
{
	this->deck1 = deck;
	this->deck1->setPosition(pos);
}

void Player::setDeck2(Deck* deck)
{
	this->deck2 = deck;
}

void Player::setDeck2(Deck* deck, int x, int y)
{
	this->deck2 = deck;
	this->deck2->setPosition(x, y);
}

void Player::setDeck2(Deck* deck, sf::Vector2f pos)
{
	this->deck2 = deck;
	this->deck2->setPosition(pos);
}

void Player::setEnergy(Energy* energy)
{
	this->energy = energy;
}

Energy* Player::getEnergy()
{
	return this->energy;
}

int Player::getHP()
{
	return this->hp;
}

void Player::setHP(int hp)
{
	this->hp = hp;
}

void Player::heal(int amount)
{
	this->hp += amount;
}

void Player::takeDamage(int amount)
{
	this->hp -= amount;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (deck1 != nullptr)
		deck1->draw(target, states);

	if (deck2 != nullptr)
		deck2->draw(target, states);

	if (hand != nullptr)
		hand->draw(target, states);

	if (energy != nullptr)
		energy->draw(target, states);
}