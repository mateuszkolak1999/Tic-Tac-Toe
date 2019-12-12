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

	//tryb jednoosobowy
	Texture texture;
	Sprite playSprite;
	Texture texture_checked;

	//tryb wieloosobowy
	Texture textureMultiplayer;
	Sprite multiplayerButton;
	Texture multiplayerButton_checked;

	//ustawienia
	Texture textureSettings;
	Sprite settingsButton;
	Texture settingsButton_checked;

	//osi¹gniêcia
	Texture textureAchievements;
	Sprite achievementsButton;
	Texture textureAchievements_checked;

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
	bool checker = true;

	void loadPlayButton();
	void loadExitButton();
	void loadBackground();
	void loadVolumeButton();
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

