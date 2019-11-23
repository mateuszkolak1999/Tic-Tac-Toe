#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"

using namespace sf;
class Field: Drawable
{
private:
	int X;
	int Y;
	int marginX;
	int marginY;
	int size = 146;
	int status = PUSTE_POLE;		//0 - puste, 1 - kó³ko, 2 - krzy¿yk
	Texture texture;
	RectangleShape field;

public:
	Field(int X=0, int Y=0, int marginX=0, int marginY=0);
	int getX();
	int getY();
	int getMarginX();
	int getMarginY();
	int getSize();
	int getStatus();
	RectangleShape getField();
	Texture getTexture();

	void setX(int X);
	void setY(int Y);
	void setMarginX(int marginX);
	void setMarginY(int marginY);
	void setSize(int size);
	void setStatus(int status);
	void setTexture(String string);
	void setField(RectangleShape shape);
	void draw(RenderTarget& target, RenderStates states) const;

};

