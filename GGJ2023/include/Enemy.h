#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy
{
public: 
	Enemy();
	Enemy(sf::Vector2f t_startPos);
	~Enemy();

	void update(sf::Time t_dt);

	void render(sf::RenderWindow* t_window);

private:
	friend class EnemyManager;
	float m_movementSpeed { 100.0f };

	sf::RectangleShape m_body;
};