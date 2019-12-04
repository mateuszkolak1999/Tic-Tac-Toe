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
	engine.game.doItOnce();
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
				STATE = engine.menu.play(window, event, Vector2f(vec));
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_MENU_SINGLEPLAYER:
				STATE = engine.menuSinglePlayer.play(window, event, Vector2f(vec));
				break;
			case STATE_GAME:
				STATE = engine.game.game(window, event, Vector2f(vec));
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_GAME_HARD:
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_GAME_MULTIPLAYER_OFFLINE:
				STATE = engine.game.gameMultiplayerOffline(window, event, Vector2f(vec));
				if (engine.menu.status)
					engine.music.musicValueQuietly();
				else
					engine.music.musicValueLoudly();
				break;
			case STATE_PAUSE:
				STATE = engine.pause.pause(window, event, Vector2f(vec));
				break;
			case STATE_WIN:
				engine.game.board.clearBoard(3, 3);
				engine.music.stopGameMusic();
				STATE = engine.end.win(window, event, Vector2f(vec));
				engine.music.playGameMusic();
				break;
			case STATE_LOSE:
				engine.game.board.clearBoard(3, 3);
				engine.music.stopGameMusic();
				STATE = engine.end.lose(window, event, Vector2f(vec));
				engine.music.playGameMusic();
				break;
			case STATE_REMIS:
				engine.game.board.clearBoard(3, 3);
				engine.music.stopGameMusic();
				STATE = engine.end.remis(window, event, Vector2f(vec));
				engine.music.playGameMusic();
				break;
		}

		window.display();
	}
}