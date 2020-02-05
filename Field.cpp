#include "Field.h"

Field::Field(int X, int Y, int marginX, int marginY, int size, int odleglosc) {
	this->X = X;
	this->Y = Y;
	this->marginX = marginX;
	this->marginY = marginY;

	//ustawianie pola
	field.setFillColor(Color::Color(54, 56, 68)/*Blue*//*Transparent*/);
	field.setSize(Vector2f(size, size));
	if (!texture.loadFromFile("Resources/res/field.png"))
		std::cout << "Blad ladowania tekstury" << std::endl;

	field.setTexture(&texture);
	field.setOrigin(size, size);
	field.setPosition(size + 30 + X * (size + odleglosc), size + 30 + Y * (size + odleglosc));
}

void Field::draw(RenderTarget& target, RenderStates states) const {
	target.draw(field);
}

int Field::getX() {
	return X;
}

int Field::getY() {
	return Y;
}

int Field::getMarginX() {
	return marginX;
}

int Field::getMarginY() {
	return marginY;
}

int Field::getSize() {
	return size;
}

int Field::getStatus() {
	return status;
}

int Field::getOdleglosc() {
	return odleglosc;
}

RectangleShape Field::getField() {
	return field;
}

Texture Field::getTexture() {
	return texture;
}

void Field::setTexture(String string) {
	this->texture.loadFromFile(string);
}

void Field::setField(RectangleShape shape) {
	this->field = shape;
}

void Field::setX(int X) {
	this->X = X;
}

void Field::setY(int Y) {
	this->Y = Y;
}

void Field::setMarginX(int marginX) {
	this->marginX = marginX;
}

void Field::setMarginY(int marginY) {
	this->marginY = marginY;
}

void Field::setSize(int size) {
	this->size = size;
}

void Field::setOdleglosc(int odleglosc) {
	this->odleglosc = odleglosc;
}

void Field::setStatus(int status) {
	this->status = status;
}
