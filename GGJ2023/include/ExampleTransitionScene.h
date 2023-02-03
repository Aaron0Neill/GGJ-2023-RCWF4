#ifndef EXAMPLE_TRANSITION_SCENE_H
#define EXAMPLE_TRANSITION_SCENE_H

#include "SceneManager.h"

class ExampleTransitionScene :
	public IBaseScene
{
public:
	ExampleTransitionScene(sf::RenderWindow* t_window);
	~ExampleTransitionScene() = default;

	void handleEvents()override;

	void update()override;

	void render()override;

private:
};

#endif