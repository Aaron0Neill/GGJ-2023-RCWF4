#include "Fireball.h"

Fireball::Fireball(sf::Vector2f t_direction, sf::Vector2f t_position) :
	IBaseSpell(t_direction, t_position)
{
	std::cout << "Fireball Created\n";
	m_body.setRadius(10.f);
	m_body.setFillColor(sf::Color::Red);
	m_body.setPosition(t_position);
	m_speed = 50;
	m_timeToLive = 3;
}

void Fireball::update(sf::Time t_dt)
{
	sf::Vector2f currentPos = m_body.getPosition();
	currentPos += m_direction * m_speed * t_dt.asSeconds();
	m_body.setPosition(currentPos);

	m_timeToLive -= t_dt.asSeconds();
}

void Fireball::render(sf::RenderWindow* t_window)
{
	t_window->draw(m_body);
}
