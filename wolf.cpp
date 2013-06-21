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

sf::Sprite Wolf::getSprite() {
    return this->sprite;
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
}


void Wolf::check_collisions(){
	int pos_x = this->sprite.getPosition().x;
	int pos_y = this->sprite.getPosition().y;
	
	if ( pos_x < 0.0f ) {	/* left position of screen */
 		this->sprite.move(10,0); /* move right */	 
	}
	else if ( pos_x > SCREEN_WIDTH-SPRITE_SIZE ) {	/* right position of screen */
		this->sprite.move(-10,0); /* move left */
	}
	if ( pos_y < 0.0f ) {	/* up position of screen */
		this->sprite.move(0,10); /* move down */
	}
	else if ( pos_y > SCREEN_HEIGHT-SPRITE_SIZE ) {	/* down position of screen */
		this->sprite.move(0,-10); /* move up */
	}
}


