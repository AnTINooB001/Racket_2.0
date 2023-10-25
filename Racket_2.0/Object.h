#pragma once
#include <SFML/Graphics.hpp>

class Object
{
protected:
	virtual void  Create() = 0;
	virtual void draw(sf::RenderWindow& wnd) = 0;
	virtual void move(float) = 0;
	virtual ~Object() {};
};

