#pragma once
#include<SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "GameState.h"

using namespace sf;
class MenuState
{
private:
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

	//symulacja
	Texture textureSymulacja;
	Sprite symulacjaButton;
	Texture symulacjaButton_checked;

	//ustawienia
	Texture textureSettings;
	Sprite settingsButton;
	Texture settingsButton_checked;

	//regulamin
	Texture textureRules;
	Sprite rulesButton;
	Texture textureRules_checked;

	//wyjscie
	Texture textureExit;
	Sprite exitButton;

	//background
	Texture textureBackground;
	Sprite background;

	void loadPlayButton();
	void loadExitButton();
	void loadBackground();

public:
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

