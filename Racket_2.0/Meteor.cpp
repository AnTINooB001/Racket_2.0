#include "Meteor.h"

Meteor::Meteor()
{
	health = 3;
	reborn();
}

void Meteor::reborn()
{
	int x = (rand() % map_width)-300;
	int y = (rand() % map_height) - map_height;
	rad = (rand() % 10) + 30;
	int s = ((rand() % 2)*1.0+1)*1.0 / 1.5;
	meteor.setPosition(sf::Vector2f(x, y));
	meteor.setRadius(rad);
	//meteor.setScale(sf::Vector2f(1, s));
}

void Meteor::draw(sf::RenderWindow& wnd)
{
	wnd.draw(meteor);
}

void Meteor::move(float time)
{
	int x = (rand() % 2);
	meteor.move(sf::Vector2f(x, time * 0.65));
	if (meteor.getPosition().y > 600+rad*2)
		reborn();
}

bool Meteor::collision(sf::FloatRect obj)
{
	if (meteor.getGlobalBounds().intersects(obj))
		return true;
	return false;
}

void Meteor::rotate(int alpha)
{
	meteor.rotate(alpha);
}

void Meteor::set_texture(sf::Texture* texture)
{
	meteor.setTexture(texture);
}

void Meteor::decrement_health()
{
	--health;
}

int Meteor::get_health() const
{
	return health;
}

sf::FloatRect Meteor::get_meteor_bounds()
{
	return meteor.getGlobalBounds();
}

