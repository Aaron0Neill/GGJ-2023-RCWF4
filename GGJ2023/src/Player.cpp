#include "Player.h"

Player::Player(sf::RenderWindow* t_window) :
	m_window(t_window), 
	m_trackingLine(sf::Lines)
{
	m_body.setSize({ 50,200 });
	m_body.setPosition({ 100, GROUND_Y - 200 });

	m_trackingLine.resize(2);
	m_trackingLine[0].position = m_body.getPosition() + m_offset;

	for (int i = 0; i < 2; ++i)
		m_trackingLine[i].color = sf::Color::Red;
}

//************************************************************************

void Player::render(sf::RenderWindow* t_window)
{
	t_window->draw(m_body);

	m_spellManager.render(t_window);
}

//************************************************************************

void Player::update(sf::Time& const t_dt)
{
	if (m_velocity != 0)
	{
		sf::Vector2f currentPos = m_body.getPosition();
		currentPos.y -= m_velocity;
		m_velocity -= 1.f * t_dt.asSeconds();
		m_body.setPosition(currentPos);
		m_trackingLine[0].position = currentPos + m_offset;
		checkLevel();
	}
	m_spellManager.update(t_dt);
}

//************************************************************************

void Player::handleEvents(sf::Event& t_event)
{
	if (sf::Event::MouseMoved == t_event.type)
		updateTracking();

	if (sf::Event::MouseButtonPressed == t_event.type)
		if (sf::Mouse::Left == t_event.mouseButton.button)
			fireSpell();

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
	if (m_body.getPosition().y + m_body.getSize().y > BRANCH_Y)
	{
		m_velocity = m_jumpSpeed;
		m_jump = true;
	}
}

void Player::fall()
{
	if (m_body.getPosition().y + m_body.getSize().y < GROUND_Y  && !m_jump)
	{
		m_velocity = -0.01f;
	}
}

void Player::fireSpell()
{
	sf::Vector2f spawnPoint = m_body.getPosition() + m_offset;
	sf::Vector2f targetPoint = m_trackingLine[1].position;

	sf::Vector2f direction = calculateDirection(spawnPoint, targetPoint);

	m_spellManager.addSpell(m_currentSpell, direction, spawnPoint);
}

void Player::checkLevel()
{
	float level = m_body.getPosition().y + m_body.getSize().y;
	if (level > BRANCH_Y && m_velocity < 0 && m_jump)
	{
		m_jump = false; 
		m_body.setPosition({ m_body.getPosition().x, BRANCH_Y - m_body.getSize().y});
		m_velocity = 0;
	}
	else if (level > GROUND_Y)
	{
		m_body.setPosition({ m_body.getPosition().x, GROUND_Y - m_body.getSize().y });
		m_velocity = 0;
	}
}

//************************************************************************

void Player::updateTracking()
{
	m_mousePos = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));
	m_trackingLine[1].position = m_mousePos;
}
