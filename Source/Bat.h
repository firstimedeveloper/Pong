//
// Created by Jun Hyuk Han on 6/20/16.
//

#ifndef PONG_BAT_H
#define PONG_BAT_H

#include "SFML/Graphics.hpp"
#include <cmath>

using namespace sf;

class Bat
{
private:
	Vector2f position;

	RectangleShape batShape;

	Vector2f velocity;
	Vector2f acceleration;

	float terminalVelocity = 10.0f;
	float accelerationVal = 0.5f;   //float, to change easily if need be


public:
	Bat(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveHorizontal(int direction);
	void moveVertical(int direction);
	void update();
	void slowDown(float percent);




};


#endif //PONG_BAT_H
