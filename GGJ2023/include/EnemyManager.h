#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include "Globals.h"
#include "Enemy.h"

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();

	void spawnWave();

	void update(sf::Time t_dt);

	void render(sf::RenderWindow* t_window);

	void removeEnemy(Enemy* t_enemy);

	void testRemove();
private:
	void spawnEnemy(sf::Vector2f& t_pos, unsigned number);

	unsigned m_wave{ 1 };

	bool m_waveRunning{ false };

	std::list<Enemy*> m_enemyList;

	sf::Texture m_enemyTexture;
};