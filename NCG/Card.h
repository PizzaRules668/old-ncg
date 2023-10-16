#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Rarity.hpp"
#include "Abilities.hpp"

#pragma once

std::string getRarityType(Rarity rarity);

class Card : public sf::Drawable
{
public:
	Card();
	Card(Rarity rarity, int cost, std::string name, std::string imagePath);
	Card(Rarity rarity, int cost, std::string name, sf::Texture texture);
	Card(Rarity rarity, int cost, int attack, int hp, Abilities abilities, std::string name);
	Card(Rarity rarity, int cost, int attack, int hp, Abilities abilities, std::string name, std::string imagePath);
	Card(Rarity rarity, int cost, int attack, int hp, Abilities abilities, std::string name, sf::Texture texture);

	int getHP();
	int getAttack();

	void attackCard(Card* creature);
	void takeDamage(int damageAmount);
	void heal(int amount);

	void weakenAttack(int amount);
	void buffAttack(int amount);

	std::string getImagePath();
	std::string getName();

	void setInfo(std::string lore);
	std::string getInfo();

	void setTexture(std::string imagePath);
	void setTexture(sf::Texture texture);
	sf::Texture getTexture();

	void setSprite(sf::Sprite sprite);
	sf::Sprite getSprite();

	float getX();
	float getY();
	sf::Vector2f getPosition();

	void setX(float x);
	void setY(float y);
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);

	void(*onPlay)() = []() { std::cout << "Placed Card" << std::endl; };
	void(*onDraw)() = []() { std::cout << "Drawed New Card" << std::endl; };
	void(*onCardPlay)() = []() { std::cout << "New Card Played" << std::endl; };
	void(*onDestroy)() = []() { std::cout << "Destroyed Card" << std::endl; };
	void(*onTurn)() = []() { std::cout << "Your Turn" << std::endl; };

	Abilities abilities;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Vector2f position;

	bool creature;

	int hp;
	int cost;
	int attack;

	std::string name;
	std::string lore;

	Rarity rarity;
	std::string imagePath;
	sf::Texture tex;
	sf::Sprite sprite;
};