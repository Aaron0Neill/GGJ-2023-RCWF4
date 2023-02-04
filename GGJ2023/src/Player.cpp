#include "Player.h"

Player::Player(sf::RenderWindow* t_window) :
	m_window(t_window)
{
	m_texture.loadFromFile("PlayerSpriteSheet.png");

	m_sprite.setTexture(m_texture);
	m_sprite.addRow(AnimationStates::IDLE, { 15*64,0,64,38 }, 5);
	m_sprite.addRow(AnimationStates::FALL, { 13*64,0,64,38 }, 2);
	m_sprite.addRow(AnimationStates::ATTACK, { 0,0,64,38 }, 6);
	m_sprite.setState(AnimationStates::IDLE);
	m_sprite.setScale(5.f, 5.f);
	m_sprite.setPosition({ 100,GROUND_Y - m_sprite.getGlobalBounds().height});
}

//************************************************************************

void Player::render(sf::RenderWindow* t_window)
{
	t_window->draw(m_sprite);

	m_spellManager.render(t_window);
}

//************************************************************************

void Player::update(sf::Time& const t_dt)
{
	if (m_velocity != 0)
	{
		if (m_sprite.getState() != AnimationStates::FALL)
			m_sprite.setState(AnimationStates::FALL);
		sf::Vector2f currentPos = m_sprite.getPosition();
		currentPos.y -= m_velocity;
		m_velocity -= 1.f * t_dt.asSeconds();
		m_sprite.setPosition(currentPos);
		checkLevel();
	}

	if (m_sprite.getState() == AnimationStates::ATTACK)
	{
		m_attackTimer -= t_dt.asSeconds();
		if (m_attackTimer <= 0)
		{
			m_sprite.setState(AnimationStates::IDLE);
		}
	}
	m_sprite.update(t_dt);
	m_spellManager.update(t_dt);
}

//************************************************************************

void Player::handleEvents(sf::Event& t_event)
{
	if (sf::Event::MouseMoved == t_event.type)
		updateTracking();

	if (sf::Event::MouseButtonPressed == t_event.type)
		if (sf::Mouse::Left == t_event.mouseButton.button)
			if (fireSpell())
			{
				m_sprite.setState(AnimationStates::ATTACK);
				m_attackTimer = 6.0f * 0.25f;
			}
		

	if (sf::Event::KeyPressed == t_event.type)
		if (sf::Keyboard::Space == t_event.key.code)
			jump();
		else if (sf::Keyboard::Down == t_event.key.code)
			fall();
		else if (sf::Keyboard::Q == t_event.key.code)
			m_currentSpell = (m_currentSpell == SpellTypes::FIRE_BALL) ? SpellTypes::LIGHTNING : SpellTypes::FIRE_BALL;
}

void Player::jump()
{
	if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height > BRANCH_Y)
	{
		m_velocity = m_jumpSpeed;
		m_jump = true;
	}
}

void Player::fall()
{
	if (m_sprite.getPosition().y + m_sprite.getGlobalBounds().height < GROUND_Y  && !m_jump)
		m_velocity = -0.01f;
}

bool Player::fireSpell()
{
	sf::Vector2f spawnPoint = m_sprite.getPosition() + m_offset;
	sf::Vector2f targetPoint = m_mousePos;

	sf::Vector2f direction = calculateDirection(spawnPoint, targetPoint);

	return m_spellManager.addSpell(SpellTypes::FIRE_BALL, direction, spawnPoint);
}

void Player::checkLevel()
{
	bool stateChanged = false;
	float height = m_sprite.getGlobalBounds().height;
	float level = m_sprite.getPosition().y + height;
	if (level > BRANCH_Y && m_velocity < 0 && m_jump)
	{
		stateChanged = true;
		m_jump = false; 
		m_sprite.setPosition({ m_sprite.getPosition().x, BRANCH_Y - height });
	}
	else if (level > GROUND_Y)
	{
		stateChanged = true;
		m_sprite.setPosition({ m_sprite.getPosition().x, GROUND_Y - height });
	}

	if (stateChanged)
	{
		m_velocity = 0;
		m_sprite.setState(AnimationStates::IDLE);
	}
}

//************************************************************************

void Player::updateTracking()
{
	m_mousePos = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));
}
