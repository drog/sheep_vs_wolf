#ifndef WOLF_HPP
#define WOLF_HPP

#include <SFML/Graphics.hpp>  
#include <iostream> 
#include "config.hpp"
#include "map.hpp"

class Wolf {
	public:
		Wolf();  
		virtual ~Wolf();
		sf::Sprite getSprite();  
		void move(int mov);
		void check_collisions( const int tilesize, int mov, Map *map );
		sf::Vector2i getPosition();
		inline bool getLife(){ return this->life; };
	private:	
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2i source;	/* obtain the position of wolf on the sprite */
		sf::Vector2i position;
		int hunger;
		bool life;

};
#endif
