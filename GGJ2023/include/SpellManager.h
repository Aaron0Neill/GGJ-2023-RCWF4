#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>

#include "IBaseSpell.h"
#include "Fireball.h"
#include "SeedPellet.h"

enum class SpellTypes 
{
	FIRE_BALL,
	LIGHTNING
};

class SpellManager
{
public:
	SpellManager();

	void update(sf::Time t_dt);

	void render(sf::RenderWindow* t_window);

	bool addSpell(SpellTypes const& t_spellType, sf::Vector2f t_direction, sf::Vector2f t_position);

	std::list<IBaseSpell*>& const getSpells() { return m_activeSpells; }

private:
	std::unordered_map<SpellTypes, std::function<IBaseSpell* (sf::Vector2f, sf::Vector2f)>> m_spellMap;

	std::list<IBaseSpell*> m_activeSpells;
};
