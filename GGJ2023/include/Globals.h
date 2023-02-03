#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
// window is 3/4 the size of the screen
const unsigned WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width / 4.f * 3.f;
const unsigned WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height / 4.f * 3.f;

const unsigned VIEW_WIDTH = 1920U;
const unsigned VIEW_HEIGHT = 1080U;

#endif