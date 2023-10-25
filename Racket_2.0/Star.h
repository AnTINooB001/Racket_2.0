#pragma once

#include "Object.h"

class Star : public Object
{
public:
	Star();
	void Create() override;
	void reborn();
	void draw(sf::RenderWindow& wnd) override;
	void move(float) override;
	int get_x() const;
	int get_y() const;
private:
	sf::ConvexShape star;
};

