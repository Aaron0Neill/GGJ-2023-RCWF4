#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>

class Player : 
	public sf::Drawable
{
public: 
	Player(sf::RenderWindow* t_window);

	void draw(sf::RenderTarget& const t_target, sf::RenderStates t_state) const override;

	void update(sf::Time& const t_dt);

	void handleEvents(sf::Event& t_event);

	void jump();

	void fall();
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
};