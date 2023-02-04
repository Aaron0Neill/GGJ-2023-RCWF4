#include "ExampleTransitionScene.h"

ExampleTransitionScene::ExampleTransitionScene(sf::RenderWindow* t_window) : 
	IBaseScene(t_window)
{
	std::cout << "Example TransitionScene Created\n";
	m_manager.addSpell(SpellTypes::FIRE_BALL);
}

void ExampleTransitionScene::handleEvents()
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
				manager->setScene(SceneTypes::EXAMPLE);
				break;
			}
	}
}

void ExampleTransitionScene::update(sf::Time t_dt)
{
	m_manager.update(t_dt);
}

void ExampleTransitionScene::render()
{
	m_window->clear();

	m_window->display();
}
