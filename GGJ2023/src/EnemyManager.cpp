#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	if (!m_enemyTexture.loadFromFile("EnemyRun.png"))
	{
		std::cout << "ERROR LOADING ENEMY RUNNING TEXTURE\n";
	}
	if (!m_birdTexture.loadFromFile("Bird.png"))
	{
		std::cout << "The bird texture couldnt be loaded" << std::endl;
	}
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::spawnWave()
{
	std::cout << "*****\nSpawning Wave: " << m_wave << "\n*****\n";
	sf::Vector2f startPos = { 1920,GROUND_Y };
	sf::Vector2f startPosBird = { 1920,GROUND_Y - 250 };
	switch (m_wave)
	{
	case 8:
		spawnEnemy(startPos, 50);
		spawnBird(startPosBird, 50);
	case 7:
		spawnEnemy(startPos, 40);
		spawnBird(startPosBird, 40);
	case 6:
		spawnEnemy(startPos, 30);
		spawnBird(startPosBird, 30);
	case 5:
		spawnEnemy(startPos, 24);
		spawnBird(startPosBird, 24);
	case 4:
		spawnEnemy(startPos, 16);
		spawnBird(startPosBird, 16);
	case 3: 
		spawnEnemy(startPos, 4);
		spawnBird(startPosBird, 4);
	case 2: 
		spawnEnemy(startPos, 3);
		spawnBird(startPosBird, 3);
	case 1:
		spawnEnemy(startPos, 1);
		spawnBird(startPosBird, 1);
		break;
	}
	m_waveRunning = true;
}

bool EnemyManager::checkForLoss()
{
	for (Enemy* enemy : m_enemyList)
		if (enemy->isOutOfBounds())
			return true;
	return false;
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
		m_enemyList.push_back(new Enemy(m_enemyTexture, t_pos));
		t_pos.x += rand() % 100 + 51;
	}
}

void EnemyManager::spawnBird(sf::Vector2f& t_pos, unsigned number)
{
	for (int i = 0; i < number; ++i)
	{
		m_enemyList.push_back(new Enemy(m_birdTexture, t_pos));
		t_pos.x += rand() % 100 + 51;
		std::cout << "Spawned bird \n";
	}
}
