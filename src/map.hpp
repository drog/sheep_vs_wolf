#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>  
#include <TmxParser/Tmx.h>
#include <iostream>
#include "config.hpp"

class Map 
{
	public:
		Map( void ) ;  
		Map(const Map &);  /* copy constructor */
		~Map( void ) ;
		void load(void);
		sf::Sprite getBackground(void) const ;
		//void imprimir(sf::RenderWindow &window);
		void setInitialGrass();
		void regenGrass();
		void printMap(sf::RenderWindow *Window);
		inline bool isSolid( int x, int y )
		{ 
			if(map->GetLayer(0)->GetTileId(x, y) == tileSolid )
				return true;
			return false;	 
		};

		inline const int GetTilesize( void ) 
		{ 
			return map->GetTileset(0)->GetTileWidth(); 
		};

		inline bool isGrass(int i,int j)
		{ 
			return this->grass[i][j]; 
		};

		inline void setGrass(int i, int j)	
		{
			this->grass[i][j]=false;
		};	

    protected:
    	Tmx::Map *map;
		const Tmx::Tileset *tileset;
		const Tmx::Layer *layer;
		sf::Texture background_texture;
		sf::Sprite background_sprite;
		sf::Texture tiles_texture;
		sf::Sprite tiles_sprite;
		int tilesize;
		//int tileW;
		//int	tileId;
    	//int limite_derecho;
		//int limite_inferior;
		static const unsigned int  tileSolid = 160; // 160 is id of tile solid
		bool grass[ SCREEN_WIDTH/16 ][ SCREEN_HEIGHT/16 ];
		int grass_time[ SCREEN_WIDTH/16 ][ SCREEN_HEIGHT/16 ];

};
#endif
