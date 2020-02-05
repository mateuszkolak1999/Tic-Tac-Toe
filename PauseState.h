#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"

using namespace sf;
class PauseState
{
private:
	Texture texture;
	Sprite close;

	Texture textureMenu;
	Sprite menu;
	
	Texture texture_background;
	Sprite background;

public:
	int pause(RenderWindow& window, Event& event, Vector2f mouse);
};

