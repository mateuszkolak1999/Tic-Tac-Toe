#pragma once
#include "DEFINIONS.h"
#include "GameState.h"
#include "MenuState.h"
#include "MenuSinglePlayerClass.h"
#include "MenuMultiPlayerClass.h"
#include "PauseState.h"
#include "EndState.h"
#include "SettingsState.h"
#include "MusicClass.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
class Engine
{
public:
	MenuState menu;
	MenuSinglePlayerClass menuSinglePlayer;
	MenuMultiPlayerClass menuMultiPlayer;
	GameState game;
	PauseState pause;
	EndState end;
	SettingsState settings;
	MusicClass music;
};

