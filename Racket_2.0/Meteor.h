#pragma once
#include "Star.h"
#include "map_settings.h"
class Meteor : public Star
{
public:
	Meteor();
	void reborn() override;
	void draw(sf::RenderWindow&) override;
	void move(float) override;
	bool collision(sf::FloatRect);
	void rotate(int);
	void set_texture(sf::Texture*);
	void decrement_health();
	int get_health() const;
	sf::FloatRect get_meteor_bounds();
private:
	sf::CircleShape meteor;
	int health;
	int rad;
};

