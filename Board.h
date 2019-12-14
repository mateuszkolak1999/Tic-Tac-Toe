#pragma once
#include "DEFINIONS.h"
#include "Field.h"
class Board
{
private:
	//Field board[BOARD_LENGTH][BOARD_WIDTH];
	Texture texture;
	Sprite boardSprite;

	Texture textureBoard5x5;
	Sprite boardSprite5x5;

	void setBoardSprite();
	void setBoardSprite5x5();

public:
	Board();
	Field board[BOARD_LENGTH_3][BOARD_WIDTH_3];
	Field board5x5[BOARD_LENGTH_5][BOARD_WIDTH_5];
	Field* getBoard();
	Field* getBoard5x5();
	void loadBoard(int length, int width, int margin_X, int margin_Y, bool table5x5);
	void clearBoard(int length, int width, bool table5x5);
	void drawBoard(RenderWindow &window, int length, int width, bool table5x5);
	Sprite getBoardSprite();
	Sprite getBoardSprite5x5();
};

