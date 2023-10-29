#include "Racket.h"

Racket::Racket()
{
	Create();
}

void Racket::Create()
{														// height 80
	int x = map_width/2;								// width 160
	int y = map_height/2;
	px = 10;
	height = 9;	// in px
	width = 10; // in px
	
	racket.setPosition(sf::Vector2f(x, y));
	//racket.setOrigin(sf::Vector2f(x, y));
	racket.setPointCount(13);
	racket.setPoint(0, sf::Vector2f(0, 0-px*height));
	racket.setPoint(1, sf::Vector2f(0 + px, 0 - px *4));
	racket.setPoint(2, sf::Vector2f(0 + px*2, 0- px * 4));
	racket.setPoint(3, sf::Vector2f(0 + px*width/2, 0 - px * 4));
	racket.setPoint(4, sf::Vector2f(0 + px * width / 2, 0 - px));
	racket.setPoint(5, sf::Vector2f(0 + px, 0 - px));
	racket.setPoint(6, sf::Vector2f(0 + px, 0));
	//---------------------------------------------------
	racket.setPoint(7, sf::Vector2f(0 - px, 0));
	racket.setPoint(8, sf::Vector2f(0 - px, 0-px));
	racket.setPoint(9, sf::Vector2f(0 - px * width / 2, 0 - px));
	racket.setPoint(10, sf::Vector2f(0 - px * width / 2, 0 - px * 4));
	racket.setPoint(11, sf::Vector2f(0 - px * 2, 0 - px * 4));
	racket.setPoint(12, sf::Vector2f(0 - px, 0 - px * 4));

	sf::RectangleShape l_gun(sf::Vector2f(px / 2, px * 6));
	l_gun.setPosition(x - px * width / 2, y - px * 7 + px/2);
	l_gun.setOrigin(sf::Vector2f(px / 2 / 2, 3.5));
	left_gun = l_gun;

	sf::RectangleShape r_gun(sf::Vector2f(px / 2, px * 6));
	r_gun.setPosition(x + px * width / 2, y - px * 7 + px/2);
	r_gun.setOrigin(sf::Vector2f(px / 2 / 2, 3.5));
	right_gun = r_gun;

	fired_left_ammo = false;
	fired_right_ammo = false;

	l_ammo = Bullet(left_gun.getPosition().x - 2, left_gun.getPosition().y,2,6);
	l_ammo.set_color(sf::Color::Green);

	r_ammo = Bullet(right_gun.getPosition().x - 2, right_gun.getPosition().y, 2, 6);
	r_ammo.set_color(sf::Color::Green);
}


void Racket::draw(sf::RenderWindow& wnd)
{
	l_ammo.draw(wnd);
	r_ammo.draw(wnd);
	wnd.draw(racket);
	wnd.draw(left_gun);
	wnd.draw(right_gun);
}

void Racket::move(sf::Vector2f& pos)
{
	racket.move(pos);
	left_gun.move(pos);
	right_gun.move(pos);
	if (!fired_left_ammo)
		reset_left_ammo();
	if (!fired_right_ammo)
		reset_right_ammo();
}
int Racket::get_x() const
{
	return racket.getPosition().x;
}

int Racket::get_y() const
{
	return racket.getPosition().y;
}

void Racket::set_pos(int x, int y)
{
	racket.setPosition(x, y);
	left_gun.setPosition(x + px*width/2, y-65);
	right_gun.setPosition(x - px * width / 2, y-65);
	if(!fired_left_ammo)
		reset_left_ammo();
	if (!fired_right_ammo)
		reset_right_ammo();
}

void Racket::left_ammo_move(float time)
{
	sf::Vector2f pos(0, time * -0.65);
	l_ammo.move(pos);
}
void Racket::right_ammo_move(float time)
{
	sf::Vector2f pos(0, time * -0.65);
	r_ammo.move(pos);
}

void Racket::set_fired_left_ammo(bool s)
{
	fired_left_ammo = s;
}
void Racket::set_fired_right_ammo(bool s)
{
	fired_right_ammo = s;
}

bool Racket::get_fired_left_ammo() const
{
	return fired_left_ammo;
}
bool Racket::get_fired_right_ammo() const
{
	return fired_right_ammo;
}

void Racket::reset_right_ammo()
{
	r_ammo.set_pos(right_gun.getPosition().x - r_ammo.get_r(), right_gun.getPosition().y);
}

void Racket::reset_left_ammo()
{
	l_ammo.set_pos(left_gun.getPosition().x - l_ammo.get_r(), left_gun.getPosition().y);
}

sf::FloatRect Racket::get_left_ammo_bounds() const
{
	return l_ammo.get_bullet_bounds();
}

sf::FloatRect Racket::get_right_ammo_bounds() const
{
	return r_ammo.get_bullet_bounds();
}

sf::FloatRect Racket::get_bounds() const
{
	return racket.getGlobalBounds();
}
