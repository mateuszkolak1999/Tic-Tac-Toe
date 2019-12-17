#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"

using namespace sf;
class PauseState
{
private:
	Texture texture;
	Sprite playagain;
	
	Texture texture_background;
	Sprite background;
	int state;

public:
	int pause(RenderWindow& window, Event& event, Vector2f mouse, int state);
};

