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

	sf::FloatRect getGlobalBound() { return m_body.getGlobalBounds(); }

	int m_health;

private:
	friend class EnemyManager;
	float m_movementSpeed { 100.0f };

	sf::RectangleShape m_body;
};