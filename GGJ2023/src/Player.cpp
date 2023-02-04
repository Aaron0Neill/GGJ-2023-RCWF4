#include "Player.h"

Player::Player(sf::RenderWindow* t_window) :
	m_window(t_window), 
	m_trackingLine(sf::Lines)
{
	m_body.setSize({ 50,200 });
	m_body.setPosition({ 100, 880 });

	m_trackingLine.resize(2);
	m_trackingLine[0].position = { 125, 900 };

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
}

//************************************************************************

void Player::handleEvents(sf::Event& t_event)
{
	if (sf::Event::MouseMoved == t_event.type)
		updateTracking();
}

//************************************************************************

void Player::updateTracking()
{
	m_mousePos = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));
	m_trackingLine[1].position = m_mousePos;
}
