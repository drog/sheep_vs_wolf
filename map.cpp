#include "map.hpp"

Map::Map()
{

}

Map::~Map()
{
	delete map;
}

void Map::loadMap()
{
	map = new Tmx::Map();
	map->ParseFile( "../img/map.tmx" );
	if( map->HasError() ) 
	{
		printf("error code: %d\n", map->GetErrorCode());
		printf("error text: %s\n", map->GetErrorText().c_str());
	}
}

void Map::load()
{
	loadMap();
	tileset = map->GetTileset(0);
	//carga imagen del mapa especificado en el mapa.xml
	//Image = loadFromFile( tileset->GetImage()->GetSource().c_str() );   
	//if( !Image.loadFromFile( tileset->GetImage()->GetSource().c_str() ) )
	if( !Image.loadFromFile( "../img/f10942.png" ) )
	{
		printf ("Error to load Image from TileSet \n");
	}

	tilesize= tileset->GetTileWidth();
	tileW = tileset->GetImage()->GetWidth() / tilesize;
	layer = map->GetLayer(0);
	
	limite_derecho = (layer->GetWidth() - 1) * tilesize - SCREEN_WIDTH/4;
	limite_inferior = (layer->GetHeight() - 1) * tilesize - SCREEN_HEIGHT/4;

	background_texture.loadFromFile("../img/map.png");
	background_sprite.setTexture(background_texture);
}

sf::Sprite Map::getBackground()
{
	return background_sprite;
	
}


/*
void Map::imprimir(sf::RenderWindow &window)
{
	static int l ,x ,y;
	sf::IntRect tileRect;
	sf::IntRect mapRect;
	tileRect.width= tilesize;
	tileRect.height= tilesize;
	sf::Sprite sprite;
	sprite.setTexture(Image);
	const int layers = map->GetNumLayers();
	const int layerWidth = layer->GetWidth();
	const int layerHeight = layer->GetHeight();

	for (l = 0; l < layers; ++l) 
	{
		layer = map->GetLayer(l);
		for (x = 0; x < layerWidth; ++x)
		{
			for (y = 0; y < layerHeight; ++y)
			{
				tileId = layer->GetTileId(x, y);

				tileRect.left = (tileId % tileW) *tilesize;
				tileRect.top = (tileId / tileW) *tilesize;

				mapRect.left= x * tilesize;
				mapRect.top= y * tilesize;

				window.draw( sprite );
			}
		}
	}
}
*/