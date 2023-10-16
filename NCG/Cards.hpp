#include <vector>

#include "Card.h"
#include "Deck.h"

#pragma once

//							Rarity, Cost, Attack, Hp, Abilities, Floaty, TeamUp, Spellproof, Hidden, Multistrike, Charge, Assassin, Splash, Armor, Name, Image Path
Card Sizzle					(COMMON, 1, 1, 1, Abilities(NoAbilities), "Sizzle", "assets/images/Fire.png");
Card Blue_Sizzle			(COMMON, 2, 3, 1, Abilities(NoAbilities), "Blue Sizzle", "assets/images/Fire.png");
Card White_Sizzle			(COMMON, 3, 3, 1, Abilities(NoAbilities), "White Sizzle", "assets/images/Fire.png");
Card Burn_Bit				(COMMON, 1, 1, 1, Abilities(TeamUp), "Burn Bit", "assets/images/Fire.png");
Card Magma_Blob				(COMMON, 5, 6, 6, Abilities(NoAbilities), "Magma Blob", "assets/images/Fire.png");
Card Baby_Phoenix			(COMMON, 2, 3, 1, Abilities(Floaty), "Baby Phoenix", "assets/images/Fire.png");
Card Fire_Ant				(COMMON, 2, 2, 2, Abilities(Hidden), "Fire Ant", "assets/images/Fire.png");
Card Deto_Nate				(COMMON, 3, 3, 1, Abilities(NoAbilities, 4), "Deto Nate", "assets/images/Fire.png");
Card Sumo_Sizzle			(RARE, 3, 2, 2, Abilities(Floaty), "Sumo Sizzle", "assets/images/Fire.png");
Card Sizzling_Coffee		(RARE, 4, 2, 2, Abilities(NoAbilities, 2), "Sizzling Coffee", "assets/images/Fire.png");
Card Burner_Bandit			(RARE, 3, 2, 2, Abilities(AbilitiesEnum(Floaty | Spellproof), 2), "Burner Bandit", "assets/images/Fire.png");
Card Killer_Mosquito		(RARE, 4, 2, 4, Abilities(AbilitiesEnum(Floaty | Hidden)), "Killer Mosquito", "assets/images/Fire.png");
Card Dragon_Egg				(RARE, 3, 1, 1, Abilities(Floaty), "Dragon Egg", "assets/images/Fire.png");
Card Soot_Snake				(WANTED, 5, 3, 3, Abilities(NoAbilities), "Soot Snake", "assets/images/Fire.png");
Card Phoenix				(WANTED, 6, 3, 1, Abilities(NoAbilities), "Phoenix", "assets/images/Fire.png");
Card Sizzlord				(WANTED, 3, 2, 3, Abilities(NoAbilities), "Sizzlord", "assets/images/Fire.png");
Card Fire_Wall				(WANTED, 1, 0, 1, Abilities(NoAbilities), "Fire Wall", "assets/images/Fire.png");
Card Momma_Sizzle			(LEGENDARY, 4, 0, 4, Abilities(NoAbilities), "Momma Sizzle", "assets/images/Fire.png");
Card Guy_with_a_Flamethrower(LEGENDARY, 4, 0, 5, Abilities(NoAbilities), "Guy w/a Flamethrower", "assets/images/Fire.png");

//						Rarity, Cost, Name,		Image Path
Card Hot_Sauce	(COMMON, 1, "Hot Sauce", "assets/images/Fire.png");
Card Agility		(COMMON, 1, "Agility", "assets/images/Fire.png");
Card Fire_it_Up	(COMMON, 3, "Fire it Up", "assets/images/Fire.png");
Card Fiery_Fate	(RARE, 4, "Fiery Fate", "assets/images/Fire.png");
Card Hot_Potato	(RARE, 3, "Hot Potato", "assets/images/Fire.png");
Card Lava_Burst	(RARE, 5, "Lava Burst", "assets/images/Fire.png");

extern Deck Fire(std::vector<Card*> {	&Sizzle, &Blue_Sizzle, &White_Sizzle, &Burn_Bit, &Magma_Blob, &Baby_Phoenix, &Fire_Ant, &Deto_Nate,
										&Sumo_Sizzle, &Sizzling_Coffee, &Burner_Bandit, &Killer_Mosquito, &Dragon_Egg, &Soot_Snake, &Phoenix, 
										&Sizzlord, &Fire_Wall, &Momma_Sizzle, &Guy_with_a_Flamethrower, &Hot_Sauce, &Agility, &Fire_it_Up, &Fiery_Fate,
										&Hot_Potato, &Lava_Burst }, "assets/images/Fire.png");

//					Rarity, Cost, Attack, Hp, Abilities, Floaty, TeamUp, Spellproof, Hidden, Multistrike, Charge, Assassin, Splash, Armor, Name, Image Path
Card Elf			(COMMON, 1, 1, 1, Abilities(NoAbilities), "Elf", "assets/images/Nature.png");
Card Hammer_Elf		(COMMON, 2, 5, 3, Abilities(Charge), "Hammer Elf", "assets/images/Nature.png");
Card Nature_Hog		(COMMON, 1, 0, 4, Abilities(NoAbilities), "Nature Hog", "assets/images/Nature.png");
Card Corn_Dog		(COMMON, 1, 1, 1, Abilities(TeamUp), "Corn Dog", "assets/images/Nature.png");
Card Buck			(COMMON, 5, 4, 4, Abilities(NoAbilities), "Buck", "assets/images/Nature.png");
Card Pea_Launcher	(COMMON, 2, 2, 2, Abilities(TeamUp), "Pea Launcher", "assets/images/Nature.png");
Card Broctopus		(COMMON, 3, 4, 2, Abilities(TeamUp), "Broctopus", "assets/images/Nature.png");
Card Vine_Monkey	(COMMON, 3, 0, 3, Abilities(Floaty), "Vine Monkey", "assets/images/Nature.png");
Card Big_Pig		(RARE, 2, 0, 6, Abilities(TeamUp), "Big_Pig", "assets/images/Nature.png");
Card Road_Hog		(RARE, 3, 0, 6, Abilities(AbilitiesEnum(Floaty| TeamUp | Spellproof)), "Road Hog", "assets/images/Nature.png");
Card Beary			(RARE, 3, 3, 2, Abilities(NoAbilities), "Beary", "assets/images/Nature.png");
Card Stalia			(RARE, 3, 3, 2, Abilities(TeamUp), "Stalia", "assets/images/Nature.png");
Card Small_Sapling	(RARE, 3, 1, 3, Abilities(NoAbilities), "Small Sapling", "assets/images/Nature.png");
Card Healer_Elf		(WANTED, 3, 1, 3, Abilities(NoAbilities), "Healer Elf", "assets/images/Nature.png");
Card Elf_Commando	(WANTED, 7, 10, 6, Abilities(Charge), "Elf Commando", "assets/images/Nature.png");
Card Hogmaster		(WANTED, 6, 4, 3, Abilities(NoAbilities), "Hogmaster", "assets/images/Nature.png");
Card Golden_Goose	(WANTED, 1, 1, 3, Abilities(Floaty), "Golden Goose", "assets/images/Nature.png");
Card Nature_Guardian(LEGENDARY, 7, 2, 7, Abilities(Floaty, 0, 2, 1), "Nature Guardian", "assets/images/Nature.png");
Card Lemon_Aid		(LEGENDARY, 4, 1, 3, Abilities(NoAbilities, 0, 0, 1), "Lemon Aid", "assets/images/Nature.png");

//					Rarity, Cost, Name,			Image Path
Card Grass_Blades	(COMMON, 1, "Grass Blades", "assets/images/Nature.png");
Card Embiggen		(COMMON, 2, "Embiggen", "assets/images/Nature.png");
Card Heal			(COMMON, 2, "Heal", "assets/images/Nature.png");
Card Flower_Power	(RARE, 4, "Flower Power", "assets/images/Nature.png");
Card Root_Growth	(RARE, 3, "Root Growth", "assets/images/Nature.png");
Card Death_by_Tree	(RARE, 4, "Death by Tree", "assets/images/Nature.png");

extern Deck Nature(std::vector<Card*> { &Elf, &Hammer_Elf, &Nature_Hog, &Corn_Dog, &Buck, &Pea_Launcher, &Broctopus, &Vine_Monkey,
										&Big_Pig, &Road_Hog, &Beary, &Stalia, &Small_Sapling, &Healer_Elf, &Elf_Commando, &Hogmaster, 
										&Golden_Goose, &Nature_Guardian, &Lemon_Aid, &Grass_Blades, &Embiggen, &Heal, &Flower_Power, 
										&Root_Growth, &Death_by_Tree}, "assets/images/Nature.png");


//					Rarity, Cost, Attack, Hp, Abilities, Floaty, TeamUp, Spellproof, Hidden, Multistrike, Charge, Assassin, Splash, Armor, Name, Image Path
Card Tadpole		(COMMON, 1, 1, 1, Abilities(NoAbilities), "Tadpole", "assets/images/Water.png");
Card Toadpole		(COMMON, 2, 1, 1, Abilities(NoAbilities, 0, 1, 0), "Toadpole", "assets/images/Water.png");
Card Squirt			(COMMON, 1, 1, 1, Abilities(TeamUp), "Squirt", "assets/images/Water.png");
Card Chirp			(COMMON, 3, 3, 3, Abilities(NoAbilities), "Chirp", "assets/images/Water.png");
Card Flying_Fishies	(COMMON, 2, 2, 2, Abilities(Floaty), "Flying Fishies", "assets/images/Water.png");
Card Sunfish		(COMMON, 4, 4, 3, Abilities(Floaty), "Sunfish", "assets/images/Water.png");
Card Dartfish		(COMMON, 3, 2, 1, Abilities(Floaty), "Dartfish", "assets/images/Water.png");
Card Mr_Freezy		(COMMON, 3, 2, 2, Abilities(NoAbilities), "Mr Freezy", "assets/images/Water.png");
Card Water_Frog		(RARE, 3, 2, 2, Abilities(TeamUp), "Water Frog", "assets/images/Water.png");
Card Tadpole_Pack	(RARE, 2, 2, 2, Abilities(NoAbilities), "Tadpole Pack", "assets/images/Water.png");
Card Fighting_Fish	(RARE, 2, 1, 2, Abilities(NoAbilities), "Fighting Fish", "assets/images/Water.png");
Card T_I_D_E		(RARE, 4, 3, 4, Abilities(Charge, 0, 3, 0), "T I D E", "assets/images/Water.png");
Card Frozen_Penguin	(RARE, 3, 2, 2, Abilities(Hidden), "Frozen Penguin", "assets/images/Water.png");
Card Winter_Mosquito(WANTED, 3, 1, 3, Abilities(AbilitiesEnum(Floaty | Spellproof)), "Winter Mosquito", "assets/images/Water.png");
Card Copy_Cat_Fish	(WANTED, 4, 1, 1, Abilities(Hidden), "Copy Cat Fish", "assets/images/Water.png");
Card Mermaid		(WANTED, 6,	2, 3, Abilities(AbilitiesEnum(Hidden | Multistrike)), "Mermaid", "assets/images/Water.png");
Card Snowcone		(WANTED, 3, 1, 3, Abilities(Hidden), "Snowcone", "assets/images/Water.png");
Card Kraken			(LEGENDARY, 5, 1, 3, Abilities(NoAbilities), "Kraken", "assets/images/Water.png");
Card Winter_Phoenix	(LEGENDARY, 7, 4, 4, Abilities(AbilitiesEnum(Floaty | Hidden)), "Winter Phoenix", "assets/images/Water.png");

//						Rarity, Cost, Name,			Image Path
Card Waterfall			(COMMON, 1, "Waterfall", "assets/images/Water.png");
Card Rainbow			(COMMON, 3, "Rainbow", "assets/images/Water.png");
Card The_Cold_Shoulder	(COMMON, 1, "The Cold Shoulder", "assets/images/Water.png");
Card Storm				(COMMON, 6, "Storm", "assets/images/Water.png");
Card Evolution			(COMMON, 4, "Evolution", "assets/images/Water.png");
Card Frostbite			(COMMON, 2, "Frostbite", "assets/images/Water.png");

extern Deck Water(std::vector<Card*> {	&Tadpole, &Toadpole, &Squirt, &Chirp, &Flying_Fishies, &Sunfish, &Dartfish, 
										&Mr_Freezy, &Water_Frog, &Tadpole_Pack, &Fighting_Fish, &T_I_D_E, &Frozen_Penguin, 
										&Winter_Mosquito, &Copy_Cat_Fish, &Mermaid, &Snowcone, &Kraken, &Winter_Phoenix,
										&Waterfall, &Rainbow, &The_Cold_Shoulder, &Storm, &Evolution, &Frostbite}, "assets/images/Water.png");

//								Rarity, Cost, Attack, Hp, Abilities, Floaty, TeamUp, Spellproof, Hidden, Multistrike, Charge, Assassin, Splash, Armor, Name, Image Path
Card Zombie						(COMMON,1, 1, 1, Abilities(NoAbilities), "Zombie", "assets/images/Spooky.png");
Card Skeleton					(COMMON, 1, 1, 1, Abilities(TeamUp), "Skeleton", "assets/images/Spooky.png");
Card Armored_Skeleton			(COMMON, 2, 1, 2, Abilities(NoAbilities, 0, 0, 1), "Armored Skeleton", "assets/images/Spooky.png");
Card Slime						(COMMON, 2, 2, 1, Abilities(NoAbilities), "Slime", "assets/images/Spooky.png");
Card Sludge						(COMMON, 5, 5, 7, Abilities(NoAbilities), "Sludge", "assets/images/Spooky.png");
Card Wisp						(COMMON, 2, 2, 1, Abilities(Floaty), "Wisp", "assets/images/Spooky.png");
Card Ghost						(COMMON, 1, 4, 1, Abilities(AbilitiesEnum(Floaty | Charge)), "Ghost", "assets/images/Spooky.png");
Card Monster_Under_The_Bed		(COMMON, 5, 3, 2, Abilities(Multistrike), "Monster Under The Bed", "assets/images/Spooky.png");
Card Skele_Duo					(RARE, 2, 1, 1, Abilities(TeamUp), "Skele Duo", "assets/images/Spooky.png");
Card Tombstone					(RARE, 2, 0, 4, Abilities(TeamUp), "Tombstone", "assets/images/Spooky.png");
Card Buff_Bonez					(RARE, 3, 2, 2, Abilities(NoAbilities), "Buff Bonez", "assets/images/Spooky.png");
Card Banshee					(RARE, 5, 5, 3, Abilities(AbilitiesEnum(Floaty | Hidden)), "Banshee", "assets/images/Spooky.png");
Card Magical_Floating_Boulder	(RARE, 4, 2, 2, Abilities(NoAbilities), "Magical Floating Boulder", "assets/images/Spooky.png");
Card Vampire_Bat				(RARE, 4, 3, 2, Abilities(Floaty), "Vampire Bat", "assets/images/Spooky.png");
Card Living_Deadwood			(WANTED, 7, 6, 6, Abilities(NoAbilities), "Living Deadwood", "assets/images/Spooky.png");
Card Commander_Crossbones		(WANTED, 2, 1, 2, Abilities(NoAbilities), "Commander Crossbones", "assets/images/Spooky.png");
Card Fortune_Teller				(WANTED, 3, 1, 2, Abilities(AbilitiesEnum(Floaty | Hidden)), "Fortune Teller", "assets/images/Spooky.png");
Card The_Anti_Energy			(LEGENDARY, 5, 4, 3, Abilities(Floaty), "The Anti Energy", "assets/images/Spooky.png");
Card Cursed_Playdoll			(LEGENDARY, 5, 3, 3, Abilities(Floaty), "Cursed Playdoll", "assets/images/Spooky.png");

//					Rarity, Cost, Name,			Image Path
Card Spider_Bite	(COMMON, 1, "Spider Bite", "assets/images/Spooky.png");
Card Howl			(COMMON, 3, "Howl", "assets/images/Spooky.png");
Card Darkness		(COMMON, 3, "Darkness", "assets/images/Spooky.png");
Card Sacrifice		(RARE, 2, "Sacrifice", "assets/images/Spooky.png");
Card Graveyard		(WANTED, 4, "Graveyard", "assets/images/Spooky.png");
Card Disco_is_Undead(WANTED, 1, "Disco is Undead", "assets/images/Spooky.png");

extern Deck Spooky(std::vector<Card*> {	&Zombie, &Skeleton, &Armored_Skeleton, &Slime, &Sludge, &Wisp, &Ghost, 
										&Monster_Under_The_Bed, &Skele_Duo, &Tombstone, &Buff_Bonez, &Banshee, 
										&Magical_Floating_Boulder, &Vampire_Bat, &Living_Deadwood, &Commander_Crossbones, 
										&Fortune_Teller, &The_Anti_Energy, &Cursed_Playdoll, &Spider_Bite, &Howl, &Darkness, 
										&Sacrifice, &Graveyard, &Disco_is_Undead }, "assets/images/Spooky.png");


//						Rarity, Cost, Attack, Hp, Abilities, Floaty, TeamUp, Spellproof, Hidden, Multistrike, Charge, Assassin, Splash, Armor, Name, Image Path
Card Mini_Warrior		(COMMON, 1, 1, 1, Abilities(NoAbilities), "Mini Warrior", "assets/images/Royal.png");
Card Mini_Archer		(COMMON, 3, 2, 3, Abilities(Multistrike), "Mini Archer", "assets/images/Royal.png");
Card Pawn				(COMMON, 1, 1, 1, Abilities(TeamUp), "Pawn", "assets/images/Royal.png");
Card Knight				(COMMON, 5, 5, 4, Abilities(NoAbilities, 0, 0, 1), "Knight", "assets/images/Royal.png");
Card One_Hit_Wonder		(COMMON, 3, 4, 1, Abilities(AbilitiesEnum(Floaty | TeamUp)), "One Hit Wonder", "assets/images/Royal.png");
Card Barrel_Cannon		(COMMON, 4, 2, 3, Abilities(NoAbilities, 0, 2, 0), "Barrel Cannon", "assets/images/Royal.png");
Card Energy_Tube		(COMMON, 1, 0, 1, Abilities(NoAbilities), "Energy Tube", "assets/images/Royal.png");
Card Mini_Banneret		(RARE, 3, 3, 1, Abilities(Hidden), "Mini Banneret", "assets/images/Royal.png");
Card Guard				(RARE, 3, 2, 2, Abilities(TeamUp, 0, 0, 1), "Guard", "assets/images/Royal.png");
Card Poison_Archer		(RARE, 3, 1, 3, Abilities(Charge), "Poison Archer", "assets/images/Royal.png");
Card Golden_Pawn		(RARE, 3, 1, 3, Abilities(AbilitiesEnum(TeamUp | Hidden)), "Golden Pawn", "assets/images/Royal.png");
Card Royal_Snail		(RARE, 3, 2, 2, Abilities(NoAbilities), "Royal Snail", "assets/images/Royal.png");
Card Energy_Tube_Point	(RARE, 2, 0, 2, Abilities(NoAbilities, 3, 0, 1), "Energy Tube Point", "assets/images/Royal.png");
Card Dark_Knight		(WANTED, 7, 5, 5, Abilities(Hidden), "Dark Knight", "assets/images/Royal.png");
Card Backstabber		(WANTED, 2, 4, 1, Abilities(NoAbilities), "Backstabber", "assets/images/Royal.png");
Card Fifty				(WANTED, 3, 0, 2, Abilities(NoAbilities), "Fifty", "assets/images/Royal.png");
Card Mortar				(WANTED, 5, 0, 5, Abilities(NoAbilities), "Mortar", "assets/images/Royal.png");
Card Energized_Pawn		(LEGENDARY, 1, 1, 1, Abilities(NoAbilities), "Energized Pawn", "assets/images/Royal.png");

//						Rarity, Cost, Name,			Image Path
Card Stab				(COMMON, 1, "Stab", "assets/images/Royal.png");
Card Arrows				(COMMON, 2, "Arrows", "assets/images/Royal.png");
Card Slash				(COMMON, 2, "Slash", "assets/images/Royal.png");
Card Draw				(COMMON, 2, "Draw", "assets/images/Royal.png");
Card Snipe				(RARE, 5, "Snipe", "assets/images/Royal.png");
Card Supply_Drop		(RARE, 2, "Supply Drop", "assets/images/Royal.png");
Card Dirty_Tricks		(LEGENDARY, 1, "Dirty Tricks", "assets/images/Royal.png");

extern Deck Royal(std::vector<Card*> {	&Mini_Warrior, &Mini_Archer, &Pawn, &Knight, &One_Hit_Wonder, &Barrel_Cannon, &Energy_Tube, 
										&Mini_Banneret, &Guard, &Poison_Archer, &Golden_Pawn, &Royal_Snail, &Energy_Tube_Point, 
										&Dark_Knight, &Backstabber, &Fifty, &Mortar, &Energized_Pawn, &Stab, &Arrows, &Slash, 
										&Draw, &Snipe, &Supply_Drop, &Dirty_Tricks }, "assets/images/Royal.png");

void setupCards()
{
}
