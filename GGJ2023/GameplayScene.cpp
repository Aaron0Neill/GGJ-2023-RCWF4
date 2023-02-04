#include "GameplayScene.h"
#include <iostream>


GameplayScene::GameplayScene(sf::RenderWindow* t_window) :
	IBaseScene(t_window), m_player(t_window)
{
	std::cout << "GameplayScene created\n";
}

void GameplayScene::handleEvents()
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

void GameplayScene::update(sf::Time t_Time)
{
	m_player.update(t_Time);
	m_manager.update(t_Time);
	collisionDetector();
}


void GameplayScene::render()
{
	m_window->clear(sf::Color(100, 100, 100, 255));
	m_manager.render(m_window);
	m_player.render(m_window);
	m_window->display();
}

void GameplayScene::collisionDetector()
{
	auto Enemies = m_manager.getEnemyList();
	auto Spells = m_player.getSpells();

	for (auto Enemy : Enemies)
	{
		for (auto Spell : Spells)
		{
			if (Enemy->getGlobalBound().intersects(Spell->getGlobalBounds()))
			{
				std::cout << "Collision Detected" << std::endl;
				Enemy->m_health -= Spell->getDmg();
			}
		}
	}

}
