#include "Board.h"

Board::Board(int length, int width, int margin_X, int margin_Y) {
	this->length = length;
	this->width = width;
	ramka.setSize(Vector2f(800, 800));
	ramka.setFillColor(Color::Green);
	ramka.setOrigin(700, 700);
	ramka.setPosition(730, 730);

	board = new Field * [length];
	for (int i = 0; i < length; i++) {
		board[i] = new Field[length];
	}

	lengthBoard = length * board[0][0].getSize() + (length - 1) * board[0][0].getOdleglosc();


	while (check) {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (lengthBoard > ramka.getSize().x&& lengthBoard > ramka.getSize().y) {
					a = 0.95 * board[i][j].getSize();
					b = board[i][j].getOdleglosc();
					board[i][j].setSize(a);
					board[i][j].setOdleglosc(b);
					lengthBoard = length * board[0][j].getSize() + (length - 1) * board[0][j].getOdleglosc();
				}
				else
				{
					for (int i = 0; i < length; i++) {
						for (int j = 0; j < width; j++) {
							if (lengthBoard < ramka.getSize().x && lengthBoard < ramka.getSize().y) {
								a = 1.05 * board[i][j].getSize();
								b = board[i][j].getOdleglosc();
								board[i][j].setSize(a);
								board[i][j].setOdleglosc(b);
								lengthBoard = length * board[0][j].getSize() + (length - 1) * board[0][j].getOdleglosc();
							}
							else {
								check = false;
								break;
							}
						}
					}
					if (!check)
						break;
				}
			}
			if (!check)
				break;
		}
	}

	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			board[i][j] = Field(i, j, margin_X, margin_Y, a, b);
}

Board::Board(Board& tablica) {
	length = tablica.getLength();
	width = tablica.getWidth();
	lengthBoard = tablica.getLengthBoard();
	widthBoard = tablica.getWidthBoard();
	a = tablica.getA();
	b = tablica.getB();
	check = tablica.getCheck();
	ramka = tablica.getRamka();
	board = tablica.getBoard();
}

Board::~Board() {

}

void Board::clear() {
	delete[] board;
}

void Board::setLength(int length) {
	this->length = length;
}

void Board::setWidth(int width) {
	this->width = width;
}

void Board::setLengthBoard(int lengthBoard) {
	this->lengthBoard = lengthBoard;
}

void Board::setWidthBoard(int widthBoard) {
	this->widthBoard = widthBoard;
}

void Board::setA(int a) {
	this->a = a;
}

void Board::setB(int b) {
	this->b = b;
}

void Board::setCheck(bool check) {
	this->check = check;
}

void Board::setRamka(RectangleShape ramka) {
	this->ramka = ramka;
}

void Board::setBoard(Field** board) {
	this->board = board;
}

int Board::getLength() {
	return length;
}

int Board::getWidth() {
	return width;
}

int Board::getLengthBoard() {
	return lengthBoard;
}

int Board::getWidthBoard() {
	return widthBoard;
}

int Board::getA() {
	return a;
}

int Board::getB() {
	return b;
}

bool Board::getCheck() {
	return check;
}

RectangleShape Board::getRamka() {
	return ramka;
}

Field** Board::getBoard() {
	return board;
}

void Board::drawMap(RenderWindow& window) {
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++) {
			window.draw(board[i][j].getField());
		}
}

void Board::scaleBoard(RenderWindow& window) {
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			board[i][j].getField().scale(a, a);
}

void Board::boardSetTexture() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			board[i][j].setTexture("Resources/res/field.png");
			board[i][j].getField().setTexture(&board[i][j].getTexture());
		}
	}
}