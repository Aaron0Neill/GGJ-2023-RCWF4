#include "Enemy.h"

Enemy::Enemy(sf::Texture& t_texture, sf::Vector2f t_startPos) : 
	m_sprite(t_texture)
{
	m_sprite.setScale(-5, 5);
	sf::FloatRect size = m_sprite.getGlobalBounds();
	m_sprite.setPosition(t_startPos - sf::Vector2f{0, size.height});
	m_sprite.addRow(AnimationStates::RUN, { 0,0,64, 22 }, 7);
	m_sprite.setState(AnimationStates::RUN);
}

Enemy::~Enemy()
{
	std::cout << "Enemy Killed\n";
}

void Enemy::update(sf::Time t_dt)
{
	sf::Vector2f pos = m_sprite.getPosition();
	pos.x -= m_movementSpeed * t_dt.asSeconds();
	m_sprite.setPosition(pos);

	m_sprite.update(t_dt);
}

void Enemy::render(sf::RenderWindow* t_window)
{
	t_window->draw(m_sprite);
}
