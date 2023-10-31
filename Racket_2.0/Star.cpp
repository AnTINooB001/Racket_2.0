#include "Star.h"

Star::Star()
{
	int x = (rand() % 1198);
	int y = (rand() % 598) + 1;
	star.setPosition(sf::Vector2f(x, y));
	//-----------------------------------------------draw model-------------------------------
	star.setPointCount(9);
	star.setPoint(0, sf::Vector2f(x, y - 4));
	star.setPoint(1, sf::Vector2f(x + 1, y - 1));
	star.setPoint(2, sf::Vector2f(x + 4, y));
	star.setPoint(3, sf::Vector2f(x + 1, y + 1));
	star.setPoint(4, sf::Vector2f(x, y + 4));
	star.setPoint(5, sf::Vector2f(x - 1, y + 1));
	star.setPoint(6, sf::Vector2f(x - 4, y));
	star.setPoint(7, sf::Vector2f(x + 1, y - 1));
	star.setPoint(8, sf::Vector2f(x, y - 4));
	//----------------------------------------------------------------------------------------
	star.setFillColor(sf::Color::White);
}

void Star::reborn()
{
	int x = (rand() % 1198) + 1;
	star.setPosition(sf::Vector2f(x, -600));
}

void Star::draw(sf::RenderWindow& wnd)
{
	wnd.draw(star);
}

void Star::move(float time)
{
	int y = star.getPosition().y;
	star.move(sf::Vector2f(0,0.65*time));
	if (star.getPosition().y > 600)
		reborn();

}

int Star::get_x() const
{
	return star.getPosition().x;
}

int Star::get_y() const
{
	return star.getPosition().y;
}
