#include <vector>
#include <string>

#pragma once

// https://stackoverflow.com/questions/8771881/setting-multiple-attributes-for-enum-structure
// Make enum of all Abilities
enum AbilitiesEnum
{
	NoAbilities = 1 << 0, // 00000001, 0x01 | No Abilities
	Multistrike = 1 << 1, // 00000010, 0x02 | Multistrike
	Spellproof  = 1 << 2, // 00000100, 0x04 | Spellproof
	Floaty      = 1 << 3, // 00001000, 0x08 | Floaty
	TeamUp      = 1 << 4, // 00010000, 0x10 | Team Up
	Hidden      = 1 << 5, // 00100000, 0x20 | Hidden
	Charge      = 1 << 6, // 01000000, 0x40 | Charge Attack
};

struct Abilities // Make Abilities struct
{
public:
	Abilities() {} // Make default constructor

	Abilities(AbilitiesEnum abilities, int assassin=0, int splash=0, int armor=0) // Make constructor
	{
		this->abilities = abilities; // Store internal abilities to the argument

		this->Assassin = assassin; // Store internal abilities to the argument
		this->Splash = splash; // Store internal abilities to the argument
		this->Armor = armor; // Store internal abilities to the argument
	}

	int getSize() // Get number of Abilities
	{
		if (this->size == -1) // If never set
			this->getString(); // Run get strings to get the number of Abilities

		return this->size; // return number Abilities
	}

	std::string getString() // 
	{
		if (this->size == -1) // If never set
		{
			switch (this->abilities) // Switch 
			{
			case Multistrike:
				this->abilitiesTxt += "Multistrike\n";
				this->size++;
				//break;

			case Spellproof:
				this->abilitiesTxt += "Spellproof\n";
				this->size++;
				//break;

			case Floaty:
				this->abilitiesTxt += "Multistrike\n";
				this->size++;
				//break;

			case TeamUp:
				this->abilitiesTxt += "TeamUp\n";
				this->size++;
				//break;

			case Hidden:
				this->abilitiesTxt += "Hidden\n";
				this->size++;
				//break;

			case Charge:
				this->abilitiesTxt += "Charge\n";
				this->size++;
				//break;

			case NoAbilities:
				this->abilitiesTxt += "";
				this->size = 0;
				break;
			}

			if (Assassin > 0)
			{
				this->abilitiesTxt += "Assassin: " + std::to_string(Assassin) + "\n";
				this->size++;
			}

			if (Splash > 0)
			{
				this->abilitiesTxt += "Splash: " + std::to_string(Splash) + "\n";
				this->size++;
			}

			if (Armor > 0)
			{
				this->abilitiesTxt += "Armor: " + std::to_string(Armor) + "\n";
				this->size++;
			}
		}

		return this->abilitiesTxt;
	}

	AbilitiesEnum getAbilities()
	{
		return this->abilities;
	}

private:
	AbilitiesEnum abilities;

	int Assassin;
	int Splash;
	int Armor;

	std::string abilitiesTxt;
	int size = -1;
};
