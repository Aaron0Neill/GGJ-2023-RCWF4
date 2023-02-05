#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
// window is 3/4 the size of the screen
const unsigned WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width / 4.f * 3.f;
const unsigned WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height / 4.f * 3.f;

const unsigned VIEW_WIDTH = 1920U;
const unsigned VIEW_HEIGHT = 1080U;

const unsigned GROUND_Y = VIEW_HEIGHT - 40;
const unsigned BRANCH_Y = VIEW_HEIGHT - 380;

static sf::Vector2f calculateDirection(sf::Vector2f t_pos, sf::Vector2f t_target)
{
	sf::Vector2f directionalVector = t_target - t_pos;
	float vectorLength = sqrt(powf(directionalVector.x, 2) + powf(directionalVector.y, 2));
	sf::Vector2f unitVector;
	if (vectorLength != 0)
		unitVector = directionalVector / vectorLength;
	return unitVector;
}

#endif