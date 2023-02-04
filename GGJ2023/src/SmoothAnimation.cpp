#include "SmoothAnimation.h"
#include <iostream>

SmoothAnimation::SmoothAnimation()
{

}

SmoothAnimation::~SmoothAnimation()
{

}

void SmoothAnimation::assignTextureToSprite()
{
	if (!gameSpritesheet.loadFromFile("ASSETS\\IMAGES\\spritesheet.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading spritesheet" << std::endl;
	}
	Generic.setTexture(gameSpritesheet);
	Generic.setPosition(300, groundLevel - (snippetHeight + layerGapH));
}

void SmoothAnimation::filmReel()
{
	smoothTransitionCount++;

	if (smoothTransitionCount == animationRate)
	{
		animationFrameTracker++;
	}
}

void SmoothAnimation::smoothAsJazzAnimation()
{
	topLCorner = sf::Vector2i(topLSprite_x + (snippetWidth * animationFrameTracker) + layerGapW, topLSprite_y);
	SpriteSSCoords = sf::IntRect(topLCorner, spriteSize);
	Generic.setTextureRect(SpriteSSCoords);
}