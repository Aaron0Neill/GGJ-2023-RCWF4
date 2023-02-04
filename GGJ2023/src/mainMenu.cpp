#include "mainMenu.h"
#include <iostream>

mainMenu::mainMenu(sf::RenderWindow* t_window) : 
	IBaseScene(t_window)
{
	std::cout << "mainMenu created\n";

	setupText();
	setupSprite();
}

void mainMenu::handleEvents()
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
				manager->setScene(SceneTypes::GAMEPLAY);
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

void mainMenu::update(sf::Time t_dt)
{
}


void mainMenu::render()
{
	m_window->clear(sf::Color(102, 229, 243, 255));

	
	m_window->draw(m_splashScreenS);
	m_window->draw(m_floorS);

	if (menuUp)
	{
		m_window->draw(m_exitS);
		m_window->draw(m_ConfirmLeave);
		m_window->draw(m_denyLeave);
	}
	else
	{
		m_window->draw(m_startScreenText);
		m_window->draw(m_quitScreenText);
	}

	m_window->display();

}

void mainMenu::checkMousePosition(sf::Event t_event)
{
	sf::Vector2f mousePos = m_window->mapPixelToCoords({ t_event.mouseButton.x, t_event.mouseButton.y });
	
	if (m_ConfirmLeave.getGlobalBounds().contains(mousePos) && menuUp)
	{
		m_window->close();
	}
	else if (m_denyLeave.getGlobalBounds().contains(mousePos) && menuUp)
	{
		menuUp = false;
	}
	else if (m_startScreenText.getGlobalBounds().contains(mousePos))
	{
		std::cout << "Change" << std::endl;
		auto manager = SceneManager::getInstance();
		manager->setScene(SceneTypes::MAIN_MENU);
	}
	else if (m_quitScreenText.getGlobalBounds().contains(mousePos))
	{
		std::cout << "Closed" << std::endl;
		menuUp = true;
	}
}

void mainMenu::setupText()
{
	if (!m_font.loadFromFile("ASSETS\\FONT\\Bangers.ttf"))
	{
		std::cout << "Error loading text" << std::endl;
	}
	m_ConfirmLeave.setFont(m_font);
	m_ConfirmLeave.setString("Yes");
	m_ConfirmLeave.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_ConfirmLeave.setOrigin(100.0f, 40.0f);
	m_ConfirmLeave.setPosition(VIEW_WIDTH / 2.f - 10.f, VIEW_HEIGHT / 2.f + 85.f);
	m_ConfirmLeave.setCharacterSize(15U);
	m_ConfirmLeave.setOutlineColor(sf::Color::Black);
	m_ConfirmLeave.setFillColor(sf::Color::White);
	m_ConfirmLeave.setOutlineThickness(1.0f);

	m_denyLeave.setFont(m_font);
	m_denyLeave.setString("No");
	m_denyLeave.setStyle(sf::Text::Italic | sf::Text::Bold);
	m_denyLeave.setOrigin(100.0f, 40.0f);
	m_denyLeave.setPosition(VIEW_WIDTH / 2.f + 120.f, VIEW_HEIGHT / 2.f + 15.f);
	m_denyLeave.setCharacterSize(100U);
	m_denyLeave.setOutlineColor(sf::Color::Black);
	m_denyLeave.setFillColor(sf::Color::White);
	m_denyLeave.setOutlineThickness(1.0f);

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

void mainMenu::setupSprite()
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

	if (!m_exitT.loadFromFile("ASSETS\\IMAGES\\ExitConfirm.png"))
	{
		std::cout << "Couldnt load exit confirm" << std::endl;
	}
	m_exitS.setTexture(m_exitT);
	m_exitS.setOrigin(200.f, 200.f);
	m_exitS.setPosition(sf::Vector2f(VIEW_WIDTH / 2.f, VIEW_HEIGHT / 2.f));
}
