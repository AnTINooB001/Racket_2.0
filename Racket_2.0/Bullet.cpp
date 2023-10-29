#include "Bullet.h"

Bullet::Bullet(int cx, int cy, int cr, int scale) : x{ cx }, y{ cy }, r{ cr }
{
	bullet.setRadius(r);
	bullet.setPosition(sf::Vector2f(x, y));
	bullet.scale(sf::Vector2f(1, scale));
}

Bullet::Bullet()
{
	r = x = y = 0;
	bullet.setRadius(r);
}

Bullet::Bullet(Bullet& rval): x{rval.x}, y{rval.y}, r{rval.r}
{
	bullet.setRadius(r);
	bullet.setPosition(sf::Vector2f(x, y));
	bullet.setOrigin(sf::Vector2f(x / 2, y / 2));
}

void Bullet::set_pos(int x,int y)
{
	bullet.setPosition(sf::Vector2f(x, y));
}

void Bullet::draw(sf::RenderWindow& wnd)
{
	wnd.draw(bullet);
}

void Bullet::move(sf::Vector2f& pos) 
{
	bullet.move(pos);
}

void Bullet::set_color(sf::Color c)
{
	bullet.setFillColor(c);
}

sf::FloatRect Bullet::get_bullet_bounds() const
{
	return bullet.getGlobalBounds();
}

int Bullet::get_x() const
{
	return bullet.getPosition().x;
}

int Bullet::get_y() const
{
	return bullet.getPosition().y;
}

int Bullet::get_r() const
{
	return bullet.getRadius();
} 

