#ifndef IBASE_SCENE_H
#define IBASE_SCENE_H

#include <iostream>

#include <SFML/Graphics.hpp>

class IBaseScene
{
public:
	IBaseScene(sf::RenderWindow* t_window) 
		: m_window(t_window) {};

	virtual ~IBaseScene() = default;

	virtual void handleEvents() = 0;
	virtual void update(sf::Time t_dt) = 0;
	virtual void render() = 0;

protected:
	sf::RenderWindow* m_window;
};

#endif