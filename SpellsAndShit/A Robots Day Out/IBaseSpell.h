#pragma once
#include <SFML/Graphics.hpp>

/// <summary>
/// Purpose: A Base Class for Spells, that inherits from other set spells
/// </summary>
class IBaseSpell
{
public:
	IBaseSpell();
	~IBaseSpell();

private:
	//Functions
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void getDmg() = 0;
};