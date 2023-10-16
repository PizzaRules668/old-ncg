#include "Card.h"

Card::Card()
{}

Card::Card(Rarity rarity, int cost, std::string name, std::string imagePath)
{
	this->rarity = rarity;
	this->abilities = abilities;
	this->cost = cost;

	this->name = name;

	this->creature = false;
	this->lore = "Name: " + this->name + ",\n Rarity: " + getRarityType(this->rarity) + ",\n Cost: " + std::to_string(this->cost) + ",\n Ablities: " + this->abilities.getString();

	this->imagePath = imagePath;
	if (!this->tex.loadFromFile(imagePath))
		throw "Could not load texture";
	this->sprite.setTexture(this->tex);
}

Card::Card(Rarity rarity, int cost, std::string name, sf::Texture texture)
{
	this->rarity = rarity;
	this->abilities = abilities;
	this->cost = cost;

	this->name = name;

	this->creature = false;
	this->lore = "Name: " + this->name + ",\n Rarity: " + getRarityType(this->rarity) + ",\n Cost: " + std::to_string(this->cost) + ",\n Ablities: " + this->abilities.getString();
	
	this->tex = texture;
	this->sprite.setTexture(this->tex);
}

Card::Card(Rarity rarity, int cost, int attack, int hp, Abilities abilities, std::string name)
{
	this->rarity = rarity;
	this->abilities = abilities;
	this->cost = cost;

	this->hp = hp;
	this->attack = attack;

	this->name = name;
	this->lore = "\nName: " + this->name + ",\n Rarity: " + getRarityType(this->rarity) + ",\n Cost: " + std::to_string(this->cost) + ",\n Attack: "
				+ std::to_string(this->attack) + ",\n Hp: " + std::to_string(this->hp) + ",\n Ablities: " + this->abilities.getString();

	this->creature = true;
}

Card::Card(Rarity rarity, int cost, int attack, int hp, Abilities abilities, std::string name, std::string imagePath)
{
	this->rarity = rarity;
	this->abilities = abilities;
	this->cost = cost;

	this->hp = hp;
	this->attack = attack;

	this->name = name;

	this->creature = true;
	this->lore = "\nName: " + name + ",\n Rarity: " + getRarityType(rarity) + ",\n Cost: " + std::to_string(cost) + ",\n Attack: "
				+ std::to_string(attack) + ",\n Hp: " + std::to_string(hp) + ",\n Ablities: " + this->abilities.getString();

	this->imagePath = imagePath;
	if (!this->tex.loadFromFile(imagePath))
		throw "Could not load texture";
	this->sprite.setTexture(this->tex);
}

Card::Card(Rarity rarity, int cost, int attack, int hp, Abilities abilities, std::string name, sf::Texture texture)
{
	this->rarity = rarity;
	this->abilities = abilities;
	this->cost = cost;

	this->hp = hp;
	this->attack = attack;

	this->name = name;
	this->lore = lore;

	this->creature = true;
	this->lore = "\nName: " + this->name + ",\n Rarity: " + getRarityType(this->rarity) + ",\n Cost: " + std::to_string(this->cost) + ",\n Attack: "
				+ std::to_string(this->attack) + ",\n Hp: " + std::to_string(this->hp) + ",\n Ablities: " + this->abilities.getString();

	this->tex = texture;
	this->sprite.setTexture(this->tex);
}

int Card::getHP()
{
	return this->hp;
}

int Card::getAttack()
{
	return this->attack;
}

void Card::attackCard(Card* creature)
{
	creature->takeDamage(this->attack);
}

void Card::takeDamage(int amount)
{
	this->hp -= amount;
}

void Card::heal(int amount)
{
	this->hp += amount;
}

void Card::weakenAttack(int amount)
{
	this->attack -= amount;
}

void Card::buffAttack(int amount)
{
	this->attack += amount;
}

std::string Card::getImagePath()
{
	return this->imagePath;
}

void Card::setTexture(std::string imagePath)
{
	this->imagePath = imagePath;
	if (!this->tex.loadFromFile(imagePath))
		throw "Could not load texture";
	this->sprite.setTexture(this->tex);
}

void Card::setTexture(sf::Texture texture)
{
	this->tex = texture;
	this->sprite.setTexture(this->tex);
}

sf::Texture Card::getTexture()
{
	return this->tex;
}

void Card::setSprite(sf::Sprite sprite)
{
	this->sprite = sprite;
}

sf::Sprite Card::getSprite()
{
	return this->sprite;
}

float Card::getX()
{
	return this->position.x;
	this->sprite.setPosition(this->position);
}

float Card::getY()
{
	return this->position.y;
	this->sprite.setPosition(this->position);
}

sf::Vector2f Card::getPosition()
{
	return this->position;
}

void Card::setX(float x)
{
	this->position.x = x;
	this->sprite.setPosition(this->position);
}

void Card::setY(float y)
{
	this->position.y = y;
	this->sprite.setPosition(this->position);
}

void Card::setPosition(sf::Vector2f position)
{
	this->position = position;
	this->sprite.setPosition(this->position);
}

void Card::setPosition(float x, float y)
{
	this->position = sf::Vector2f(x, y);
	this->sprite.setPosition(this->position);
}

std::string Card::getName()
{
	return this->name;
}

void Card::setInfo(std::string lore)
{
	this->lore = lore;
}

std::string Card::getInfo()
{
	if (this->creature)
		this->lore = "\nName: " + this->name + ",\n Rarity: " + getRarityType(this->rarity) + ",\n Cost: " + std::to_string(this->cost) + ",\n Attack: "
			+ std::to_string(this->attack) + ",\n Hp: " + std::to_string(this->hp) + ",\n Ablities: " + this->abilities.getString();

	else
		this->lore = "Name: " + this->name + ",\n Rarity: " + getRarityType(this->rarity) + ",\n Cost: " + std::to_string(this->cost) + ",\n Ablities: " + this->abilities.getString();

	return this->lore;
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

std::string getRarityType(Rarity rarity)
{
	switch (rarity)
	{
	default:
		break;
	case COMMON:
		return "Common";
	case RARE:
		return "Rare";
	case WANTED:
		return "Wanted";
	case LEGENDARY:
		return "Ledendary";
	}

	return "";
}
