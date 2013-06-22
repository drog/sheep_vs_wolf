#include "wolf.hpp"

Wolf::Wolf()
{
	if( !this->texture.loadFromFile("../img/animals.png") )
        std::cout <<  "could not locate the specified file"  << std::endl; 
    else
        this->sprite.setTexture(this->texture);
    
    this->sprite.setPosition(60.0f, 20.0f);
    this->life = true;
    this->source.x=4;
    this->source.y=1;
}

Wolf::~Wolf()
{
    //delete texture;
    //delete sprite;
}

sf::Sprite Wolf::getSprite() 
{
    return this->sprite;
}

sf::Vector2i Wolf::getPosition()
{
	this->position.x = this->sprite.getPosition().x;
	this->position.y = this->sprite.getPosition().y;
	return this->position;
}

void Wolf::move ( int mov ){
	const int texture_size_x = texture.getSize().x; /*  image.x / 2 => contains sheeps and wolf*/

	this->source.x++;
	if( this->source.x*32 >= texture_size_x )
		this->source.x=4;

	switch(mov) { 
	case 0:		/* move down */
       	this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
       	this->sprite.move(0,10);
		break;	
	case 1:		/* move left */
        this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
        this->sprite.move(-10,0);
		break;	
	case 2:		/* move right */
        this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
        this->sprite.move(10,0);
		break;	
	case 3:		/* move up */
        this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
        this->sprite.move(0,-10);
		break;
	}
	hunger-=4;
}


void Wolf::check_collisions( const int tilesize , int mov , Map *map){
	const int texture_size_x = texture.getSize().x/2; /*  image.x / 2 => contains sheeps and wolf*/

	this->position.x = this->sprite.getPosition().x;
	this->position.y = this->sprite.getPosition().y;

/*	
			____________	
 (x1,y1)>	|			|	<(x2,y1)
			|	image	|
			|			|
			|			|
 (x1,y2)>	-------------	<(x2,y2)
*/

	int x1 = (this->position.x + 5) / tilesize;  /* posx + 5 for better collision   */
	int y1 = (this->position.y + 5) / tilesize;
	int x2 = (this->position.x + 32 - 5) / tilesize;
	int y2 = (this->position.y + 32 - 5) / tilesize;

	/*  map->isSolid(int x, int y) return true if the position is solid  */
	if( map->isSolid( x1 , y1) || map->isSolid( x2 , y2) || map->isSolid( x2 , y1) || map->isSolid( x1 , y2) )
	{

		this->source.x++;
		if( this->source.x*32 >= texture_size_x )
			this->source.x=4;

		switch(mov) { 
		case 0:		/* if move down move up*/
	       	this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
	       	this->sprite.move(0,-10);
			break;	
		case 1:		/* if move left move right*/
	        this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
	        this->sprite.move(10,0);
			break;	
		case 2:		/* if move right move left*/
	        this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
	        this->sprite.move(-10,0);
			break;	
		case 3:		/* if move up move down*/
	        this->sprite.setTextureRect( sf::IntRect(this->source.x*32, mov*32, 32, 32) );
	        this->sprite.move(0,10);
			break;
		}
	}
}


