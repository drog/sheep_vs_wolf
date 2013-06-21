/* g++  main.cpp -o asd  -lsfml-graphics -lsfml-window -lsfml-system */

#include <iostream> 
#include <SFML/Graphics.hpp>  
#include <time.h>
#include "config.hpp"
#include "sheep.cpp"
#include "wolf.cpp"
#include "map.cpp"

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

    //bool game_pause = false;

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

        Window.draw( map->getBackground() ); /* draw background */
        int mov;          
        for (int i=0; i<NUM_SHEEP; ++i){
            mov=rand()%4; 
            sheep[i].move( mov ); /* create a random number for movement of sheeps */
            sheep[i].check_collisions( tilesize, mov , map); 
            Window.draw( sheep[i].getSprite() ); /* draw sheeps */
        }

        for (int i=0; i<NUM_WOLF; ++i){
            wolf[i].move( rand()%4 ); /* create a random number for movement of wolfs */
            wolf[i].check_collisions(); 
            Window.draw( wolf[i].getSprite() ); /* draw wolfs */
        }
        
        Window.display();
        
    } /* game loop */
} /* main */