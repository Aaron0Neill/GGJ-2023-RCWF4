#include "ExampleScene.h"
#include <iostream>

ExampleScene::ExampleScene(sf::RenderWindow* t_window) : 
	IBaseScene(t_window)
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
	}
}

void ExampleScene::update()
{
}


void ExampleScene::render()
{
	m_window->clear(sf::Color(100, 100, 100, 255));

	m_window->display();
}
