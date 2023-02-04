#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// Purpose: A Base Class for Spells, that inherits from other set spells
/// </summary>
class IBaseSpell
{
public:
	IBaseSpell(sf::Vector2f t_direction, sf::Vector2f t_position) : m_damage(1), m_speed(1), m_cooldown(1), m_timeToLive(3), m_direction(t_direction) {}
	virtual ~IBaseSpell() {};

	//Functions
	virtual void update(sf::Time t_dt) = 0;
	virtual void render(sf::RenderWindow* t_window) = 0;
	virtual int getDmg() { return m_damage; }
	virtual float getTimeToLive() { return m_timeToLive; }
	virtual float getCooldown() = 0;
	virtual void setCooldown() =0;

protected:
	friend class SpellManager;
	sf::Vector2f m_direction;
	float m_speed;
	float m_cooldown;
	float m_timeToLive;
	int m_damage;
};