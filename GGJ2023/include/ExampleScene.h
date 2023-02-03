#ifndef EXAMPLE_SCENE_H
#define EXAMPLE_SCENE_H

#include "SceneManager.h"

class ExampleScene :
	public IBaseScene
{
public:
	ExampleScene(sf::RenderWindow* t_window);
	~ExampleScene() = default;

	void handleEvents()override;

	void update()override;

	void render()override;

private:
};

#endif