#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "GameState.h"

class SettingsState
{
private:
	//nazwa gry
	Texture texture_name;
	Sprite spriteName;

	//do play
	Texture textureMusicGame;
	Sprite musicGame;
	Texture textureMusicGame_checked;

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

	bool status{ false };		//do muzyki
	bool checker{ true };

public:
	bool getStatus();
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

