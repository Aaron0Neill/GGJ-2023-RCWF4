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

	virtual float getCooldown()override { return m_cooldown; }
	virtual void setCooldown() { m_cooldown = 1.0f; }
private:
	friend class SpellManager;
	sf::CircleShape m_body;
	static float m_cooldown;
	static bool m_modified;
};