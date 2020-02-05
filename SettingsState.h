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

	//do muzyki
	Texture textureMusicGame;
	Sprite musicGame;
	Texture textureMusicGame_checked;

	//wiekosc planszy
	Texture texturePlus;
	Texture textureMinus;
	Texture textureNapisPlansza;
	Sprite napisPlansza;
	Sprite plus;
	Sprite minus;
	Texture textureIlosc[13];
	Sprite ilosc;
	int numer { 3 };
	bool status2{ false };
	bool status3{ false };
	bool checker2{ true };
	bool checker3{ true };

	//symulacja
	Texture textureNapisSymulacja;
	Texture texturePlusSymulacja;
	Texture textureMinusSymulacja;
	Texture textureTloIloscSymulacji;
	Sprite napisSymulacja;
	Sprite plusSymulacja;
	Sprite minusSymulacja;
	Sprite tloIloscSymulacji;
	int iloscSymulacji{ 0 };
	Font fontIloscSymulacji;
	bool status4{ false };
	bool status5{ false };
	bool checker4{ true };
	bool checker5{ true };

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
	void loadTextureBoard();

	bool status{ true };		//do muzyki
	bool checker{ true };

public:
	bool getStatus();
	int getNumer();
	int getIloscSymulacji();
	int play(RenderWindow& window, Event& event, Vector2f mouse);
};

