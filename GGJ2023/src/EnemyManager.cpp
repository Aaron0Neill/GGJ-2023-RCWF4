#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::spawnWave()
{
	std::cout << "*****\nSpawning Wave: " << m_wave << "\n*****\n";
	sf::Vector2f startPos = { 1920,880 };
	switch (m_wave)
	{
	case 4:
		spawnEnemy(startPos, 4);
	case 3: 
		spawnEnemy(startPos, 4);
	case 2: 
		spawnEnemy(startPos, 3);
	case 1:
		spawnEnemy(startPos, 1);
		break;
	}
	m_waveRunning = true;
}

void EnemyManager::update(sf::Time t_dt)
{
	for (Enemy* enemy : m_enemyList)
		enemy->update(t_dt);

	if (m_waveRunning && m_enemyList.size() == 0)
	{
		m_waveRunning = false;
		++m_wave;
	}
}

void EnemyManager::render(sf::RenderWindow* t_window)
{
	for (Enemy* enemy : m_enemyList)
		enemy->render(t_window);
}

void EnemyManager::removeEnemy(Enemy* t_enemy)
{
	m_enemyList.remove(t_enemy);
	delete t_enemy;
}

void EnemyManager::testRemove()
{
	if (m_enemyList.size() > 0)
	{
		Enemy* start = *m_enemyList.begin();
		m_enemyList.remove(start);
		delete start;
	}
}

void EnemyManager::spawnEnemy(sf::Vector2f& t_pos, unsigned number)
{
	for (int i = 0; i < number; ++i)
	{
		m_enemyList.push_back(new Enemy(t_pos));
		t_pos.x += rand() % 100 + 51;
	}
}
