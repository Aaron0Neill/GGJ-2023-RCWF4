#ifndef GAME_H
#define GAME_H

#include "Globals.h"
#include "mainMenu.h"
#include "ExampleTransitionScene.h"
#include "SceneManager.h"
#include "GameplayScene.h"

#include <memory.h>

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game() = default;
	~Game() = default;

	void init();

	void run();

private:
	sf::RenderWindow* m_window;
	SceneManager* m_manager;
	
};
#endif