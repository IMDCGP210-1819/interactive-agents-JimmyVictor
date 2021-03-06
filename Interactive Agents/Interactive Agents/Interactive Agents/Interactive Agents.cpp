#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Agent.h"
#include "Map.h"
using namespace std;

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;




sf::Sprite* benchSprite;
sf::Sprite* bikeSprite;
sf::Sprite* treadMillSprite; 
Agent* agent;

Map* worldMap;
void DrawCalls(sf::RenderWindow* window)
{
	window->draw(agent->m_sprite);
	window->draw(*benchSprite);
	window->draw(*bikeSprite);
	window->draw(*treadMillSprite);
}

int main()
{
	sf::Texture guyTexture;
	sf::Texture benchTexture;
	sf::Texture bikeTexture;
	sf::Texture treadMillTexture;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Interactive Agents!");
	worldMap = new Map(WINDOW_WIDTH / MAP_NODE_DIMENSION_X, WINDOW_HEIGHT / MAP_NODE_DIMENSION_Y);

	guyTexture.loadFromFile("../Assets/guy.png");
	benchTexture.loadFromFile("../Assets/benchpress.png");
	bikeTexture.loadFromFile("../Assets/bike.png");
	treadMillTexture.loadFromFile("../Assets/run.png");

	benchSprite = new sf::Sprite(benchTexture);
	bikeSprite = new sf::Sprite(bikeTexture);
	treadMillSprite = new sf::Sprite(treadMillTexture);
	agent = new Agent(sf::Sprite(guyTexture), worldMap);

	/*benchSprite.setPosition(sf::Vector2f(500.0f, 350.0f));
	bikeSprite.setPosition(sf::Vector2f(850.0f, 50.0f));
	treadMillSprite.setPosition(sf::Vector2f(900.0f, 400.0f));*/

	benchSprite->setPosition(sf::Vector2f(worldMap->nodes[7 * worldMap->width + 10].x, worldMap->nodes[7 * worldMap->width + 6].y));
	bikeSprite->setPosition(sf::Vector2f(worldMap->nodes[12 * worldMap->width + 2].x, worldMap->nodes[12 * worldMap->width + 2].y));
	treadMillSprite->setPosition(sf::Vector2f(worldMap->nodes[17 * worldMap->width + 15].x, worldMap->nodes[17 * worldMap->width + 15].y));

	worldMap->nodes[7, 10].isObstacle = true;
	worldMap->nodes[12, 2].isObstacle = true;
	worldMap->nodes[17, 15].isObstacle = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(255, 111, 97, 100));
		agent->m_sprite.setPosition(sf::Vector2f(5, 5));
		DrawCalls(&window);
		window.display();
	}

	return 0;
}

void SpawnAgents() 
{

}
