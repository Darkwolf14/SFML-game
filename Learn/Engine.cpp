#include "Engine.h"
#include <iostream>

namespace gEng
{

	Engine::Engine(sf::Vector2i windowSize, sf::Vector2i terrainSize)
	{

		player = Player(sf::Vector2f(20, 20), sf::Vector2f(100, 150), sf::Color(160, 50, 104));


		window = new sf::RenderWindow(sf::VideoMode(windowSize.x, windowSize.y), "Window");
		window->setFramerateLimit(60);

		camera.setCenter(player.getPosition().x + (player.getSize().x)/2, player.getPosition().y + (player.getSize().y) / 2);
		camera.setSize(window->getSize().x, window->getSize().y);

		this->terrainSize = terrainSize;
		for (int height = 0; height < this->terrainSize.y; height++)
		{
			for (int width = 0; width < this->terrainSize.x; width++)
			{
				objVector.push_back(Object(sf::Vector2f(width * tileSize + 0, height * tileSize + 500), sf::Vector2f(tileSize, tileSize), sf::Color(128, 201, 0)));
			}
		}

	}

	Engine::~Engine() {
		delete window;
	}

	void Engine::startMainLoop()
	{
		float deltaTime = 0;
		sf::Clock CurrentTime;

		while (window->isOpen())
		{

			deltaTime = CurrentTime.restart().asSeconds();

			Engine::eventsControl(deltaTime);

			window->clear();
			drawAll();
			window->display();

			window->setView(camera);

		}
	}

	void Engine::eventsControl(float deltaTime) {

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed()) {
				window->close();
			}

			if (event.type == sf::Event::Resized) {
				camera.setSize(window->getSize().x, window->getSize().y);
			}
		}

		float dtSpeed = player.getSpeed() * deltaTime;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.move(sf::Vector2f(0, -dtSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.move(sf::Vector2f(0, dtSpeed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.move(sf::Vector2f(-dtSpeed, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.move(sf::Vector2f(dtSpeed, 0));
		}

		camera.setCenter(player.getPosition().x + (player.getSize().x) / 2, player.getPosition().y + (player.getSize().y) / 2);
	}

	void Engine::drawTerrain()
	{
		for (int height = 0; height < terrainSize.y; height++)
		{
			for (int width = 0; width < terrainSize.x; width++)
			{
				objVector[height * terrainSize.x + width].draw(window);
			}
		}

	}

	void Engine::drawAll() {
		drawTerrain();
		player.draw(window);
	}

}