#include "Racket.h"

Racket::Racket()
{
	Create();
}

void Racket::Create()
{												// height 80
	int x = 600;								// width 160
	int y = 300;
	int height = 80;
	int width = 160;
	int px = 10;
	//racket.setPosition(x, y);
	racket.setPointCount(13);
	racket.setPoint(0, sf::Vector2f(x, y - height));
	racket.setPoint(1, sf::Vector2f(x + px/2, y - height + px));
	racket.setPoint(2, sf::Vector2f(x + px/2, y - px * 4));
	racket.setPoint(3, sf::Vector2f(x + px * 2, y - px * 4));
	racket.setPoint(4, sf::Vector2f(x + px * 2, y - px * 2));
	racket.setPoint(5, sf::Vector2f(x + px * 8, y - px * 2));
	racket.setPoint(6, sf::Vector2f(x + px * 8, y));
	racket.setPoint(7, sf::Vector2f(x - px * 8, y));
	racket.setPoint(8, sf::Vector2f(x - px * 8, y - px*2));
	racket.setPoint(9, sf::Vector2f(x - px * 2, y - px * 2));
	racket.setPoint(10, sf::Vector2f(x - px * 2, y - px * 4));
	racket.setPoint(11, sf::Vector2f(x - px/2, y - px * 4));
	racket.setPoint(12, sf::Vector2f(x - px / 2, y - px * 7));

	//racket.setFillColor(sf::Color::Yellow);
}

void Racket::draw(sf::RenderWindow& wnd)
{
	wnd.draw(racket);
}

void Racket::move(float)
{
}
