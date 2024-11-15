#include "Object.h"

namespace gEng 
{

	Object::Object(sf::Vector2f position, sf::Vector2f size, sf::Color color) 
	{
		shape.setSize(size);
		shape.setPosition(position);
		shape.setFillColor(color);
		shape.setOutlineThickness(2);
		shape.setOutlineColor(sf::Color(255, 255, 255));
	}

	void Object::move(sf::Vector2f pos) 
	{
		shape.move(pos);
	}
	void Object::draw(sf::RenderWindow* window) 
	{
		window->draw(shape);
	}
}