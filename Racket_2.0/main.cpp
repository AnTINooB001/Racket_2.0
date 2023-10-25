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

    sf::RectangleShape beetwen2and3(sf::Vector2f(1200, 600));
    sf::Texture beetwen2and3_t;
    beetwen2and3_t.loadFromFile("textures\\beetwen2and3.png");
    beetwen2and3.setTexture(&beetwen2and3_t);
    beetwen2and3.setPosition(sf::Vector2f(0, -1200));

    sf::RectangleShape back_g3(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t3;
    back_ground_t3.loadFromFile("textures\\map3.png");
    back_g3.setTexture(&back_ground_t3);
    back_g3.setPosition(sf::Vector2f(0, -1800));

    sf::RectangleShape back_g4(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t4;
    back_ground_t4.loadFromFile("textures\\map4.png");
    back_g4.setTexture(&back_ground_t4);
    back_g4.setPosition(sf::Vector2f(0, -2400));


    sf::RectangleShape back_g5(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t5;
    back_ground_t5.loadFromFile("textures\\map5.png");
    back_g5.setTexture(&back_ground_t5);
    back_g5.setPosition(sf::Vector2f(0, -3000));

    Racket racket;

    std::vector<Star> stars(100);
    sf::Clock timer;
    float map_speed, star_speed,time;
    while (window.isOpen())
    {
        time = timer.getElapsedTime().asMicroseconds();
        map_speed = time / 5000;
        star_speed = time / 6000;
        time /= 6000;
        
        timer.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        beetwen2and3.move(sf::Vector2f(0, map_speed));
        back_g5.move(sf::Vector2f(0, map_speed));
        back_g4.move(sf::Vector2f(0, map_speed));
        back_g3.move(sf::Vector2f(0,map_speed));
        back_g2.move(sf::Vector2f(0, map_speed));
        back_g.move(sf::Vector2f(0, map_speed));
        if (back_g.getPosition().y > 600)
            back_g.setPosition(sf::Vector2f(0, -2400));
        if (back_g2.getPosition().y > 600)
            back_g2.setPosition(sf::Vector2f(0, -2400));
        if (back_g3.getPosition().y > 600)
            back_g3.setPosition(sf::Vector2f(0, -2400));
        if (back_g4.getPosition().y > 600)
            back_g4.setPosition(sf::Vector2f(0, -2400));
        if (back_g5.getPosition().y > 600)
            back_g5.setPosition(sf::Vector2f(0, -2400));
        if (beetwen2and3.getPosition().y > 600)
            beetwen2and3.setPosition(sf::Vector2f(0, -2400));

        for (int i = 0; i < stars.size(); i++)
            stars[i].move(star_speed);

        window.clear();
        window.draw(back_g);
        window.draw(back_g2);
        window.draw(back_g3);
        window.draw(back_g4);
        window.draw(back_g5);
        window.draw(beetwen2and3);
        for (int i = 0; i < stars.size(); i++)
            stars[i].draw(window);

        racket.draw(window);
        window.display();
    }

    return 0;
}