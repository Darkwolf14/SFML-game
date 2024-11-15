#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine.h"

int main() 
{
	gEng::Engine engine(sf::Vector2i(800, 600), sf::Vector2i(100, 10));
	
	engine.startMainLoop();

	return 0;

}
