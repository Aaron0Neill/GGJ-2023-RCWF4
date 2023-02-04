#include "ExampleScene.h"
#include <iostream>

ExampleScene::ExampleScene(sf::RenderWindow* t_window) : 
	IBaseScene(t_window)
{
	std::cout << "ExampleScene created\n";

	setupText();
	setupSprite();
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
				checkMousePosition(e);
				return;
			}
		}

	}
}

void ExampleScene::update()
{
}


void ExampleScene::render()
{
	m_window->clear(sf::Color(102, 229, 243, 255));

	m_window->draw(m_startScreenText);
	m_window->draw(m_quitScreenText);
	m_window->draw(m_splashScreenS);
	m_window->draw(m_floorS);

	m_window->display();

}

void ExampleScene::checkMousePosition(sf::Event t_event)
{
	sf::Vector2f mousePos = m_window->mapPixelToCoords({ t_event.mouseButton.x, t_event.mouseButton.y });
	
	if (m_startScreenText.getGlobalBounds().contains(mousePos))
	{
		std::cout << "Change" << std::endl;
		auto manager = SceneManager::getInstance();
		manager->setScene(SceneTypes::EXAMPLE_TRANS);
	}
	else if (m_quitScreenText.getGlobalBounds().contains(mousePos))
	{
		std::cout << "Closed" << std::endl;
		m_window->close();
	}
}

void ExampleScene::setupText()
{
	if (!m_font.loadFromFile("ASSETS\\FONT\\Bangers.ttf"))
	{
		std::cout << "Error loading text" << std::endl;
	}
	m_startScreenText.setFont(m_font);
	m_startScreenText.setString("Start");
	m_startScreenText.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_startScreenText.setOrigin(100.0f, 40.0f);
	m_startScreenText.setPosition(VIEW_WIDTH / 2.f, VIEW_HEIGHT / 2.f);
	m_startScreenText.setCharacterSize(80U);
	m_startScreenText.setOutlineColor(sf::Color::Black);
	m_startScreenText.setFillColor(sf::Color::White);
	m_startScreenText.setOutlineThickness(1.0f);

	m_quitScreenText.setFont(m_font);
	m_quitScreenText.setString("Quit");
	m_quitScreenText.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_quitScreenText.setOrigin(100.0f, 40.0f);
	m_quitScreenText.setPosition(VIEW_WIDTH / 2.f, VIEW_HEIGHT / 2.f + 100.f);
	m_quitScreenText.setCharacterSize(50U);
	m_quitScreenText.setOutlineColor(sf::Color::Black);
	m_quitScreenText.setFillColor(sf::Color::White);
	m_quitScreenText.setOutlineThickness(1.0f);
}

void ExampleScene::setupSprite()
{
	if (!m_splashScreen.loadFromFile("ASSETS\\IMAGES\\SplashScreen.png"))
	{
		std::cout << "Couldnt load splashscreen" << std::endl;
	}
	m_splashScreenS.setTexture(m_splashScreen);
	m_splashScreenS.setOrigin(425.f, 200.f);
	m_splashScreenS.setPosition(sf::Vector2f(VIEW_WIDTH / 2.f, 200.f));

	if (!m_floorT.loadFromFile("ASSETS\\IMAGES\\Floor.png"))
	{
		std::cout << "Couldnt load floor texture" << std::endl;
	}
	m_floorS.setTexture(m_floorT);
	m_floorS.setOrigin(1000.0f, 23.5f);
	m_floorS.setPosition(sf::Vector2f(VIEW_WIDTH / 2.f, 1036.5f));
}
