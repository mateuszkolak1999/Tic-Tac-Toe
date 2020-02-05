#pragma once
#include "Board.h"
#include "PauseState.h"
#include "DEFINIONS.h"
#include "MusicClass.h"
#include "SettingsState.h"
#include <cstdlib>
#include <time.h>

using namespace sf;

struct Move
{
	int i, j;
};

enum class Player { HUMAN, AI };

class GameState
{
private:

	//metody
	void setTexture();
	void setTextureKolko();
	void setTextureKrzyzyk();
	void setTextureKolkoWin();
	void setTextureKrzyzykWin();
	void drawPause(RenderWindow& window);
	int pauseButton(Vector2f mouse, Event& event, int state);
	void waiting(int liczba_sekund);
	void gameload(RenderWindow& window, Event& event, int numer);
	void drawKrzyzykAndKolko(RenderWindow& window, int length, int width);
	bool AIFunction(Player player, Board& board, int length, int width);
	void playerFunction(Event& event, Vector2f mouse, int length, int width);
	void playerFunctionMultiplayer(Event& event, Vector2f mouse, int length, int width);
	bool checkWin(Player player,Board& board, int length,int width);
	bool isMovesLeft(Board& board, int length, int width);
	Move minimax(Board& board, int length, int width);
	int maxSearch(Board& board, int length, int width);
	int minSearch(Board& board, int length, int width);
	int score(Board& board, int length, int width);
	bool gameOver(Board& board, int length, int width);
	void loadBackground();
	Texture getScaledTexture(const sf::Texture& texture, Vector2f scale);
	int MINMAX2(Board& board, int length, int width, int depth, bool isMax, int alfa, int beta);
	Move findBestMove(Board& board, int length, int width);



	
	//textura pauzy
	Texture texturePause;
	Sprite pause;

	//textura kolka i krzyzyka i background
	Texture textureKolko;
	Texture textureKrzyzyk;
	Texture textureKrzyzykWin;
	Texture textureKolkoWin;
	Texture textureBackground;

	Sprite kolko;
	Sprite krzyzyk;
	Sprite kolkoWin[3];
	Sprite krzyzykWin[3];
	Sprite background;

	//zmienne do gry

	bool check_draw{ false };		//false - ruch gracza, true - ruch komputera
	bool AI_check{ false };				//komputer
	float x{ 0 };						//zmienne do rysowania krzyzyka
	float y{ 0 };

	int a{ 0 };			//zmienne do statusu na polu
	int b{ 0 };

	int x_rand{ 0 };		//zmienne do AI
	int y_rand{ 0 };

	int max{};

	MusicClass music;

	bool checker{ true };

	int player = KRZYZYK;
	int opponent = KOLKO;
	Vector2f newScaleKrzyzykAndKolko;
	float scaleKrzyzykAndKolko;

	int licznik = 0;

	int liczba_win{ 0 };
	int liczba_lose{ 0 };
	int liczba_remis{ 0 };

	bool checker_simulate{ true };
	int x_temp;
	int y_temp;


public:
	Board tablica;
	void doIt(RenderWindow& window,int numer);		//metoda pozwalajaca zainicjowac ca³¹ tablice
	void clearBoard(int length, int width);
	int getLiczba_win();
	int getLiczba_lose();
	int getLiczba_remis();
	int game(RenderWindow& window, Event& event, Vector2f mouse, int numer);
	int gameMultiplayerOffline(RenderWindow& window, Event& event, Vector2f mouse, int numer);
	int symulation(RenderWindow& window, Event& event, Vector2f mouse, int licznik_symulacji, int numer);
};

