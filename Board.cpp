#include "Board.h"

Field* Board::getBoard() {
	return *board;
}

void Board::setBoardSprite() {
	if (!texture.loadFromFile("Resources/res/Grid.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	boardSprite.setTexture(texture);
	boardSprite.setPosition(BOARD_MARGIN_X, BOARD_MARGIN_Y);
}

void Board::loadBoard(int length, int width) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			board[i][j] = Field(i, j, BOARD_MARGIN_X, BOARD_MARGIN_Y);
		}
	}
}

void Board::clearBoard(int length, int width) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			board[i][j].setStatus(PUSTE_POLE);
		}
	}
}

void Board::drawBoard(RenderWindow &window, int length, int width) {
	setBoardSprite();
	window.draw(boardSprite);
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			window.draw(board[i][j].getField());
}

Board::Board() 
{

}

Sprite Board::getBoardSprite() {
	return boardSprite;
}
