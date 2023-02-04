#pragma once

#include "IBaseSpell.h"
#include <iostream>

class SeedPellet :
	public IBaseSpell
{
public:
	SeedPellet(sf::Vector2f t_direction, sf::Vector2f t_position);
	~SeedPellet()override {};

	virtual void update(sf::Time t_dt)override;
	virtual void render(sf::RenderWindow* t_window)override;

	virtual float getCooldown() {
		return 0;
	};
	virtual void setCooldown() {};

	virtual sf::FloatRect getGlobalBounds() { return m_body.getGlobalBounds(); }
private:
	sf::CircleShape m_body;
};