//
// Created by Jun Hyuk Han on 6/20/16.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Ball
{
private:
	Vector2f position;

	RectangleShape ballShape;

	float xVelocity = 0.2f;
	float yVelocity = 0.2f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();
	void reboundBatorTop();
	void hitBottom();

	void update();
};


#endif //PONG_BALL_H
