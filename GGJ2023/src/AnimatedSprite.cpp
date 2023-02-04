#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : 
	m_framedelay(0.25f)
{
}

AnimatedSprite::AnimatedSprite(sf::Texture& const t_texture) : 
	Sprite(t_texture), 
	m_framedelay(0.25)
{
}

void AnimatedSprite::addRow(AnimationStates const& t_state, sf::IntRect t_startPos, uint8_t t_counter)
{
	std::vector<sf::IntRect> frames;
	for (uint8_t i = 0; i < t_counter; ++i)
	{
		sf::IntRect frame = t_startPos;
		frame.left = t_startPos.left + frame.width * i;
		frames.push_back(frame);
	}
	m_frameMapping.emplace( t_state, frames );
}

void AnimatedSprite::update(sf::Time t_dt)
{
	m_timeSinceLastUpdate += t_dt.asSeconds();
	if (m_timeSinceLastUpdate > m_framedelay)
	{
		++m_currentFrame;
		if (m_currentFrame == m_frameMapping[m_currentState].end())
			m_currentFrame = m_frameMapping[m_currentState].begin();

		setTextureRect(*m_currentFrame);
		m_timeSinceLastUpdate = 0;

	}
}

void AnimatedSprite::setState(AnimationStates const &t_state)
{
	m_currentFrame = m_frameMapping[t_state].begin();
	m_currentState = t_state;
	setTextureRect(*m_currentFrame);
}
