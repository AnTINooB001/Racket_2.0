#pragma once

#include "Bullet.h"
#include "map_settings.h"

class Racket 
{
public:
	Racket();
	void Create() ;
	void draw(sf::RenderWindow& wnd) ;
	void move(sf::Vector2f&);
	int get_x() const;
	int get_y() const;
	void set_pos(int x, int y);
	void right_ammo_move(float);
	void left_ammo_move(float);
	void set_fired_left_ammo(bool);
	void set_fired_right_ammo(bool);
	bool get_fired_left_ammo() const;
	bool get_fired_right_ammo() const;
	void reset_right_ammo();
	void reset_left_ammo();
	sf::FloatRect get_left_ammo_bounds() const;
	sf::FloatRect get_right_ammo_bounds() const;
	sf::FloatRect get_bounds() const;
private:
	sf::ConvexShape racket;
	int width,height,px;
	sf::RectangleShape left_gun;
	sf::RectangleShape right_gun;
	Bullet l_ammo;
	Bullet r_ammo;
	bool fired_left_ammo;
	bool fired_right_ammo;
};

