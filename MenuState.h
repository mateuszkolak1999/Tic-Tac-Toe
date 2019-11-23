#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "GameState.h"
#include "MusicClass.h"

using namespace sf;
class MenuState
{
public:
	//nazwa gry
	Texture texture_name;
	Sprite spriteName;

	//do play
	Texture texture;
	Sprite playSprite;

	//wyjscie
	Texture textureExit;
	Sprite exitButton;

	//background
	Texture textureBackground;
	Sprite background;

	void loadPlayButton();
	void loadExitButton();
	void loadBackground();
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

