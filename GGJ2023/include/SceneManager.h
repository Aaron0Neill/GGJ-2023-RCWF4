#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "IBaseScene.h"

#include <unordered_map>
#include <functional>
#include <memory>

enum class SceneTypes : uint8_t
{
	MAIN_MENU,
	EXAMPLE_TRANS,
	GAMEPLAY
};

using Scene = std::unique_ptr<IBaseScene>;
using SceneFactory = std::unordered_map<SceneTypes, std::function<Scene(sf::RenderWindow*)>>;

class SceneManager
{
public:
	static SceneManager* getInstance()
	{
		static SceneManager instance;
		return &instance;
	}

	SceneManager(SceneManager const&) = delete;
	void operator=(SceneManager const&) = delete;


	template<typename T>
	void registerScene(SceneTypes t_type)
	{
		m_factory[t_type] = [](sf::RenderWindow* t_window) {
			return std::make_unique<T>(t_window);
		};
	}

	void setWindow(sf::RenderWindow* t_window) { m_window = t_window; }

	void setScene(SceneTypes t_type) 
	{
		if (m_factory.count(t_type))
			m_currentScene = m_factory[t_type](m_window);
	}

	void handleEvents() { m_currentScene->handleEvents(); };

	void update(sf::Time t_dt) { m_currentScene->update(t_dt); };

	void render() { m_currentScene->render(); };

private:
	SceneManager() = default; 
	~SceneManager() = default;
	
	sf::RenderWindow* m_window;
	Scene m_currentScene;
	SceneFactory m_factory;
};

#endif