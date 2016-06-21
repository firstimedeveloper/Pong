//
// Created by Jun Hyuk Han on 6/20/16.
//

#include "Bat.h"

Bat::Bat(float startX, float startY)
{
	//set starting position
	position.x = startX;
	position.y = startY;

	//set shape of player and initialize position
	batShape.setSize(sf::Vector2f(50,5));
	batShape.setPosition(position);

	//initial velocity is 0x,0y and is a vector
	velocity.x = 0.0f;
	velocity.y = 0.0f;

	//acceleration is always 0.5x,0.5y //velocity always increases by the same amount (value of acceleration)
	acceleration.x = accelerationVal;
	acceleration.y = accelerationVal;



}

FloatRect Bat::getPosition()
{
	return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return batShape;
}

void Bat::update() // changing the position in update (where it's called every frame) will have continuous movement
{
	position += velocity;
	velocity.x *= 0.9f;
	velocity.y *= 0.9f;

	batShape.setPosition(position);

}


void Bat::moveHorizontal(int direction) //values are 1 and -1
{

	if(std::abs(velocity.x) < terminalVelocity) //if velocity less than terminal velocity, change velocity by value of acceleration
	{
		velocity.x += acceleration.x * direction ;
		//velocity.x *= 0.8f;
	}
}

void Bat::moveVertical(int direction)   //values are 1 and -1 //this is inversed, so -1 goes up 1 goes down
{

	if(std::abs(velocity.y) < terminalVelocity) //if velocity less than terminal velocity, change velocity by value of acceleration
	{
		velocity.y += acceleration.y * direction ;
		//velocity.y *= 0.8f;
	}
}

void Bat::slowDown(float percent) // slowdown the player drastically
{
	velocity.x *= percent;
	velocity.y *= percent;
}
