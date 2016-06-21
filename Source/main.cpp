//
// Created by Jun Hyuk Han on 6/3/16.
//

#include <cstdlib>
#include <sstream>

#include "SFML/Graphics.hpp"
#include "Bat.h"
#include "Ball.h"

using namespace sf;

int main()
{
	int windowWidth = 1024;
	int windowHeight = 768;

	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");
	window.setFramerateLimit(60);


	int score = 0;
	int lives = 3;

	Bat bat(windowWidth / 2, windowHeight / 2);

	Ball ball(windowWidth / 2, 1);

	Font font;
	font.loadFromFile("open-sans/Opensans-light.ttf");

	Text hud;
	hud.setString("Hello");
	hud.setFont(font);
	hud.setCharacterSize(32);
	hud.setColor(Color::White);
	hud.setPosition(window.getSize().x / 2 - hud.getGlobalBounds().width / 2,
	                window.getSize().y / 2 - hud.getGlobalBounds().height / 2);

	window.clear(sf::Color::Black);
	window.draw(hud);
	window.display();

	Event event;
	Keyboard keyboard;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::Closed:
					window.close();
					break;
				default:
					break;
			}

		}
		if(Keyboard::isKeyPressed(Keyboard::Right))
			bat.moveHorizontal(1);
		if(Keyboard::isKeyPressed(Keyboard::Left))
			bat.moveHorizontal(-1);

		if(Keyboard::isKeyPressed(Keyboard::Up))
			bat.moveVertical(-1);
		if(Keyboard::isKeyPressed(Keyboard::Down))
			bat.moveVertical(1);

		if(Keyboard::isKeyPressed(Keyboard::Space))
			bat.slowDown(0.9f);



		window.clear(sf::Color::Black);
		bat.update();
		window.draw(bat.getShape());
		window.display();
	}


	return 0;

}