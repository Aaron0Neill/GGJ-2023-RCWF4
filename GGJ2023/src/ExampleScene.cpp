#include "ExampleScene.h"
#include <iostream>

ExampleScene::ExampleScene(sf::RenderWindow* t_window) : 
	IBaseScene(t_window), 
	m_player(t_window)
{
	std::cout << "ExampleScene created\n";
}

void ExampleScene::handleEvents()
{
	static sf::Event e;
	while (m_window->pollEvent(e))
	{
		if (sf::Event::Closed == e.type)
			m_window->close();

		if (sf::Event::KeyPressed == e.type)
			if (sf::Keyboard::Num1 == e.key.code)
			{
				auto manager = SceneManager::getInstance();
				manager->setScene(SceneTypes::EXAMPLE_TRANS);
				return;
			}
			else if (sf::Keyboard::Num2 == e.key.code)
				m_manager.spawnWave();
			else if (sf::Keyboard::Num3 == e.key.code)
				m_manager.testRemove();

		m_player.handleEvents(e);
	}
}

void ExampleScene::update(sf::Time t_dt)
{
	m_player.update(t_dt);
	m_manager.update(t_dt);
}


void ExampleScene::render()
{
	m_window->clear(sf::Color(100, 100, 100, 255));

	m_manager.render(m_window);
	m_player.render(m_window);

	m_window->display();
}
