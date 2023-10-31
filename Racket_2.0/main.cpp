#include "GameLib.h"


int main()
{
    
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(map_width, map_height), "Racket 2");
    sf::Image icon;
    if (!icon.loadFromFile("textures\\racket.png"))
        return 1;
    window.setIcon(100, 90, icon.getPixelsPtr());
    window.setVerticalSyncEnabled(true);
    int max_score = 0;
start:
    //------------------------------------------------------------background-----------------------------------------------
    sf::RectangleShape back_g(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t;
    if(!back_ground_t.loadFromFile("textures\\map.png"))
        return 2;
    back_g.setTexture(&back_ground_t);
    back_g.setPosition(sf::Vector2f(0, 0));

    sf::RectangleShape back_g2(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t2;
    if(!back_ground_t2.loadFromFile("textures\\map2.png"))
        return 2;
    back_g2.setTexture(&back_ground_t2);
    back_g2.setPosition(sf::Vector2f(0, -600));

    sf::RectangleShape beetwen2and3(sf::Vector2f(1200, 600));
    sf::Texture beetwen2and3_t;
    if(!beetwen2and3_t.loadFromFile("textures\\beetwen2and3.png"))
        return 2;
    beetwen2and3.setTexture(&beetwen2and3_t);
    beetwen2and3.setPosition(sf::Vector2f(0, -1200));

    sf::RectangleShape back_g3(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t3;
    if(!back_ground_t3.loadFromFile("textures\\map3.png"))
        return 2;
    back_g3.setTexture(&back_ground_t3);
    back_g3.setPosition(sf::Vector2f(0, -1800));

    sf::RectangleShape back_g4(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t4;
    back_ground_t4.loadFromFile("textures\\map4.png");
    back_g4.setTexture(&back_ground_t4);
    back_g4.setPosition(sf::Vector2f(0, -2400));


    sf::RectangleShape back_g5(sf::Vector2f(1200, 600));
    sf::Texture back_ground_t5;
    if(!back_ground_t5.loadFromFile("textures\\map5.png"))
        return 2;
    back_g5.setTexture(&back_ground_t5);
    back_g5.setPosition(sf::Vector2f(0, -3000));
    //---------------------------------------------------------racket--------------------------------
    Racket racket;
    sf::Texture r_t;
    if(!r_t.loadFromFile("textures\\racket.png"))
        return 3;
    racket.set_texture(&r_t);
//-----------------------------------------------------------------stars--------------------------------------
    std::vector<Star> stars(100);
    //-----------------------------------------------------------------------values---------------------------
    sf::Clock timer,left_bullet_timer, right_bullet_timer;
    float map_speed, star_speed,time, racket_speed,bullet_speed,meteor_speed;
    sf::Vector2f new_racket_pos;
    bool reset_left_bullet_clock = false;
    bool reset_right_bullet_clock = false;
    bool game_over = false;
    //---------------------------------------------------meteores-------------------------------------------
    constexpr int meteor_count = 15;
    std::vector<Meteor> meteores(meteor_count);
    sf::Texture meteor_t;
    if(!meteor_t.loadFromFile("textures\\meteor.png"))
        return 4;
    for (int i = 0; i < meteor_count; i++)
    {
        meteores[i].set_texture(&meteor_t);
    }
    //--------------------------------------------Score------------------------------------------------
    int score = 0;
    sf::Font font;
    if(!font.loadFromFile("textures\\sr.TTF"))
        return 5;
    sf::Text text("", font,20);
    text.setStyle(sf::Text::Bold);
    text.setPosition(sf::Vector2f(1050, 10));
    //------------------------------------------------------------back ground music----------------------------------------
    sf::Music music_back_g;
    if (!music_back_g.openFromFile("textures\\back_g_music.mp3"))
        return 6;
    music_back_g.setLoop(true);
    music_back_g.play();
    music_back_g.setVolume(50);
    //-----------------------------------------------racket fire sound----------------------------------------------------
    sf::Sound fire, stone_break;
    sf::SoundBuffer fire_b, stone_break_b;
    if(!fire_b.loadFromFile("textures\\racket_blast.mp3"))
        return 7;
    fire.setBuffer(fire_b);
    fire.setVolume(10);

    sf::Sound fire2;
    sf::SoundBuffer fire_b2;
    if(!fire_b2.loadFromFile("textures\\racket_blast2.mp3"))
        return 8;
    fire2.setBuffer(fire_b2);
    fire2.setVolume(10);
// ------------------------------------------------------------------break stone sound--------------------------
    stone_break_b.loadFromFile("textures\\break_stone.mp3");
    stone_break.setBuffer(stone_break_b);
 //-----------------------------------------------------------------Lose text-----------------
    sf::Text end("YOU LOSE", font, 10);
    sf::Text max_score_t("", font, 10);
 //-------------------------------------------------main while----------------------------------------------
    while (window.isOpen())
    {
        time = timer.getElapsedTime().asMicroseconds();
        map_speed = time / 5000;
        star_speed = time / 6000;
        meteor_speed = time / 4000;
        racket_speed = time / 2500;
        bullet_speed = time / 300;
        time /= 6000;
        
        timer.restart();
        sf::Event my_event;
        while (window.pollEvent(my_event))
        {

            if (my_event.type == sf::Event::Closed)
                window.close();

            switch (my_event.type)
            {
            case sf::Event::KeyPressed:
                if (my_event.key.code == sf::Keyboard::S) new_racket_pos.y = 1 * racket_speed;
                if (my_event.key.code == sf::Keyboard::W) new_racket_pos.y = -1 * racket_speed;
                if (my_event.key.code == sf::Keyboard::A) new_racket_pos.x = -1 * racket_speed;
                if (my_event.key.code == sf::Keyboard::D) new_racket_pos.x = 1 * racket_speed;
                if (my_event.key.code == sf::Keyboard::Space && racket.get_fired_left_ammo() == false) racket.set_fired_left_ammo(true);
                if (my_event.key.code == sf::Keyboard::Space && racket.get_fired_right_ammo() == false) racket.set_fired_right_ammo(true);
                break;
            case sf::Event::KeyReleased:
                if (my_event.key.code == sf::Keyboard::S) new_racket_pos.y = 0;
                if (my_event.key.code == sf::Keyboard::W) new_racket_pos.y = 0;
                if (my_event.key.code == sf::Keyboard::A) new_racket_pos.x = 0;
                if (my_event.key.code == sf::Keyboard::D) new_racket_pos.x = 0;
            default:                                                                                                                                                                                                                                    
                break;
            }
        }
        //----------------------------------back ground-----------------------------------------
        back_g.move(sf::Vector2f(0, map_speed));
        back_g2.move(sf::Vector2f(0, map_speed));
        beetwen2and3.move(sf::Vector2f(0, map_speed));
        back_g3.move(sf::Vector2f(0, map_speed));
        back_g4.move(sf::Vector2f(0, map_speed));
        back_g5.move(sf::Vector2f(0, map_speed));
        if (back_g.getPosition().y > 600)
            back_g.setPosition(sf::Vector2f(0, -2400));
        if (back_g2.getPosition().y > 600)
            back_g2.setPosition(sf::Vector2f(0, -2400));
        if (beetwen2and3.getPosition().y > 600)
            beetwen2and3.setPosition(sf::Vector2f(0, -2400));
        if (back_g3.getPosition().y > 600)
            back_g3.setPosition(sf::Vector2f(0, -2400));
        if (back_g4.getPosition().y > 600)
            back_g4.setPosition(sf::Vector2f(0, -2400));
        if (back_g5.getPosition().y > 600)
            back_g5.setPosition(sf::Vector2f(0, -2400));
        //--------------------------------------------racket fire--------------------------------------------------------
        // left ammo
        if (racket.get_fired_left_ammo())
        {
            //fire.play();
            if(!reset_left_bullet_clock)
                left_bullet_timer.restart();
            reset_left_bullet_clock = true;
            racket.left_ammo_move(bullet_speed);
        }
        if ((int)left_bullet_timer.getElapsedTime().asMilliseconds() > 300 && racket.get_fired_left_ammo() == true)
        {
            
            racket.set_fired_left_ammo(false);
            reset_left_bullet_clock = false;
            fire2.play();
        }
        // right ammo
        if (racket.get_fired_right_ammo())
        {
            
            if (!reset_right_bullet_clock)
                right_bullet_timer.restart();
            reset_right_bullet_clock = true;
            racket.right_ammo_move(bullet_speed);
        }
        if ((int)right_bullet_timer.getElapsedTime().asMilliseconds() > 300 && racket.get_fired_right_ammo() == true)
        {
            fire.play();
            racket.set_fired_right_ammo(false);
            reset_right_bullet_clock = false;
        }
        //------------------------------------------meteores move and rotate------------------------------------
        for (int i = 0; i < meteor_count; i++)
        {
            meteores[i].move(meteor_speed);
        }
        for (int i = 0; i < meteor_count; i++)
        {
            meteores[i].rotate(1);
        } 
        
        //-------------------------------------------------racket move--------------------------------------------------
        racket.move(new_racket_pos);
        auto pos = sf::Vector2f(racket.get_x(), racket.get_y());
        if (racket.get_x() > 1200)
            racket.set_pos(1200, pos.y);
        if (racket.get_x() < 0)
            racket.set_pos(0, pos.y);
        if (racket.get_y() > 600)
            racket.set_pos(pos.x, 600);
        if (racket.get_y() < 10)
            racket.set_pos(pos.x, 10);

        if(racket.get_y() < 11 && racket.get_x() > 1200)
            racket.set_pos(1200, 11);
        if (racket.get_y() < 11 && racket.get_x() < 0)
            racket.set_pos(0, 11);
        if (racket.get_y() > 599 && racket.get_x() > 1200)
            racket.set_pos(1200, 599);
        if (racket.get_y() > 599 && racket.get_x() < 0)
            racket.set_pos(0, 599);

        //----------------------------------------collisions check------------------------------
        for (int i = 0; i < meteor_count; i++)
        {
            if (meteores[i].collision(racket.get_left_ammo_bounds()) && racket.get_fired_left_ammo())
            {
                racket.reset_left_ammo();
                racket.left_ammo_move(0);
                if (meteores[i].get_health() <= 0)
                {
                    score++;
                    stone_break.play();
                    meteores[i].reborn();
                }
                else
                    meteores[i].decrement_health();
            }
            if (meteores[i].collision(racket.get_right_ammo_bounds()) && racket.get_fired_right_ammo())
            {
                racket.reset_right_ammo();
                racket.right_ammo_move(0);
                if (meteores[i].get_health() <= 0)
                {
                    score++;
                    meteores[i].reborn();
                }
                else
                    meteores[i].decrement_health();
            }
            if (meteores[i].collision(racket.get_bounds()))
            {
                game_over = true;
                break;
            }
            
        }

        //-------------------------------------------------------stars create-----------------------------------------
        for (int i = 0; i < stars.size(); i++)
            stars[i].move(star_speed);
        //-----------------------------------------------------back ground--------------------------------------------
        window.clear();
        window.draw(back_g);
        window.draw(back_g2);
        window.draw(beetwen2and3);
        window.draw(back_g3);
        window.draw(back_g4);
        window.draw(back_g5);
        //--------------------------------------------------------------draw stars and meteores-----------------------------------
        for (int i = 0; i < stars.size(); i++)
            stars[i].draw(window);
        for (int i = 0; i < meteor_count; i++)
        {
            meteores[i].draw(window);
        }
        //-----------------------------------------------------------draw racket----------------------
        racket.draw(window);
        //---------------------------------draw score-------------------------------------------------
        std::ostringstream os;
        os << score;
        text.setString("Score: " + os.str());
        window.draw(text);

        window.display();
        //----------------------------game over-----------------------------------------------
        if (game_over)
        {
            if (max_score < score)
                max_score = score;

            std::ostringstream os;
            os << max_score;

            max_score_t.setString("Max Score: " + os.str());
            max_score_t.setScale(10, 10);
            max_score_t.setPosition(map_width / 2 - 370, map_height / 2 + 40);
            end.setScale(10, 10);
            end.setPosition(map_width / 2- 370, map_height / 2-40);
            sf::Clock timer_end;
            end.setString(end.getString() + " "+text.getString());
            window.draw(max_score_t);
            window.draw(end);
            window.display();
            while (timer_end.getElapsedTime().asSeconds() < 2);
            window.display();
            while (timer_end.getElapsedTime().asSeconds() < 2);
            window.display();
            goto start;
        }
    }

    return 0;
}