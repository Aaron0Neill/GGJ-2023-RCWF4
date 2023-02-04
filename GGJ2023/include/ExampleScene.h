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
	sf::Font m_font;
	sf::Text m_startScreenText;
	sf::Text m_quitScreenText;
	void checkMousePosition(sf::Event t_event);
	void setupText();
};

#endif