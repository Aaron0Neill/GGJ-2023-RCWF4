#pragma once
#include "SceneManager.h"
#include "EnemyManager.h"
#include "Player.h"

class GameplayScene :
	public IBaseScene
{
public:
	GameplayScene(sf::RenderWindow* t_window);
	~GameplayScene() =default;

	void handleEvents();
	void update(sf::Time t_dt)override;
	void render()override;
	void collisionDetector();
	void gameIsOver();


private:
	void setupScene();
	EnemyManager m_manager;
	Player m_player;
	sf::Texture m_floorT;
	sf::Sprite m_floorS;
	sf::Texture m_treeT;
	sf::Sprite m_treeS;
	bool done{ false };
	
};