/* g++  main.cpp -o asd  -lsfml-graphics -lsfml-window -lsfml-system */

#include <iostream> 
#include <SFML/Graphics.hpp>  
#include <time.h>
#include "config.hpp"
#include "sheep.cpp"
#include "wolf.cpp"
#include "map.cpp"
#include "utils.hpp"
int main()
{
    srand ( time(NULL) );

    /* options of screen are in config.hpp */
    sf::RenderWindow Window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, DEPTH),  "Wolf v/s Sheep" ); 
    Window.setFramerateLimit(18); 

    Map *map = new Map;
    map->load();
    const int tilesize = map->GetTilesize(); /* map tilesize */

    Sheep *sheep = new Sheep[NUM_SHEEP]; /* num_sheep are in config.hpp*/
    Wolf *wolf = new Wolf[NUM_WOLF]; /* num_wolf are in config.hpp*/
    Utils *utils;
    //bool game_pause = false;

    sf::Font font;
    if (!font.loadFromFile("../fonts/scoreboard.ttf"))
        std::cout << " error to load fonts" <<std::endl;
    
    sf::Text textTitle("Sheep v/s Wolf",font, 34);
    textTitle.setColor(sf::Color::White);
    textTitle.setStyle(sf::Text::Bold);
    textTitle.setPosition(270,480);


    sf::Text textSheeps("Sheeps : ",font, 24);
    textSheeps.setColor(sf::Color::White);
    textSheeps.setStyle(sf::Text::Bold);
    textSheeps.setPosition(10,480);

    sf::Text textWolfs("Wolfs : ",font, 24);
    textWolfs.setColor(sf::Color::White);
    textWolfs.setStyle(sf::Text::Bold);
    textWolfs.setPosition(10,510);

    int mov;
    int live_sheeps = 0;
    int live_wolfs = 0;
    while(Window.isOpen()) /* game loop */
    {
        //time = clock.restart();
        sf::Event Event; 
        while(Window.pollEvent(Event))
        {
            switch(Event.type)
            {
                case sf::Event::Closed:
                    Window.close();
                    break;
                case sf::Event::KeyPressed:            
                        if (Event.key.code == sf::Keyboard::Escape)
                        {
                            Window.close();
                            break;
                        }
                        if(Event.key.code == sf::Keyboard::Space)
                        {
                            //game_pause = true;  
                            break; 
                        }
                default:
                    break;        
            } /* switch(Event.type) */
        } /* while(Window.pollEvent(Event)) */

        Window.clear();            
        Window.draw( map->getBackground() ); /* draw background */
        
        live_sheeps = 0;  
        live_wolfs = 0;
        for (int i=0; i<NUM_SHEEP; ++i){
            mov=rand()%4; 
            sheep[i].move( mov ); /* create a random number for movement of sheeps */
            sheep[i].check_collisions( tilesize, mov , map); 
            
            if(sheep[i].getLife())  
                live_sheeps++;   /* counter of sheeps */

            Window.draw( sheep[i].getSprite() ); /* draw sheeps */
        }

        for (int i=0; i<NUM_WOLF; ++i){
            wolf[i].move( rand()%4 ); /* create a random number for movement of wolfs */
            wolf[i].check_collisions(); 

            if(wolf[i].getLife())  
                live_wolfs++;   /* counter of wolfs */

            Window.draw( wolf[i].getSprite() ); /* draw wolfs */
        }

        textWolfs.setString("Wolfs : "+ utils->int2Str(live_wolfs) );
        textSheeps.setString("Sheeps : "+ utils->int2Str(live_sheeps) ); 

        Window.draw(textTitle);
        Window.draw(textSheeps);
        Window.draw(textWolfs);
        Window.display();
        
    } /* game loop */
} /* main */