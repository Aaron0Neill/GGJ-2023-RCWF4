#include "GameplayScene.h"
#include <iostream>


GameplayScene::GameplayScene(sf::RenderWindow* t_window) :
	IBaseScene(t_window), m_player(t_window)
{
	std::cout << "GameplayScene created\n";
	setupScene();
}

void GameplayScene::handleEvents()
{
	static sf::Event e;
	if (done)
	{
		auto manager = SceneManager::getInstance();
		manager->setScene(SceneTypes::EXAMPLE_TRANS);
		done = false;
		return;
	}
	while (m_window->pollEvent(e))
	{
		if (sf::Event::Closed == e.type)
			m_window->close();

			if (sf::Event::KeyPressed == e.type)
				if (sf::Keyboard::Escape == e.key.code)
				{
					auto manager = SceneManager::getInstance();
					manager->setScene(SceneTypes::MAIN_MENU);
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
	
	if (m_manager.checkForLoss())
		gameIsOver();

	collisionDetector();
}


void GameplayScene::render()
{
	m_window->clear(sf::Color(102, 229, 243, 255));
	m_window->draw(m_treeS);
	m_window->draw(m_floorS);
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
				if (Enemy->m_health <= 0)
				{
					m_manager.testRemove();
				}
			}
		}
	}


}

void GameplayScene::gameIsOver()
{
	done = true;
	
}

void GameplayScene::setupScene()
{
	if (!m_floorT.loadFromFile("ASSETS\\IMAGES\\Floor.png"))
	{
		std::cout << "Couldnt load floor texture" << std::endl;
	}
	m_floorS.setTexture(m_floorT);
	m_floorS.setOrigin(1000.0f, 23.5f);
	m_floorS.setPosition(sf::Vector2f(VIEW_WIDTH / 2.f, 1036.5f));

	if (!m_treeT.loadFromFile("ASSETS\\IMAGES\\TreeBranch.png"))
	{
		std::cout << "Couldnt load tree with branch texture" << std::endl;
	}
	m_treeS.setTexture(m_treeT);
	m_treeS.setScale(10.f, 10.f);
	m_treeS.setPosition(sf::Vector2f(-450.f,80.f));
}
