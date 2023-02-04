#ifndef EXAMPLE_SCENE_H
#define EXAMPLE_SCENE_H

#include "SceneManager.h"
#include "EnemyManager.h"

#include "Player.h"

class ExampleScene :
	public IBaseScene
{
public:
	ExampleScene(sf::RenderWindow* t_window);
	~ExampleScene() = default;

	void handleEvents()override;

	void update(sf::Time t_dt)override;

	void render()override;

private:
	EnemyManager m_manager;
	Player m_player;
};

#endif