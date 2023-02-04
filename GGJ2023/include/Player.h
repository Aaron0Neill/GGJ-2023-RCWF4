#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>
#include "SpellManager.h"

class Player
{
public: 
	Player(sf::RenderWindow* t_window);

	void render(sf::RenderWindow* t_window);

	void update(sf::Time& const t_dt);

	void handleEvents(sf::Event& t_event);

	void jump();

	void fall();

	void fireSpell();
private:
	void checkLevel();

	void updateTracking();

	/// <summary>
	/// Sample body <REPLACE WITH A SPRITE>
	/// </summary>
	sf::RectangleShape m_body;

	sf::VertexArray m_trackingLine;

	sf::Vector2f m_mousePos;

	sf::Vector2f m_offset{ 25,25 };

	float m_velocity;
	float m_jumpSpeed{0.75f};
	bool m_jump{ false };

	sf::RenderWindow* m_window;
	SpellManager m_spellManager;
	SpellTypes m_currentSpell;
};