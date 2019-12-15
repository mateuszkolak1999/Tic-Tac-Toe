#pragma once
#include "Board.h"
#include "PauseState.h"
#include "DEFINIONS.h"
#include "MusicClass.h"
#include <cstdlib>
#include <time.h>

using namespace sf;

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
	void gameload(RenderWindow& window, Event& event);
	void gameload5x5(RenderWindow& window, Event& event);
	void drawKrzyzykAndKolko(RenderWindow& window, int length, int width, bool table5x5);
	void AIFunction(int length, int width, bool table5x5);
	void playerFunction(Event& event, Vector2f mouse, int length, int width, bool table5x5);
	void playerFunctionMultiplayer(Event& event, Vector2f mouse, int length, int width, bool table5x5);
	int checkWin(RenderWindow& window, bool table5x5);
	void loadBackground();
	
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

	bool check_draw = false;		//false - ruch gracza, true - ruch komputera
	bool AI = false;				//komputer
	float x;						//zmienne do rysowania krzyzyka
	float y;
	bool opponent;			//false - krzyzyk, true - kolko (w grze multiplayer)

	int a;			//zmienne do statusu na polu
	int b;

	int x_rand;		//zmienne do AI
	int y_rand;

	int max = 9;		//zmienna do liczenia ile pól jest jeszcz wolnych w grze 3x3
	int max5x5 = 25;	//zmienna do liczenia ile pól jest jeszcz wolnych w grze 5x5

	MusicClass music;

public:
	Board board;			//plnsza do gry 3x3
	void doItOnce();		//metoda pozwalajaca zainicjowac ca³¹ tablice
	void doItOnce5x5();		//metoda pozwalajaca zainicjowac ca³¹ tablice
	int game(RenderWindow& window, Event& event, Vector2f mouse);
	int game5x5(RenderWindow& window, Event& event, Vector2f mouse);
	int gameMultiplayerOffline(RenderWindow& window, Event& event, Vector2f mouse);
	int gameMultiplayerOffline5x5(RenderWindow& window, Event& event, Vector2f mouse);
};

