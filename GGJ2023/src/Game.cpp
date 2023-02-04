#include "Game.h"
#include <iostream>

void Game::init()
{
	m_window = new sf::RenderWindow({ WINDOW_WIDTH, WINDOW_HEIGHT }, "Scene Manager Template");
	m_window->setKeyRepeatEnabled(false);
	m_window->setView({ { VIEW_WIDTH / 2.f, VIEW_HEIGHT / 2.f },{ VIEW_WIDTH, VIEW_HEIGHT } });

	m_manager = SceneManager::getInstance();
	m_manager->setWindow(m_window);

	m_manager->registerScene<mainMenu>(SceneTypes::EXAMPLE);
	m_manager->registerScene<ExampleTransitionScene>(SceneTypes::EXAMPLE_TRANS);

	m_manager->setScene(SceneTypes::EXAMPLE);
}

void Game::run()
{

	while (m_window->isOpen())
	{ // update the active scene
		m_manager->handleEvents();
		
		m_manager->update();
		
		m_manager->render();
	}
}
