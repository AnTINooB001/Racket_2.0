#pragma once

#include "Object.h"

class Racket : public Object
{
public:
	Racket();
	void Create() override;
	void draw(sf::RenderWindow& wnd) override;
	void move(float) override;
	int get_x() const;
	int get_y() const;
private:
	sf::ConvexShape racket;
};

