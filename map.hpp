#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>  
#include <TmxParser/Tmx.h>
#include "config.hpp"

class Map 
{
	public:
		Map( void ) ;  
		~Map( void ) ;
		void loadMap(void);
		void load(void);
		sf::Sprite getBackground(void);
		//void imprimir(sf::RenderWindow &window);


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

    protected:
    	Tmx::Map *map;
		const Tmx::Tileset *tileset = NULL;
		const Tmx::Layer *layer = NULL;
		sf::Image Image;
		sf::Texture background_texture;
		sf::Sprite background_sprite;
		int tilesize;
		int tileW;
		int	tileId;
    	int limite_derecho;
		int limite_inferior;
		static const unsigned int  tileSolid = 160; // 160 is id of tile solid

};
#endif
