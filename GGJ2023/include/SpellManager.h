#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <functional>

class Spell
{
public:
	Spell()
	{
		timeToLive = 2;
		std::cout << "Spell was created.\n";
	}

	~Spell()
	{
		std::cout << "Spell was deleted.\n";

	}

	void update(sf::Time t_dt)
	{
		timeToLive -= t_dt.asSeconds();
	}
	float timeToLive;
};


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

	void addSpell(SpellTypes const& t_spellType);

private:
	std::unordered_map<SpellTypes, std::function<Spell* ()>> m_spellMap;

	std::list<Spell*> m_activeSpells;
};
