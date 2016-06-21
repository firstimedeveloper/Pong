//
// Created by Jun Hyuk Han on 6/20/16.
//

#include "Ball.h"

Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setSize(sf::Vector2f(10,10));
	ballShape.setPosition(position);
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity = -xVelocity;
}

void Ball::reboundBatorTop()
{
	position.x -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

void Ball::hitBottom()
{
	position.x = 500;
	position.y = 1;
}

void Ball::update()
{
	position.x += xVelocity;
	position.y += yVelocity;

	ballShape.setPosition(position);
}
