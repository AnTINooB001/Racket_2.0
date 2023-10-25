#pragma once

#include "Object.h"

class Planet 
{
public:
	Planet(int,int,double, double, sf::Texture*);
	void move(float);
	void rotate(int);
	void draw(sf::RenderWindow&);
	void reborn();
private:
	sf::CircleShape planet;
	int min_size;
	int max_size;
	double scale_x;
	double scale_y;
};

