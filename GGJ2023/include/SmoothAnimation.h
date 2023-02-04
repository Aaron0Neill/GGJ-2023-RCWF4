#pragma once
#include <SFML/Graphics.hpp>

class SmoothAnimation
{
private:
	SmoothAnimation();
	~SmoothAnimation();

public:
	//Generic Variables
	const int SCREEN_WIDTH = 1920;
	const int SCREEN_HEIGHT = 1080;
	int groundLevel = SCREEN_HEIGHT - 43;
	int spellSpeed = 0; //speed at which spell moves across screen
	int animationRate = 0; //the increment of smoothTransitionCount at which you draw the next frame of animation
	int smoothTransitionCount = 0; //passive counter/loop-timer
	int animationFrameTracker = 0; //for smoothAsJazzAnimation function
	int timeSinceSpellCast = 0; //for despawning spells
	sf::Sprite Generic;
	sf::Texture gameSpritesheet; //000 x 000 spritesheet, Width: 0snippets Height: 0snippets
	float snippetWidth; float snippetHeight;
	float layerGapW; float layerGapH;
	sf::Vector2i spriteSize = sf::Vector2i(snippetWidth, snippetHeight);
	//Top Left Corner
	int snippetGridCoord_x; int snippetGridCoord_y;
	int Start_TopLSprite_x = snippetWidth * snippetGridCoord_x; int Start_TopLSprite_y = snippetGridCoord_y;
	int topLSprite_x = Start_TopLSprite_x; int topLSprite_y = Start_TopLSprite_y;
	sf::Vector2i topLCorner = sf::Vector2i(topLSprite_x, topLSprite_y);
	//Final Coords
	sf::IntRect SpriteSSCoords = sf::IntRect(topLCorner, spriteSize);

	/// <summary>
	/// Purpose: What it says on the tin
	/// </summary>
	void assignTextureToSprite();

	/// <summary>
	/// Purpose: Tracks when things should increment
	/// </summary>
	void filmReel();

	/// <summary>
	/// Purpose: Getting and Setting Coords on spritesheet
	/// </summary>
	void smoothAsJazzAnimation();
};

