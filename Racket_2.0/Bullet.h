#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet(int cx, int cy, int cr,int scale) ;
	Bullet();
	Bullet(Bullet& rval);
	void set_pos(int,int);
	void draw(sf::RenderWindow& wnd);
	void move(sf::Vector2f&);
	void set_color(sf::Color);
	sf::FloatRect get_bullet_bounds() const;
	int get_x() const;
	int get_y() const;
	int get_r() const;
private:
	sf::CircleShape bullet;
	int x, y, r;
};

