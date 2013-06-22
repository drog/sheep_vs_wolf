#include "map.hpp"

Map::Map()
{
	this->map = new Tmx::Map();
	
	map->ParseFile( "../img/map.tmx" );
	if( map->HasError() ) 
	{
		std::cout << "error code: " << map->GetErrorCode() << "\n" <<std::endl;
		std::cout << "error text: " << map->GetErrorText().c_str() << "\n" <<std::endl;
	}
	tileset = map->GetTileset(0);
	tilesize= tileset->GetTileWidth();
	
	layer = map->GetLayer(0);

	/*tileW = tileset->GetImage()->GetWidth() / tilesize;
	*/
}

Map::Map(const Map &) /* copy constructor */
{
	
}


Map::~Map()
{
	delete this->map;
}

void Map::load()
{

	//carga imagen del mapa especificado en el mapa.xml
	//if( !Image.loadFromFile( tileset->GetImage()->GetSource().c_str() ) )
	if( !Image.loadFromFile( "../img/f10942.png" ) )
	{
		std::cout << "Error to load Image from TileSet \n" <<std::endl;
	}
	
	//limite_derecho = (layer->GetWidth() - 1) * tilesize - SCREEN_WIDTH/4;
	//limite_inferior = (layer->GetHeight() - 1) * tilesize - SCREEN_HEIGHT/4;

	background_texture.loadFromFile("../img/map.png");
	background_sprite.setTexture(background_texture);
}

sf::Sprite Map::getBackground() const 
{
	return this->background_sprite;
	
}

void Map::setGrass()
{
	int j,i;
	for(j=0; j<= SCREEN_HEIGHT / tilesize; ++j)
		for (i=0; i<= SCREEN_WIDTH / tilesize; ++i)
			this->grass[j][i]=true;
		
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