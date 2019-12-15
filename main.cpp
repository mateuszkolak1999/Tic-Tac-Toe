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
#include"Engine.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Kolko i krzyzyk",Style::Close);
	Vector2i vec;
	Engine engine;
	STATE = STATE_MENU;
	int a=STATE_MENU;
	//engine.game.doItOnce();
	//engine.game.doItOnce5x5();
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
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++)
						std::cout << engine.game.board.board[j][i].getStatus();
					std::cout << std::endl;
				}
				std::cout << "----------------" << std::endl;
			}
		}
	
		window.clear();
		switch (STATE)
		{
			case STATE_MENU:
				engine.game.doItOnce();
				engine.game.doItOnce5x5();
				STATE = engine.menu.play(window, event, Vector2f(vec));
				a = STATE_MENU;
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_MENU_SINGLEPLAYER:
				STATE = engine.menuSinglePlayer.play(window, event, Vector2f(vec));
				a = STATE_MENU_SINGLEPLAYER;
				break;
			case STATE_MENU_MULTIPLAYER:
				STATE = engine.menuMultiPlayer.play(window, event, Vector2f(vec));
				a = STATE_MENU_MULTIPLAYER;
				break;
			case STATE_GAME:
				STATE = engine.game.game(window, event, Vector2f(vec));
				a = STATE_GAME;
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_GAME_5x5:
				STATE = engine.game.game5x5(window, event, Vector2f(vec));
				a = STATE_GAME_5x5;
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_GAME_MULTIPLAYER_OFFLINE:
				STATE = engine.game.gameMultiplayerOffline(window, event, Vector2f(vec));
				a = STATE_GAME_MULTIPLAYER_OFFLINE;
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_GAME_MULTIPLAYER_OFFLINE_5x5:
				STATE = engine.game.gameMultiplayerOffline5x5(window, event, Vector2f(vec));
				a = STATE_GAME_MULTIPLAYER_OFFLINE_5x5;
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_PAUSE:
				if (a == STATE_GAME)
					STATE = engine.pause.pause(window, event, Vector2f(vec), STATE_GAME);
				else if(a == STATE_GAME_MULTIPLAYER_OFFLINE)
					STATE = engine.pause.pause(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE);
				break;
			case STATE_WIN:
				engine.music.stopGameMusic();
				if (a == STATE_GAME) {
					engine.game.board.clearBoard(3, 3, false);
					STATE = engine.end.win(window, event, Vector2f(vec), STATE_GAME);
				}
				else if (a == STATE_GAME_5x5) {
					engine.game.board.clearBoard(5, 5, true);
					STATE = engine.end.win(window, event, Vector2f(vec), STATE_GAME_5x5);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE) {
					engine.game.board.clearBoard(3, 3, false);
					STATE = engine.end.win(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE_5x5) {
					engine.game.board.clearBoard(5, 5, true);
					STATE = engine.end.win(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE_5x5);
				}
				engine.music.playGameMusic();
				break;
			case STATE_LOSE:
				engine.music.stopGameMusic();
				if (a == STATE_GAME) {
					engine.game.board.clearBoard(3, 3, false);
					STATE = engine.end.lose(window, event, Vector2f(vec), STATE_GAME);
				}
				else if (a == STATE_GAME_5x5) {
					engine.game.board.clearBoard(5, 5, true);
					STATE = engine.end.lose(window, event, Vector2f(vec), STATE_GAME_5x5);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE) {
					engine.game.board.clearBoard(3, 3, false);
					STATE = engine.end.lose(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE_5x5) {
					engine.game.board.clearBoard(5, 5, true);
					STATE = engine.end.lose(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE_5x5);
				}
				engine.music.playGameMusic();
				break;
			case STATE_REMIS:
				engine.music.stopGameMusic();
				if (a == STATE_GAME) {
					engine.game.board.clearBoard(3, 3, false);
					STATE = engine.end.remis(window, event, Vector2f(vec), STATE_GAME);
				}
				else if (a == STATE_GAME_5x5) {
					engine.game.board.clearBoard(5, 5, true);
					STATE = engine.end.remis(window, event, Vector2f(vec), STATE_GAME_5x5);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE) {
					engine.game.board.clearBoard(3, 3, false);
					STATE = engine.end.remis(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE);
				}
				else if (a == STATE_GAME_MULTIPLAYER_OFFLINE_5x5) {
					engine.game.board.clearBoard(5, 5, true);
					STATE = engine.end.remis(window, event, Vector2f(vec), STATE_GAME_MULTIPLAYER_OFFLINE_5x5);
				}
				engine.music.playGameMusic();
				break;
		}

		window.display();
	}
}