#include "Board.h"

Field* Board::getBoard() {
	return *board;
}

Field* Board::getBoard5x5() {
	return *board5x5;
}

void Board::setBoardSprite() {
	if (!texture.loadFromFile("Resources/res/Grid.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	boardSprite.setTexture(texture);
	boardSprite.setPosition(BOARD_MARGIN_X, BOARD_MARGIN_Y);
}

void Board::setBoardSprite5x5() {
	if (!textureBoard5x5.loadFromFile("Resources/res/Grid5x5.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	boardSprite5x5.setTexture(textureBoard5x5);
	boardSprite5x5.setPosition(BOARD_MARGIN_X_5x5, BOARD_MARGIN_Y_5x5);
}

void Board::loadBoard(int length, int width, int margin_X, int margin_Y, bool table5x5) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (!table5x5)
				board[i][j] = Field(i, j, margin_X, margin_Y);
			else
				board5x5[i][j] = Field(i, j, margin_X, margin_Y);
		}
	}
}

void Board::clearBoard(int length, int width, bool table5x5) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (!table5x5)
				board[i][j].setStatus(PUSTE_POLE);
			else
				board5x5[i][j].setStatus(PUSTE_POLE);
		}
	}
}

void Board::drawBoard(RenderWindow &window, int length, int width, bool table5x5) {

	if (!table5x5) {
		setBoardSprite();
		window.draw(boardSprite);
	}
	else {
		setBoardSprite5x5();
		window.draw(boardSprite5x5);
	}

	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++) {
			if (!table5x5)
				window.draw(board[i][j].getField());
			else
				window.draw(board5x5[i][j].getField());
		}
			
}

Board::Board() 
{

}

Sprite Board::getBoardSprite() {
	return boardSprite;
}

Sprite Board::getBoardSprite5x5() {
	return boardSprite5x5;
}
