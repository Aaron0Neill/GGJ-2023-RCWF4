#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "AnimatedSprite.h"

class Enemy
{
public: 
	Enemy(sf::Texture& t_texture, sf::Vector2f t_startPos);
	~Enemy();

	void update(sf::Time t_dt);

	void render(sf::RenderWindow* t_window);

	sf::FloatRect getGlobalBound() { return m_sprite.getGlobalBounds(); }

	int m_health;

private:
	friend class EnemyManager;
	float m_movementSpeed { 75.0f };

	AnimatedSprite m_sprite;
	sf::Texture m_texture;
};