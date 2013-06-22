#ifndef WOLF_HPP
#define WOLF_HPP

#include <SFML/Graphics.hpp>  
#include <iostream> 
#include "config.hpp"

class Wolf {
	public:
		Wolf();  
		virtual ~Wolf();
		sf::Sprite getSprite();  
		void move(int mov);
		void check_collisions();
		inline bool getLife(){ return this-life; };
	private:	
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2i source;
		bool life;

};
#endif
