#pragma once
#include "DEFINIONS.h"
#include "GameState.h"
#include "MenuState.h"
#include "MenuSinglePlayerClass.h"
#include "PauseState.h"
#include "EndState.h"
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
	GameState game;
	PauseState pause;
	EndState end;
	MusicClass music;
};

