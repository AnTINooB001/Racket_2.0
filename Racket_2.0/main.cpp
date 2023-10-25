#include "GameLib.h"
#include <vector>

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Racket 2");
    sf::RectangleShape back_g(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t;
    back_ground_t.loadFromFile("textures\\map.png");
    back_g.setTexture(&back_ground_t);

    sf::RectangleShape back_g2(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t2;
    back_ground_t2.loadFromFile("textures\\map2.png");
    back_g2.setTexture(&back_ground_t2);
    back_g2.setPosition(sf::Vector2f(0, -600));

    Racket racket;

    std::vector<Star> stars(100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        back_g2.move(sf::Vector2f(0, 0.065));
        back_g.move(sf::Vector2f(0, 0.065));
        if (back_g.getPosition().y > 600)
            back_g.setPosition(sf::Vector2f(0, -600));
        if (back_g2.getPosition().y > 600)
            back_g2.setPosition(sf::Vector2f(0, -600));

        for (int i = 0; i < stars.size(); i++)
            stars[i].move(0.065);

        window.clear();
        window.draw(back_g);
        window.draw(back_g2);
        for (int i = 0; i < stars.size(); i++)
            stars[i].draw(window);
        racket.draw(window);
        window.display();
    }

    return 0;
}