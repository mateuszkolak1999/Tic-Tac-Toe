#include "Field.h"

Field::Field(int X, int Y, int marginX, int marginY) {
	this->X = X;
	this->Y = Y;
	this->marginX = marginX;
	this->marginY = marginY;

	//ustawianie pola
	field.setFillColor(Color::Transparent);
	field.setSize(Vector2f(size,size));
	field.setPosition((float)marginX + X * (size + 14),(float) marginY + Y * (size + 14));

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

void Field::setStatus(int status) {
	this->status = status;
}
