#pragma once
#include <SFML/Graphics.hpp>

class SeedPellet
{
public:
	SeedPellet();
	~SeedPellet();
private:
	int dmg = 3;
	int animationRate = 10;
	int topLGridCoord_x = 0; int topLGridCoord_y = 0;
	sf::Sprite seedPelletS; sf::Sprite seedPellet1S;
};

class Fireball
{
public:
	Fireball();
	~Fireball();
private:
	int dmg = 5;
	int animationRate = 10;
	int topLGridCoord_x = 0; int topLGridCoord_y = 0;
	sf::Sprite fireballS; sf::Sprite fireball1S;
};