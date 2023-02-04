#include "SpellManager.h"

SpellManager::SpellManager()
{
	m_spellMap[SpellTypes::FIRE_BALL] = [](sf::Vector2f t_direction, sf::Vector2f t_position) { return new Fireball(t_direction, t_position); };
	m_spellMap[SpellTypes::LIGHTNING] = [](sf::Vector2f t_direction, sf::Vector2f t_position) { return new SeedPellet(t_direction, t_position); };
}

bool SpellManager::addSpell(SpellTypes const& t_spellType, sf::Vector2f t_direction, sf::Vector2f t_position)
{
	IBaseSpell* spell = m_spellMap[t_spellType](t_direction, t_position);

	if (spell->getCooldown() > 0)
	{
		delete spell;
		return false;
	}
	m_activeSpells.push_back(spell);
	spell->setCooldown();
	return true;
}

void SpellManager::update(sf::Time t_dt)
{
	for (auto& spells : m_activeSpells)
		spells->update(t_dt);

	m_activeSpells.remove_if([](IBaseSpell* t_spell) {
		if (t_spell->getTimeToLive() <= 0)
		{
			delete t_spell;
			return true;
		}
		return false;
		});
	Fireball::m_modified = false;
}

void SpellManager::render(sf::RenderWindow* t_window)
{
	for (auto spells : m_activeSpells)
		spells->render(t_window);
}