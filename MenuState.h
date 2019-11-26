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

	//jednoosobowy
	Texture texture;
	Sprite playSprite;

	//tryb wieloosobowy
	Texture textureMultiplayerButton;
	Sprite multiplayerButton;

	//ustawienia
	Texture textureSettingsButton;
	Sprite settingsButton;

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

