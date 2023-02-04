#ifndef EXAMPLE_SCENE_H
#define EXAMPLE_SCENE_H

#include "SceneManager.h"

class mainMenu :
	public IBaseScene
{
public:
	mainMenu(sf::RenderWindow* t_window);
	~mainMenu() = default;

	void handleEvents()override;

	void update(sf::Time t_dt)override;

	void render()override;

private:
	sf::Font m_font;
	sf::Text m_startScreenText;
	sf::Text m_quitScreenText;
	sf::Text m_ConfirmLeave;
	sf::Text m_denyLeave;
	sf::Texture m_splashScreen;
	sf::Sprite m_splashScreenS;
	sf::Texture m_floorT;
	sf::Sprite m_floorS;
	sf::Texture m_exitT;
	sf::Sprite m_exitS;
	bool menuUp{ false };
	void checkMousePosition(sf::Event t_event);
	void setupText();
	void setupSprite();
};

#endif