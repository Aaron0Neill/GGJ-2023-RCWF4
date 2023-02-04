#include "Game.h"
#include <iostream>

void Game::init()
{
	m_window = new sf::RenderWindow({ WINDOW_WIDTH, WINDOW_HEIGHT }, "Scene Manager Template");
	m_window->setKeyRepeatEnabled(false);
	m_window->setView({ { VIEW_WIDTH / 2.f, VIEW_HEIGHT / 2.f },{ VIEW_WIDTH, VIEW_HEIGHT } });

	m_manager = SceneManager::getInstance();
	m_manager->setWindow(m_window);

	m_manager->registerScene<ExampleScene>(SceneTypes::EXAMPLE);
	m_manager->registerScene<ExampleTransitionScene>(SceneTypes::EXAMPLE_TRANS);

	m_manager->setScene(SceneTypes::EXAMPLE);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time lag = sf::Time::Zero;
	const sf::Time MS_PER_UPDATE = sf::seconds(1 / 60.0f);

	while (m_window->isOpen())
	{
		sf::Time dT = clock.restart();
		lag += dT;

		m_manager->handleEvents();

		while (lag > MS_PER_UPDATE)
		{
			m_manager->update(MS_PER_UPDATE);
			lag -= MS_PER_UPDATE;
		}

		m_manager->update(dT);
		m_manager->render();
	}
}