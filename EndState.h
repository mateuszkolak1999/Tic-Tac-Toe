#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINIONS.h"

using namespace sf;
class EndState
{
private:
	Texture retryTexture;
	Texture homeTexture;
	Texture closeTexture;
	Texture winKolkoTexture;
	Texture winKrzyzykTexture;
	Texture textureBackground;

	Sprite retryButton;
	Sprite homeButton;
	Sprite closeButton;
	Sprite winKolko;
	Sprite winKrzyzyk;
	Sprite background;

	void retryLoad(RenderWindow& window);
	void homeLoad(RenderWindow& window);
	void closeLoad(RenderWindow& window);
	void winLoadKrzyzyk(RenderWindow& window);
	void winLoadKolko(RenderWindow& window);
	void loadBackground(RenderWindow& window);
	void loadRemisGraphics(RenderWindow& window);

	int state;

public:
	int lose(RenderWindow& window, Event& event, Vector2f mouse, int state);
	int win(RenderWindow& window, Event& event, Vector2f mouse, int state);
	int remis(RenderWindow& window, Event& event, Vector2f mouse, int state);
};

