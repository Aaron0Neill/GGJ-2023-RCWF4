#pragma once

#include "IBaseSpell.h"
#include <iostream>

class Fireball :
	public IBaseSpell
{
public:
	Fireball(sf::Vector2f t_direction, sf::Vector2f t_position);
	~Fireball()override {};

	virtual void update(sf::Time t_dt)override;
	virtual void render(sf::RenderWindow* t_window)override;

	virtual sf::FloatRect getGlobalBounds() { return m_body.getGlobalBounds(); }
private:
	sf::CircleShape m_body;
};