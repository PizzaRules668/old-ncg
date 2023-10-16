#include <iostream>
#include <random>
#include <chrono>

#include <SFML/Graphics.hpp>

#include "Abilities.hpp"
#include "Energy.hpp"
#include "Cards.hpp"
#include "Player.h"
#include "Game.h"
#include "Card.h"
#include "Hand.h"
#include "Lane.h"
#include "Deck.h"

float getPos(int id, int numOfCards, float windowWidth, float imageWidth) // evently spread out objects
{
	return (windowWidth / numOfCards * id) - imageWidth;
	// (windows width / number of cards * what card your getting pos of) - width of image
	// ex (1920 / 7 * 2) - 298
}

int main()
{
	setupCards(); // Init all cards

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Window", sf::Style::Default); // Windows for rendering to
	
	Game game; // Init game logic

	Lane heights("assets/images/TestLane.png"); // Init heights lane
	Lane ground1("assets/images/TestLane.png"); // Init ground lane 1
	Lane ground2("assets/images/TestLane.png"); // Init ground lane 2
	Lane ground3("assets/images/TestLane.png"); // Init ground lane 3
	Lane floaty(true, "assets/images/TestLane.png"); // Init floaty lane

	std::vector<Lane*> lanes = { &heights, &ground1, &ground2, &ground3, &floaty }; // Init List of lanes
	std::vector<Deck*> decks = { &Fire, &Nature, &Water, &Spooky, &Royal}; // Init List of the decks

	std::shuffle(decks.begin(), decks.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count() * 2)); // Shuffle deck, with random seed being time unix

	game.getPlayerOne()->setDeck1(decks.at(0), getPos(1, 7, window.getSize().x, heights.getTexture().getSize().x)-75.0f, 580.0f); // Give deck one in shuffled list to player 1
	game.getPlayerOne()->setDeck2(decks.at(2), getPos(7, 7, window.getSize().x, heights.getTexture().getSize().x)-75.0f, 580.0f); // Give deck three in shuffled list to player 1

	game.getPlayerTwo()->setDeck1(decks.at(1), getPos(1, 7, window.getSize().x, heights.getTexture().getSize().x)-75.0f, 0.0f); // Give deck two in shuffled list to player 2
	game.getPlayerTwo()->setDeck2(decks.at(3), getPos(7, 7, window.getSize().x, heights.getTexture().getSize().x)-75.0f, 0.0f); // Give deck four in shuffled list to player 2

	game.setLanes(lanes); // Give the list of lanes to the game
	game.setDecks(decks); // Give the list of decks to the game

	heights.setPosition(getPos(2, 7, window.getSize().x, heights.getTexture().getSize().x)-75.0f, 150.0f); // Set heights position
	ground1.setPosition(getPos(3, 7, window.getSize().x, ground1.getTexture().getSize().x)-75.0f, 150.0f); // Set ground 1 position
	ground2.setPosition(getPos(4, 7, window.getSize().x, ground2.getTexture().getSize().x)-75.0f, 150.0f); // Set ground 2 position
	ground3.setPosition(getPos(5, 7, window.getSize().x, ground3.getTexture().getSize().x)-75.0f, 150.0f); // Set ground 3 position
	floaty.setPosition(getPos(6, 7, window.getSize().x, floaty.getTexture().getSize().x)-75.0f, 150.0f); // Set floaty position

	while (window.isOpen()) // While window is open
	{
		sf::Event event; // Create event object
		while (window.pollEvent(event)) // While there are events
		{
			if (event.type == sf::Event::Closed)
				window.close(); // Close windows

			// Update Variable
			game.update(event, window.getSize().x); // Tell game to update
		}

		// Clear Screen
		window.clear(); // Clear the screen

		// Draw to window in order
		window.draw(game); // Tell game to draw all objects

		// Update Display
		window.display(); // Display the game object
	}

	return 0;
}
