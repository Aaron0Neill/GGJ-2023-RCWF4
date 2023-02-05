#include "ExampleTransitionScene.h"

ExampleTransitionScene::ExampleTransitionScene(sf::RenderWindow* t_window) : 
	IBaseScene(t_window)
{
	std::cout << "Example TransitionScene Created\n";

	setupSprite();
}

void ExampleTransitionScene::handleEvents()
{
	static sf::Event e;
	while (m_window->pollEvent(e))
	{
		if (sf::Event::Closed == e.type)
			m_window->close();

		if (sf::Event::KeyPressed == e.type)
			if (sf::Keyboard::Space == e.key.code)
			{
				auto manager = SceneManager::getInstance();
				manager->setScene(SceneTypes::MAIN_MENU);
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

	m_window->draw(m_floorS);
	m_window->draw(m_failS);

	m_window->display();
}

void ExampleTransitionScene::setupSprite()
{
	if (!m_floorT.loadFromFile("ASSETS\\IMAGES\\Floor.png"))
	{
		std::cout << "Couldnt load floor texture" << std::endl;
	}
	m_floorS.setTexture(m_floorT);
	m_floorS.setOrigin(1000.0f, 23.5f);
	m_floorS.setPosition(sf::Vector2f(VIEW_WIDTH / 2.f, 1036.5f));

	if (!m_failT.loadFromFile("ASSETS\\IMAGES\\Fail.png"))
	{
		std::cout << "Couldnt load fail texture" << std::endl;
	}
	m_failS.setTexture(m_failT);
	m_failS.setOrigin(400.0f, 200.0f);
	m_failS.setPosition(sf::Vector2f(VIEW_WIDTH / 2.f, 200.f));


}


