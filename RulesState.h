#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "GameState.h"

class RulesState
{
private:
	//nazwa gry
	Texture texture_name;
	Sprite spriteName;

	//zasady gry
	Texture textureRules;
	Sprite rules;

	//wyjscie
	Texture textureExit;
	Sprite exitButton;

	//background
	Texture textureBackground;
	Sprite background;

	//back button
	Texture textureBack;
	Sprite backButton;

	void loadRules();
	void loadTitle();
	void loadBackButton();
	void loadExitButton();
	void loadBackground();

public:
	int load(RenderWindow& window, Event& event, Vector2f mouse);
};

