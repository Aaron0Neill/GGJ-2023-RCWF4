#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>
#include "SpellManager.h"
#include "AnimatedSprite.h"

class Player
{
public: 
	Player(sf::RenderWindow* t_window);
	~Player();

	void render(sf::RenderWindow* t_window);

	void update(sf::Time& const t_dt);

	void handleEvents(sf::Event& t_event);

	void jump();

	void fall();
	std::list <IBaseSpell*>& const getSpells() { return m_spellManager.getSpells(); }
	bool fireSpell();
private:
	void checkLevel();

	void updateTracking();

	sf::Texture m_texture;
	AnimatedSprite m_sprite;

	sf::Vector2f m_mousePos;

	sf::Vector2f m_offset{ 25,25 };

	float m_velocity;
	float m_jumpSpeed{0.75f};
	bool m_jump{ false };

	float m_attackTimer;

	sf::RenderWindow* m_window;
	SpellManager m_spellManager;
	SpellTypes m_currentSpell;
};