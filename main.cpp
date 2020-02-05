#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "DEFINIONS.h"
#include "Field.h"
#include "Board.h"
#include "GameState.h"
#include "MenuState.h"
#include "GameState.h"
#include "PauseState.h"
#include "MusicClass.h"
#include "SettingsState.h"
#include"Engine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Kolko i krzyzyk",Style::Close);
	Vector2i vec;
	Engine engine;
	STATE = STATE_MENU;
	int a=STATE_MENU;
	engine.music.playGameMusic();

	while (window.isOpen())
	{
		sf::Event event;
		vec = Mouse::getPosition(window);
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					window.close();
					break;
				}

			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::A) {
				for (int i = 0; i < engine.game.tablica.getLength(); i++) {
					for (int j = 0; j < engine.game.tablica.getWidth(); j++)
						std::cout << engine.game.tablica.getBoard()[j][i].getStatus();
					std::cout << std::endl;
				}
				std::cout << "----------------" << std::endl;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape && STATE == STATE_GAME 
				|| event.type == Event::KeyPressed && event.key.code == Keyboard::Escape && STATE == STATE_GAME_MULTIPLAYER_OFFLINE
				|| event.type == Event::KeyPressed && event.key.code == Keyboard::Escape && STATE == STATE_SIMULATE) {
				STATE = STATE_PAUSE;
				engine.game.clearBoard(engine.settings.getNumer(), engine.settings.getNumer());
			}
		}
	
		window.clear();
		switch (STATE)
		{
			case STATE_MENU:
				if (engine.settings.getStatus())
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				STATE = engine.menu.play(window, event, Vector2f(vec));
				a = STATE_MENU;
				break;
			case STATE_GAME:
				if (engine.settings.getStatus())
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				STATE = engine.game.game(window, event, Vector2f(vec), engine.settings.getNumer());
				a = STATE_GAME;
				break;
			case STATE_GAME_MULTIPLAYER_OFFLINE:
				STATE = engine.game.gameMultiplayerOffline(window, event, Vector2f(vec), engine.settings.getNumer());
				a = STATE_GAME_MULTIPLAYER_OFFLINE;
				if (engine.settings.getStatus())
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_SIMULATE:
				STATE = engine.game.symulation(window, event, Vector2f(vec), engine.settings.getIloscSymulacji(),engine.settings.getNumer());
				a = STATE_SIMULATE;
				if (engine.settings.getStatus())
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_PAUSE:
					STATE = engine.pause.pause(window, event, Vector2f(vec));
				break;
			case STATE_WIN:
				engine.music.stopGameMusic();
				if (a == STATE_GAME) {
					STATE = engine.end.win(window, event, Vector2f(vec), STATE_GAME);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE) {
					STATE = engine.end.win(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE);
				}
				engine.music.playGameMusic();
				if (engine.settings.getStatus())
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_LOSE:
				engine.music.stopGameMusic();
				if (a == STATE_GAME) {
					STATE = engine.end.lose(window, event, Vector2f(vec), STATE_GAME);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE) {
					STATE = engine.end.lose(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE);
				}
				engine.music.playGameMusic();
				break;
			case STATE_REMIS:
				engine.music.stopGameMusic();
				if (a == STATE_GAME) {
					STATE = engine.end.remis(window, event, Vector2f(vec), STATE_GAME);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE) {
					STATE = engine.end.remis(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE);
				}
				engine.music.playGameMusic();
				break;
			case STATE_SYMULATION_RESULT:
				engine.music.stopGameMusic();
				if (a == STATE_SIMULATE) {
					STATE = engine.end.symulacja(window, event, Vector2f(vec), engine.game.getLiczba_win(),engine.game.getLiczba_lose(),engine.game.getLiczba_remis(), STATE_SIMULATE);
				}
				engine.music.playGameMusic();
				break;
			case STATE_SETTINGS:
				STATE = engine.settings.play(window, event, Vector2f(vec));
				a = STATE_SETTINGS;
				if (engine.settings.getStatus())
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_RULES:
				STATE = engine.rules.load(window, event, Vector2f(vec));
				a = STATE_RULES;
				if (engine.settings.getStatus())
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
		}

		window.display();
	}
}