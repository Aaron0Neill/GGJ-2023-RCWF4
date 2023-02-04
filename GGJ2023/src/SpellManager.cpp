#include "SpellManager.h"

SpellManager::SpellManager()
{
	m_spellMap[SpellTypes::FIRE_BALL] = []() { return new Spell(); };
	m_spellMap[SpellTypes::LIGHTNING] = []() { return new Spell(); };
}

void SpellManager::addSpell(SpellTypes const& t_spellType)
{
	m_activeSpells.push_back(m_spellMap[t_spellType]());
}

void SpellManager::update(sf::Time t_dt)
{
	for (auto& spells : m_activeSpells)
		spells->update(t_dt);

	m_activeSpells.remove_if([](Spell* t_spell) {
		if (t_spell->timeToLive <= 0)
		{
			delete t_spell;
			return true;
		}
		return false;
		});
}

void SpellManager::render(sf::RenderWindow* t_window)
{

}