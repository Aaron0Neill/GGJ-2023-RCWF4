#ifndef EXAMPLE_TRANSITION_SCENE_H
#define EXAMPLE_TRANSITION_SCENE_H

#include "SceneManager.h"
#include "SpellManager.h"

class ExampleTransitionScene :
	public IBaseScene
{
public:
	ExampleTransitionScene(sf::RenderWindow* t_window);
	~ExampleTransitionScene() = default;

	void handleEvents()override;

	void update(sf::Time t_dt)override;

	void render()override;

private:
	void setupSprite();
	SpellManager m_manager;
	sf::Texture m_floorT;
	sf::Sprite m_floorS;
	sf::Texture m_failT;
	sf::Sprite m_failS;
};

#endif