#pragma once
#include "DEFINIONS.h"
#include "Field.h"

class Board
{
private:
	int length{ 3 };
	int width{ 3 };
	int lengthBoard{ 0 };
	int widthBoard{ 0 };
	int a{ 0 };
	int b{ 0 };
	bool check{ true };
	RectangleShape ramka;
	Field** board;
public:
	Board(int length = 3, int width = 3, int margin_X = 0, int margin_Y = 0);
	Board(Board& tablica);
	~Board();

	void clear();
	void setLength(int length);
	void setWidth(int width);
	void setLengthBoard(int lengthBoard);
	void setWidthBoard(int widthBoard);
	void setA(int a);
	void setB(int b);
	void setCheck(bool check);
	void setRamka(RectangleShape ramka);
	void setBoard(Field** board);

	int getLength();
	int getWidth();
	int getLengthBoard();
	int getWidthBoard();
	int getA();
	int getB();
	bool getCheck();
	RectangleShape getRamka();
	Field** getBoard();

	void drawMap(RenderWindow& window);
	void scaleBoard(RenderWindow& window);
	void boardSetTexture();
};

