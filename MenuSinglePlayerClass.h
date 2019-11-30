#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "GameState.h"

class MenuSinglePlayerClass
{
public:
	//nazwa gry
	Texture texture_name;
	Sprite spriteName;

	//do play
	Texture textureEasy;
	Sprite playEasy;
	Texture textureHard;
	Sprite playHard;

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
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

