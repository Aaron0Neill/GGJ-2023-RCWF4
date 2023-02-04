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

void Player::draw(sf::RenderTarget& const t_target, sf::RenderStates t_state) const
{
	t_target.draw(m_body);

	t_target.draw(m_trackingLine);
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
}

//************************************************************************

void Player::handleEvents(sf::Event& t_event)
{
	if (sf::Event::MouseMoved == t_event.type)
		updateTracking();

	if (sf::Event::KeyPressed == t_event.type)
		if (sf::Keyboard::Space == t_event.key.code)
			jump();
		else if (sf::Keyboard::Down == t_event.key.code)
			fall();
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
