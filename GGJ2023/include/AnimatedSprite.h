#pragma once

#include <SFML/Graphics.hpp>
#include <cstdint>
#include <unordered_map>

enum class AnimationStates : uint8_t
{
	IDLE,
	ATTACK, 
	RUN, 
	DIE,
	FALL
};

class AnimatedSprite : 
	public sf::Sprite
{
public:
	AnimatedSprite();
	AnimatedSprite(sf::Texture& const t_texture);

	void addRow(AnimationStates const& t_state, sf::IntRect t_startPos, uint8_t t_counter);

	void update(sf::Time t_dt);

	void setState(AnimationStates const& t_state);

	AnimationStates getState() { return m_currentState; }
private:
	float m_framedelay;
	float m_timeSinceLastUpdate;

	std::unordered_map<AnimationStates, std::vector<sf::IntRect>> m_frameMapping;

	std::vector<sf::IntRect>::iterator m_currentFrame;

	AnimationStates m_currentState;
};