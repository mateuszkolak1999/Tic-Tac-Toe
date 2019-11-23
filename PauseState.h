#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"

using namespace sf;
class PauseState
{
public:
	Texture texture;
	Sprite playagain;
	
	Texture texture_background;
	Sprite background;

	int pause(RenderWindow& window, Event& event, Vector2f mouse);
};

