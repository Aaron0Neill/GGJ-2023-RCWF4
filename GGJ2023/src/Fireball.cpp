#include "Fireball.h"

float Fireball::m_cooldown = 0;
bool Fireball::m_modified = false;

Fireball::Fireball(sf::Vector2f t_direction, sf::Vector2f t_position) :
	IBaseSpell(t_direction, t_position)
{
	m_body.setRadius(10.f);
	m_body.setFillColor(sf::Color::Red);
	m_body.setPosition(t_position);
	m_speed = 500;
	m_timeToLive = 3.f;
}

void Fireball::update(sf::Time t_dt)
{
	sf::Vector2f currentPos = m_body.getPosition();
	currentPos += m_direction * m_speed * t_dt.asSeconds();
	m_body.setPosition(currentPos);

	m_timeToLive -= t_dt.asSeconds();
	if (m_cooldown > 0 && !m_modified)
	{
		m_cooldown -= t_dt.asSeconds();
		m_modified = true;
	}

}

void Fireball::render(sf::RenderWindow* t_window)
{
	t_window->draw(m_body);
}
