#include "Enemy.h"

Enemy::Enemy() : 
	Enemy({1920,880})
{
}

Enemy::Enemy(sf::Vector2f t_startPos)
{
	m_body.setSize({ 50,200 });
	m_body.setPosition(t_startPos);
	m_body.setFillColor(sf::Color::Red);

	std::cout << "Enemy Created\n";
}

Enemy::~Enemy()
{
	std::cout << "Enemy Killed\n";
}

void Enemy::update(sf::Time t_dt)
{
	sf::Vector2f pos = m_body.getPosition();
	pos.x -= m_movementSpeed * t_dt.asSeconds();
	m_body.setPosition(pos);
}

void Enemy::render(sf::RenderWindow* t_window)
{
	t_window->draw(m_body);
}
