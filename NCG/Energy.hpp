#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#pragma once

class Energy : public sf::Drawable
{
public:
	Energy()
	{
		this->comicSans.loadFromFile("assets/ComicSans.TTF");
		this->yourEnergy.setFont(comicSans);
		this->yourEnergy.setFillColor(sf::Color::White);

		this->nextPhaseTexture.loadFromFile("assets/images/Next Phase.png");
		this->nextPhaseSprite.setTexture(this->nextPhaseTexture);
		this->nextPhaseSprite.scale(0.5f, 0.5f);
	}

	void update(sf::Event event, float targetSize)
	{
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			if (this->nextPhaseSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
				this->nextPhase();

		this->nextPhaseSprite.setPosition(0, 300.0f);
		
		this->yourEnergy.setString(std::to_string(this->getEnergy()));
		this->yourEnergy.setPosition(this->getPos(7, 7, targetSize, this->yourEnergy.getLocalBounds().width) - 75.0f, 300.0f);
	}

	void nextPhase()
	{
		if (this->phase == 1)
		{
			if (this->round == 12)
			{
				this->round = 1;
				this->energy = round;
			}

			else
			{
				this->energy = this->round;
			}

			this->phase = 2;
		}
		else if (this->phase == 2)
		{
			this->phase = 1;
		}
	}

	void nextPhase(int bonus)
	{
		
	}

	int getEnergy()
	{
		return this->energy;
	}

	std::string log()
	{
		return "";
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(this->yourEnergy);
		target.draw(this->nextPhaseSprite);
	}
private:
	float getPos(int id, int numOfCards, float windowWidth, float imageWidth)
	{
		return (windowWidth / numOfCards * id) - imageWidth;
	}

	// 0 = Creature Phase, 1 = Spell Phase
	int phase = 1;

	int round = 1;

	int energy = 0;

	sf::Font comicSans;
	sf::Text yourEnergy;
	sf::Texture nextPhaseTexture;
	sf::Sprite nextPhaseSprite;
};

