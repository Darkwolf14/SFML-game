#ifndef ENGINE_H
#define ENGINE_H

#include "Player.h"
#include <vector>



namespace gEng 
{


	class Engine
	{
	private:
		sf::RenderWindow* window;
		sf::View camera; 

		std::vector<Object> objVector;
		Player player;

		sf::Vector2i terrainSize;
		int tileSize=20;


	public:
		Engine(sf::Vector2i windowSize, sf::Vector2i terrainSize);
		~Engine();

		void startMainLoop();

		void eventsControl(float deltaTime);

		void drawTerrain();
		void drawAll();
	};

}
#endif
