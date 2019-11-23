#pragma once
#include "DEFINIONS.h"
#include "Field.h"
class Board
{
private:
	//Field board[BOARD_LENGTH][BOARD_WIDTH];
	Texture texture;
	Sprite boardSprite;

	void setBoardSprite();

public:
	Board();
	Field board[BOARD_LENGTH_3][BOARD_WIDTH_3];
	Field* getBoard();
	void loadBoard(int length, int width);
	void clearBoard(int length, int width);
	void drawBoard(RenderWindow &window, int length, int width);
	Sprite getBoardSprite();

};

