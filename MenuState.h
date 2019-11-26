#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "GameState.h"

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

	//volue button
	Texture textureVolumeButtonOn;
	Texture textureVolumeButtonOff;
	Sprite volumeButton;
	bool status = false;

	void loadPlayButton();
	void loadExitButton();
	void loadBackground();
	void loadVolumeButton();
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

