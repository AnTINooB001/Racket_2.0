#include "Planet.h"

Planet::Planet(int min_sz, int max_sz, double sc_x, double sc_y, sf::Texture* texture) : min_size{ min_sz }, max_size{ max_sz }, scale_x{ sc_x }, scale_y{ sc_y }
{
	reborn();
	planet.setTexture(texture);
}

void Planet::move(float time)
{
	int y = planet.getPosition().y;
	planet.move(sf::Vector2f(0, 0.65 * time));
	if (planet.getPosition().y > 600 + planet.getRadius()*2)
		reborn();
}

void Planet::rotate(int alpha)
{
	planet.rotate(alpha);
}

void Planet::draw(sf::RenderWindow& wnd)
{
	wnd.draw(planet);
}

void Planet::reborn()
{
	int x = (rand() % 1198) + 1;
	int y = ((rand() % 1200)* (-1)) - 600;
	int r = (rand() % (max_size-min_size)) + min_size;
	planet.setRadius(r);
	planet.setOrigin(sf::Vector2f(r, r));
	planet.setPosition(sf::Vector2f(x, y));
	planet.setScale(sf::Vector2f(scale_x, scale_y));
}
