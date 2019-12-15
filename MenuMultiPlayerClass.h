#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "GameState.h"

class MenuMultiPlayerClass
{
private:
	//nazwa gry
	Texture texture_name;
	Sprite spriteName;

	//do play
	Texture texture3x3;
	Sprite play3x3;
	Texture texture5x5;
	Sprite play5x5;
	Texture texture3x3_checked;
	Texture texture5x5_checked;

	//wyjscie
	Texture textureExit;
	Sprite exitButton;

	//background
	Texture textureBackground;
	Sprite background;

	//back button
	Texture textureBack;
	Sprite backButton;

	void loadPlayButton();
	void loadExitButton();
	void loadBackground();

public:
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

