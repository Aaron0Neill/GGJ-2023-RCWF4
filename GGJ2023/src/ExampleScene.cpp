#include "ExampleScene.h"
#include <iostream>

ExampleScene::ExampleScene(sf::RenderWindow* t_window) : 
	IBaseScene(t_window)
{
	std::cout << "ExampleScene created\n";
}

void ExampleScene::handleEvents()
{
	static sf::Event e;
	while (m_window->pollEvent(e))
	{
		if (sf::Event::Closed == e.type)
			m_window->close();

		if (sf::Event::KeyPressed == e.type)
		{
			if (sf::Keyboard::Num1 == e.key.code)
			{
				auto manager = SceneManager::getInstance();
				manager->setScene(SceneTypes::EXAMPLE_TRANS);
				return;
			}
		}
		else if (sf::Event::MouseButtonReleased == e.type)
		{
			if (sf::Mouse::Left == e.mouseButton.button)
			{
				
			}
		}

	}
}

void ExampleScene::update()
{
}


void ExampleScene::render()
{
	m_window->clear(sf::Color(100, 100, 100, 255));

	m_window->display();

	setupText();

}

void ExampleScene::checkMousePosition(sf::Event t_event)
{
	
}

void ExampleScene::setupText()
{
	if (!m_font.loadFromFile("ASSETS\\FONTS\\Bangers.ttf"))
	{
		std::cout << "Error loading text" << std::endl;
	}
	m_startScreenText.setFont(m_font);
	m_startScreenText.setString("Start");
	m_startScreenText.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_startScreenText.setPosition(65.0f, 400.0f);
	m_startScreenText.setCharacterSize(80U);
	m_startScreenText.setOutlineColor(sf::Color::Black);
	m_startScreenText.setFillColor(sf::Color::White);
	m_startScreenText.setOutlineThickness(1.0f);
}
