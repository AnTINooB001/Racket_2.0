#pragma once

#include <SFML/Graphics.hpp>


class Star
{
public:
	Star();
	virtual void reborn();
	virtual void draw(sf::RenderWindow& wnd) ;
	virtual void move(float);
	virtual int get_x() const;
	virtual int get_y() const;
private:
	sf::ConvexShape star;
};

