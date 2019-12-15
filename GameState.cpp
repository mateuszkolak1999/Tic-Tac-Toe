#include "GameState.h"

void GameState::setTexture() {
	if (!texturePause.loadFromFile("Resources/res/Pause Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	pause.setTexture(texturePause);
}

void GameState::setTextureKolko() {
	if (!textureKolko.loadFromFile("Resources/res/O.png"))
		std::cout << "Blad ladowania struktury" << std::endl;
	kolko.setTexture(textureKolko);
}

void GameState::setTextureKrzyzyk() {
	if (!textureKrzyzyk.loadFromFile("Resources/res/X.png"))
		std::cout << "Blad ladowania struktury" << std::endl;
	krzyzyk.setTexture(textureKrzyzyk);
}

void GameState::setTextureKolkoWin() {
	if (!textureKolkoWin.loadFromFile("Resources/res/O Win.png"))
		std::cout << "Blad ladowania struktury" << std::endl;
	kolkoWin[0].setTexture(textureKolkoWin);
	kolkoWin[1].setTexture(textureKolkoWin);
	kolkoWin[2].setTexture(textureKolkoWin);
}

void GameState::setTextureKrzyzykWin() {
	if (!textureKrzyzykWin.loadFromFile("Resources/res/X Win.png"))
		std::cout << "Blad ladowania struktury" << std::endl;
	krzyzykWin[0].setTexture(textureKrzyzykWin);
	krzyzykWin[1].setTexture(textureKrzyzykWin);
	krzyzykWin[2].setTexture(textureKrzyzykWin);
}

void GameState::drawPause(RenderWindow& window) {
	setTexture();
	pause.setPosition(Vector2f(725,50));
	window.draw(pause);
}

int GameState::pauseButton(Vector2f mouse, Event& event, int state) {
	if (pause.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem pause" << std::endl;
				return STATE_PAUSE;
			}
		}
	}
	return state;
}

void GameState::loadBackground() {
	if (!textureBackground.loadFromFile("Resources/res/Main_Menu_Background.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
}

void GameState::gameload(RenderWindow& window, Event &event) {
	loadBackground();
	window.draw(background);
	board.drawBoard(window,3,3, false);
	drawPause(window);
	setTextureKrzyzyk();
	setTextureKolko();
	setTextureKolkoWin();
	setTextureKrzyzykWin();
}

void GameState::gameload5x5(RenderWindow& window, Event& event) {
	loadBackground();
	window.draw(background);
	board.drawBoard(window, 5, 5, true);
	setTextureKrzyzyk();
	setTextureKolko();
	setTextureKolkoWin();
	setTextureKrzyzykWin();
}

void GameState::doItOnce()
{
	board.loadBoard(3,3, BOARD_MARGIN_X, BOARD_MARGIN_Y, false);
}

void GameState::doItOnce5x5()
{
	board.loadBoard(5, 5, BOARD_MARGIN_X_5x5, BOARD_MARGIN_Y_5x5, true);
}

void GameState::waiting(int liczba_sekund)
{
	clock_t a;
	a = clock() + liczba_sekund * CLOCKS_PER_SEC;
	while (clock() < a) {}
}

void GameState::drawKrzyzykAndKolko(RenderWindow& window, int length, int width, bool table5x5) {

	Vector2u tempSpriteSize = krzyzyk.getTexture()->getSize();

if(!table5x5)
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board.board[i][j].getStatus() == KRZYZYK)
			{
					x = board.getBoardSprite().getPosition().x + (tempSpriteSize.x * i) - 7;
					y = board.getBoardSprite().getPosition().y + (tempSpriteSize.y * j) - 7;
					krzyzyk.setPosition(x, y);
					window.draw(krzyzyk);
			}
			if (board.board[i][j].getStatus() == KOLKO)
			{
					x = board.getBoardSprite().getPosition().x + (tempSpriteSize.x * i) - 7;
					y = board.getBoardSprite().getPosition().y + (tempSpriteSize.y * j) - 7;
					kolko.setPosition(x, y);
					window.draw(kolko);
			}
		}
	}
else
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board.board5x5[i][j].getStatus() == KRZYZYK)
			{
					x = board.getBoardSprite5x5().getPosition().x + (tempSpriteSize.x * i) - 7;
					y = board.getBoardSprite5x5().getPosition().y + (tempSpriteSize.y * j) - 7;
					krzyzyk.setPosition(x, y);
					window.draw(krzyzyk);
			}
			if (board.board5x5[i][j].getStatus() == KOLKO)
			{
					x = board.getBoardSprite5x5().getPosition().x + (tempSpriteSize.x * i) - 7;
					y = board.getBoardSprite5x5().getPosition().y + (tempSpriteSize.y * j) - 7;
					kolko.setPosition(x, y);
					window.draw(kolko);
			}
		}
	}
}

void GameState::AIFunction(int length, int width, bool table5x5) {
	srand(time(NULL));
	
	if(!table5x5)
		while(true){
			x_rand = rand() % length;
			y_rand = rand() % width;

			if (board.board[x_rand][y_rand].getStatus() == KRZYZYK || board.board[x_rand][y_rand].getStatus() == KOLKO)
				continue;
			else {
				board.board[x_rand][y_rand].setStatus(KOLKO);
				std::cout << "x: " << x_rand << " y: " << y_rand << std::endl;
				max--;
				break;
			}
		}
	else
		while (true) {
			x_rand = rand() % length;
			y_rand = rand() % width;

			if (board.board5x5[x_rand][y_rand].getStatus() == KRZYZYK || board.board5x5[x_rand][y_rand].getStatus() == KOLKO)
				continue;
			else {
				board.board5x5[x_rand][y_rand].setStatus(KOLKO);
				std::cout << "x: " << x_rand << " y: " << y_rand << std::endl;
				max5x5--;
				break;
			}
		}
}

void GameState::playerFunction(Event& event, Vector2f mouse, int length, int width, bool table5x5) {

	Vector2u tempSpriteSize = krzyzyk.getTexture()->getSize();

	if(!table5x5)
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (board.board[i][j].getField().getGlobalBounds().contains(mouse)) {
					if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
						if (board.board[i][j].getStatus() == PUSTE_POLE) {
							a = i;
							b = j;
							x = board.getBoardSprite().getPosition().x + (tempSpriteSize.x * i) - 7;
							y = board.getBoardSprite().getPosition().y + (tempSpriteSize.y * j) - 7;
							board.board[a][b].setStatus(KRZYZYK);
							krzyzyk.setPosition(x, y);
							music.playKrzyzykMusic();
							max--;
							AI = true;
						}
					}
				}
			}
		}
	else
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (board.board5x5[i][j].getField().getGlobalBounds().contains(mouse)) {
					if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
						if (board.board5x5[i][j].getStatus() == PUSTE_POLE) {
							a = i;
							b = j;
							x = board.getBoardSprite5x5().getPosition().x + (tempSpriteSize.x * i) - 7;
							y = board.getBoardSprite5x5().getPosition().y + (tempSpriteSize.y * j) - 7;
							board.board5x5[a][b].setStatus(KRZYZYK);
							krzyzyk.setPosition(x, y);
							music.playKrzyzykMusic();
							max5x5--;
							AI = true;
						}
					}
				}
			}
		}
}

void GameState::playerFunctionMultiplayer(Event& event, Vector2f mouse, int length, int width, bool table5x5) {

	Vector2u tempSpriteSize;

	if(!table5x5)
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (board.board[i][j].getField().getGlobalBounds().contains(mouse)) {
					if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
						if (board.board[i][j].getStatus() == PUSTE_POLE) {
							a = i;
							b = j;
							x = board.getBoardSprite().getPosition().x + (tempSpriteSize.x * i) - 7;
							y = board.getBoardSprite().getPosition().y + (tempSpriteSize.y * j) - 7;
							if (opponent) {
								tempSpriteSize = kolko.getTexture()->getSize();
								a = i;
								b = j;
								x = board.getBoardSprite().getPosition().x + (tempSpriteSize.x * i) - 7;
								y = board.getBoardSprite().getPosition().y + (tempSpriteSize.y * j) - 7;
								board.board[a][b].setStatus(KOLKO);
								kolko.setPosition(x, y);
								music.playKrzyzykMusic();
								opponent = false;
							}
							else {
								tempSpriteSize = krzyzyk.getTexture()->getSize();
								a = i;
								b = j;
								x = board.getBoardSprite().getPosition().x + (tempSpriteSize.x * i) - 7;
								y = board.getBoardSprite().getPosition().y + (tempSpriteSize.y * j) - 7;
								board.board[a][b].setStatus(KRZYZYK);
								krzyzyk.setPosition(x, y);
								music.playKrzyzykMusic();
								opponent = true;
							}
							max--;
						}
					}
				}
			}
		}
	else
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (board.board5x5[i][j].getField().getGlobalBounds().contains(mouse)) {
					if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
						if (board.board5x5[i][j].getStatus() == PUSTE_POLE) {
							a = i;
							b = j;
							x = board.getBoardSprite5x5().getPosition().x + (tempSpriteSize.x * i) - 7;
							y = board.getBoardSprite5x5().getPosition().y + (tempSpriteSize.y * j) - 7;
							if (opponent) {
								tempSpriteSize = kolko.getTexture()->getSize();
								a = i;
								b = j;
								x = board.getBoardSprite5x5().getPosition().x + (tempSpriteSize.x * i) - 7;
								y = board.getBoardSprite5x5().getPosition().y + (tempSpriteSize.y * j) - 7;
								board.board5x5[a][b].setStatus(KOLKO);
								kolko.setPosition(x, y);
								music.playKrzyzykMusic();
								opponent = false;
							}
							else {
								tempSpriteSize = krzyzyk.getTexture()->getSize();
								a = i;
								b = j;
								x = board.getBoardSprite5x5().getPosition().x + (tempSpriteSize.x * i) - 7;
								y = board.getBoardSprite5x5().getPosition().y + (tempSpriteSize.y * j) - 7;
								board.board5x5[a][b].setStatus(KRZYZYK);
								krzyzyk.setPosition(x, y);
								music.playKrzyzykMusic();
								opponent = true;
							}
							max5x5--;
						}
					}
				}
			}
		}
}

int GameState::checkWin(RenderWindow& window, bool table5x5) {

	if (!table5x5) {
		if (board.board[0][0].getStatus() == KRZYZYK && board.board[1][1].getStatus() == KRZYZYK && board.board[2][2].getStatus() == KRZYZYK) {
			x = board.board[0][0].getField().getPosition().x - 7;
			y = board.board[0][0].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[1][1].getField().getPosition().x - 7;
			y = board.board[1][1].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[2][2].getField().getPosition().x - 7;
			y = board.board[2][2].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[0][2].getStatus() == KRZYZYK && board.board[1][1].getStatus() == KRZYZYK && board.board[2][0].getStatus() == KRZYZYK) {
			x = board.board[0][2].getField().getPosition().x - 7;
			y = board.board[0][2].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[1][1].getField().getPosition().x - 7;
			y = board.board[1][1].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[2][0].getField().getPosition().x - 7;
			y = board.board[2][0].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[0][0].getStatus() == KRZYZYK && board.board[0][1].getStatus() == KRZYZYK && board.board[0][2].getStatus() == KRZYZYK) {
			x = board.board[0][0].getField().getPosition().x - 7;
			y = board.board[0][0].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[0][1].getField().getPosition().x - 7;
			y = board.board[0][1].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[0][2].getField().getPosition().x - 7;
			y = board.board[0][2].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[1][0].getStatus() == KRZYZYK && board.board[1][1].getStatus() == KRZYZYK && board.board[1][2].getStatus() == KRZYZYK) {
			x = board.board[1][0].getField().getPosition().x - 7;
			y = board.board[1][0].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[1][1].getField().getPosition().x - 7;
			y = board.board[1][1].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[1][2].getField().getPosition().x - 7;
			y = board.board[1][2].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[2][0].getStatus() == KRZYZYK && board.board[2][1].getStatus() == KRZYZYK && board.board[2][2].getStatus() == KRZYZYK) {
			x = board.board[2][0].getField().getPosition().x - 7;
			y = board.board[2][0].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[2][1].getField().getPosition().x - 7;
			y = board.board[2][1].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[2][2].getField().getPosition().x - 7;
			y = board.board[2][2].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[0][0].getStatus() == KRZYZYK && board.board[1][0].getStatus() == KRZYZYK && board.board[2][0].getStatus() == KRZYZYK) {
			x = board.board[0][0].getField().getPosition().x - 7;
			y = board.board[0][0].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[1][0].getField().getPosition().x - 7;
			y = board.board[1][0].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[2][0].getField().getPosition().x - 7;
			y = board.board[2][0].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[0][1].getStatus() == KRZYZYK && board.board[1][1].getStatus() == KRZYZYK && board.board[2][1].getStatus() == KRZYZYK) {
			x = board.board[0][1].getField().getPosition().x - 7;
			y = board.board[0][1].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[1][1].getField().getPosition().x - 7;
			y = board.board[1][1].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[2][1].getField().getPosition().x - 7;
			y = board.board[2][1].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[0][2].getStatus() == KRZYZYK && board.board[1][2].getStatus() == KRZYZYK && board.board[2][2].getStatus() == KRZYZYK) {
			x = board.board[0][2].getField().getPosition().x - 7;
			y = board.board[0][2].getField().getPosition().y - 7;
			krzyzykWin[0].setPosition(x, y);

			x = board.board[1][2].getField().getPosition().x - 7;
			y = board.board[1][2].getField().getPosition().y - 7;
			krzyzykWin[1].setPosition(x, y);

			x = board.board[2][2].getField().getPosition().x - 7;
			y = board.board[2][2].getField().getPosition().y - 7;
			krzyzykWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(krzyzykWin[i]);
			window.display();

			std::cout << "Wygralem" << std::endl;
			return KRZYZYK;
		}
		else if (board.board[0][0].getStatus() == KOLKO && board.board[1][1].getStatus() == KOLKO && board.board[2][2].getStatus() == KOLKO) {
			x = board.board[0][0].getField().getPosition().x - 7;
			y = board.board[0][0].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[1][1].getField().getPosition().x - 7;
			y = board.board[1][1].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[2][2].getField().getPosition().x - 7;
			y = board.board[2][2].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else if (board.board[0][2].getStatus() == KOLKO && board.board[1][1].getStatus() == KOLKO && board.board[2][0].getStatus() == KOLKO) {
			x = board.board[0][2].getField().getPosition().x - 7;
			y = board.board[0][2].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[1][1].getField().getPosition().x - 7;
			y = board.board[1][1].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[2][0].getField().getPosition().x - 7;
			y = board.board[2][0].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else if (board.board[0][0].getStatus() == KOLKO && board.board[0][1].getStatus() == KOLKO && board.board[0][2].getStatus() == KOLKO) {
			x = board.board[0][0].getField().getPosition().x - 7;
			y = board.board[0][0].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[0][1].getField().getPosition().x - 7;
			y = board.board[0][1].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[0][2].getField().getPosition().x - 7;
			y = board.board[0][2].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else if (board.board[1][0].getStatus() == KOLKO && board.board[1][1].getStatus() == KOLKO && board.board[1][2].getStatus() == KOLKO) {
			x = board.board[1][0].getField().getPosition().x - 7;
			y = board.board[1][0].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[1][1].getField().getPosition().x - 7;
			y = board.board[1][1].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[1][2].getField().getPosition().x - 7;
			y = board.board[1][2].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else if (board.board[2][0].getStatus() == KOLKO && board.board[2][1].getStatus() == KOLKO && board.board[2][2].getStatus() == KOLKO) {
			x = board.board[2][0].getField().getPosition().x - 7;
			y = board.board[2][0].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[2][1].getField().getPosition().x - 7;
			y = board.board[2][1].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[2][2].getField().getPosition().x - 7;
			y = board.board[2][2].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else if (board.board[0][0].getStatus() == KOLKO && board.board[1][0].getStatus() == KOLKO && board.board[2][0].getStatus() == KOLKO) {
			x = board.board[0][0].getField().getPosition().x - 7;
			y = board.board[0][0].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[1][0].getField().getPosition().x - 7;
			y = board.board[1][0].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[2][0].getField().getPosition().x - 7;
			y = board.board[2][0].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else if (board.board[0][2].getStatus() == KOLKO && board.board[1][2].getStatus() == KOLKO && board.board[2][2].getStatus() == KOLKO) {
			x = board.board[0][2].getField().getPosition().x - 7;
			y = board.board[0][2].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[1][2].getField().getPosition().x - 7;
			y = board.board[1][2].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[2][2].getField().getPosition().x - 7;
			y = board.board[2][2].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else if (board.board[2][0].getStatus() == KOLKO && board.board[2][1].getStatus() == KOLKO && board.board[2][2].getStatus() == KOLKO) {
			x = board.board[2][0].getField().getPosition().x - 7;
			y = board.board[2][0].getField().getPosition().y - 7;
			kolkoWin[0].setPosition(x, y);

			x = board.board[2][1].getField().getPosition().x - 7;
			y = board.board[2][1].getField().getPosition().y - 7;
			kolkoWin[1].setPosition(x, y);

			x = board.board[2][2].getField().getPosition().x - 7;
			y = board.board[2][2].getField().getPosition().y - 7;
			kolkoWin[2].setPosition(x, y);

			for (int i = 0; i < 3; i++)
				window.draw(kolkoWin[i]);
			window.display();

			std::cout << "przegralem" << std::endl;
			return KOLKO;
		}
		else {
			return PUSTE_POLE;
		}
	}
	else {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
			{
				if (board.board5x5[i][j].getStatus() == KRZYZYK && board.board5x5[i][j + 1].getStatus() == KRZYZYK && board.board5x5[i][j + 2].getStatus() == KRZYZYK) {
					x = board.board5x5[i][j].getField().getPosition().x - 6;
					y = board.board5x5[i][j].getField().getPosition().y - 6;
					krzyzykWin[0].setPosition(x, y);

					x = board.board5x5[i][j + 1].getField().getPosition().x - 6;
					y = board.board5x5[i][j + 1].getField().getPosition().y - 6;
					krzyzykWin[1].setPosition(x, y);

					x = board.board5x5[i][j + 2].getField().getPosition().x - 6;
					y = board.board5x5[i][j + 2].getField().getPosition().y - 6;
					krzyzykWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(krzyzykWin[i]);
					window.display();

					std::cout << "Wygralem" << std::endl;
					return KRZYZYK;
				}
				else if (board.board5x5[i][j].getStatus() == KRZYZYK && board.board5x5[i + 1][j].getStatus() == KRZYZYK && board.board5x5[i + 2][j].getStatus() == KRZYZYK) {
					x = board.board5x5[i][j].getField().getPosition().x - 6;
					y = board.board5x5[i][j].getField().getPosition().y - 6;
					krzyzykWin[0].setPosition(x, y);

					x = board.board5x5[i + 1][j].getField().getPosition().x - 6;
					y = board.board5x5[i + 1][j].getField().getPosition().y - 6;
					krzyzykWin[1].setPosition(x, y);

					x = board.board5x5[i + 2][j].getField().getPosition().x - 6;
					y = board.board5x5[i + 2][j].getField().getPosition().y - 6;
					krzyzykWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(krzyzykWin[i]);
					window.display();

					std::cout << "Wygralem" << std::endl;
					return KRZYZYK;
				}
				else if (board.board5x5[i][j].getStatus() == KRZYZYK && board.board5x5[i + 1][j + 1].getStatus() == KRZYZYK && board.board5x5[i + 2][j + 2].getStatus() == KRZYZYK) {
					x = board.board5x5[i][j].getField().getPosition().x - 6;
					y = board.board5x5[i][j].getField().getPosition().y - 6;
					krzyzykWin[0].setPosition(x, y);

					x = board.board5x5[i + 1][j + 1].getField().getPosition().x - 6;
					y = board.board5x5[i + 1][j + 1].getField().getPosition().y - 6;
					krzyzykWin[1].setPosition(x, y);

					x = board.board5x5[i + 2][j + 2].getField().getPosition().x - 6;
					y = board.board5x5[i + 2][j + 2].getField().getPosition().y - 6;
					krzyzykWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(krzyzykWin[i]);
					window.display();

					std::cout << "Wygralem" << std::endl;
					return KRZYZYK;
				}
				else if (board.board5x5[i + 2][j].getStatus() == KRZYZYK && board.board5x5[i + 1][j + 1].getStatus() == KRZYZYK && board.board5x5[i][j + 2].getStatus() == KRZYZYK) {
					x = board.board5x5[i + 2][j].getField().getPosition().x - 6;
					y = board.board5x5[i + 2][j].getField().getPosition().y - 6;
					krzyzykWin[0].setPosition(x, y);

					x = board.board5x5[i + 1][j + 1].getField().getPosition().x - 6;
					y = board.board5x5[i + 1][j + 1].getField().getPosition().y - 6;
					krzyzykWin[1].setPosition(x, y);

					x = board.board5x5[i][j + 2].getField().getPosition().x - 6;
					y = board.board5x5[i][j + 2].getField().getPosition().y - 6;
					krzyzykWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(krzyzykWin[i]);
					window.display();

					std::cout << "Wygralem" << std::endl;
					return KRZYZYK;
				}
				else if (board.board5x5[i][j].getStatus() == KOLKO && board.board5x5[i][j + 1].getStatus() == KOLKO && board.board5x5[i][j + 2].getStatus() == KOLKO) {
					x = board.board5x5[i][j].getField().getPosition().x - 6;
					y = board.board5x5[i][j].getField().getPosition().y - 6;
					kolkoWin[0].setPosition(x, y);

					x = board.board5x5[i][j + 1].getField().getPosition().x - 6;
					y = board.board5x5[i][j + 1].getField().getPosition().y - 6;
					kolkoWin[1].setPosition(x, y);

					x = board.board5x5[i][j + 2].getField().getPosition().x - 6;
					y = board.board5x5[i][j + 2].getField().getPosition().y - 6;
					kolkoWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(kolkoWin[i]);
					window.display();

					std::cout << "Przegralem" << std::endl;
					return KOLKO;
				}
				else if (board.board5x5[i][j].getStatus() == KOLKO && board.board5x5[i + 1][j].getStatus() == KOLKO && board.board5x5[i + 2][j].getStatus() == KOLKO) {
					x = board.board5x5[i][j].getField().getPosition().x - 6;
					y = board.board5x5[i][j].getField().getPosition().y - 6;
					kolkoWin[0].setPosition(x, y);

					x = board.board5x5[i + 1][j].getField().getPosition().x - 6;
					y = board.board5x5[i + 1][j].getField().getPosition().y - 6;
					kolkoWin[1].setPosition(x, y);

					x = board.board5x5[i + 2][j].getField().getPosition().x - 6;
					y = board.board5x5[i + 2][j].getField().getPosition().y - 6;
					kolkoWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(kolkoWin[i]);
					window.display();

					std::cout << "Przegralem" << std::endl;
					return KOLKO;
				}
				else if (board.board5x5[i][j].getStatus() == KOLKO && board.board5x5[i + 1][j + 1].getStatus() == KOLKO && board.board5x5[i + 2][j + 2].getStatus() == KOLKO) {
					x = board.board5x5[i][j].getField().getPosition().x - 6;
					y = board.board5x5[i][j].getField().getPosition().y - 6;
					kolkoWin[0].setPosition(x, y);

					x = board.board5x5[i + 1][j + 1].getField().getPosition().x - 6;
					y = board.board5x5[i + 1][j + 1].getField().getPosition().y - 6;
					kolkoWin[1].setPosition(x, y);

					x = board.board5x5[i + 2][j + 2].getField().getPosition().x - 6;
					y = board.board5x5[i + 2][j + 2].getField().getPosition().y - 6;
					kolkoWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(kolkoWin[i]);
					window.display();

					std::cout << "Przegralem" << std::endl;
					return KOLKO;
				}
				else if (board.board5x5[i + 2][j].getStatus() == KOLKO && board.board5x5[i + 1][j + 1].getStatus() == KOLKO && board.board5x5[i][j + 2].getStatus() == KOLKO) {
					x = board.board5x5[i + 2][j].getField().getPosition().x - 6;
					y = board.board5x5[i + 2][j].getField().getPosition().y - 6;
					kolkoWin[0].setPosition(x, y);

					x = board.board5x5[i + 1][j + 1].getField().getPosition().x - 6;
					y = board.board5x5[i + 1][j + 1].getField().getPosition().y - 6;
					kolkoWin[1].setPosition(x, y);

					x = board.board5x5[i][j + 2].getField().getPosition().x - 6;
					y = board.board5x5[i][j + 2].getField().getPosition().y - 6;
					kolkoWin[2].setPosition(x, y);

					for (int i = 0; i < 3; i++)
						window.draw(kolkoWin[i]);
					window.display();

					std::cout << "Przegralem" << std::endl;
					return KOLKO;
				}
			}
	}
}

int GameState::game(RenderWindow& window, Event& event, Vector2f mouse) {
		gameload(window, event);
		playerFunction(event, mouse,3,3, false);
		drawKrzyzykAndKolko(window,3,3, false);

		if (max == 0) {
			if (checkWin(window, false) == KRZYZYK) {
				std::cout << "WYGRANA" << std::endl;
				max = 9;
				music.playWinMusic();
				waiting(1);
				return STATE_WIN;
			}else if (checkWin(window, false) == KOLKO) {
				max = 9;
				std::cout << "PRZEGRANA" << std::endl;
				music.playLostMusic();
				waiting(1);
				return STATE_LOSE;
			}
			else {
				std::cout << "REMIS" << std::endl;
				max = 9;
				music.playLostMusic();
				waiting(1);
				return STATE_REMIS;
			}
		}
		else {
			if (AI)
			{
				AIFunction(3, 3, false);
				AI = false;
			}

			if (checkWin(window, false) == KRZYZYK) {
				std::cout << "WYGRANA" << std::endl;
				max = 9;
				music.playWinMusic();
				waiting(1);
				return STATE_WIN;
			}

			if (checkWin(window, false) == KOLKO) {
				max = 9;
				std::cout << "PRZEGRANA" << std::endl;
				music.playLostMusic();
				waiting(1);
				return STATE_LOSE;
			}
		}

		return pauseButton(mouse, event, STATE_GAME);
}

int GameState::game5x5(RenderWindow& window, Event& event, Vector2f mouse) {
	gameload5x5(window, event);
	playerFunction(event, mouse, 5, 5, true);
	drawKrzyzykAndKolko(window, 5, 5, true);

	if (max5x5 == 0) {
		if (checkWin(window, true) == KRZYZYK) {
			std::cout << "WYGRANA" << std::endl;
			max5x5 = 25;
			music.playWinMusic();
			waiting(1);
			return STATE_WIN;
		}
		else if (checkWin(window, true) == KOLKO) {
			max5x5 = 25;
			std::cout << "PRZEGRANA" << std::endl;
			music.playLostMusic();
			waiting(1);
			return STATE_LOSE;
		}
		else {
			std::cout << "REMIS" << std::endl;
			max5x5 = 25;
			music.playLostMusic();
			waiting(1);
			return STATE_REMIS;
		}
	}
	else {
		if (AI)
		{
			AIFunction(5, 5, true);
			AI = false;
		}

		if (checkWin(window, true) == KRZYZYK) {
			std::cout << "WYGRANA" << std::endl;
			max5x5 = 25;
			music.playWinMusic();
			waiting(1);
			return STATE_WIN;
		}

		if (checkWin(window, true) == KOLKO) {
			max5x5 = 25;
			std::cout << "PRZEGRANA" << std::endl;
			music.playLostMusic();
			waiting(1);
			return STATE_LOSE;
		}
	}
	
	return STATE_GAME_5x5;
}

int GameState::gameMultiplayerOffline(RenderWindow& window, Event& event, Vector2f mouse) {
	gameload(window, event);
	playerFunctionMultiplayer(event, mouse, 3, 3, false);
	drawKrzyzykAndKolko(window, 3, 3, false);

	if (max == 0) {
		if (checkWin(window, false) == KRZYZYK) {
			std::cout << "WYGRANA KZYZYKA" << std::endl;
			max = 9;
			music.playWinMusic();
			waiting(1);
			return STATE_WIN;
		}
		else if (checkWin(window, false) == KOLKO) {
			max = 9;
			std::cout << "WYGRANA KOLKA" << std::endl;
			music.playWinMusic();
			waiting(1);
			return STATE_LOSE;
		}
		else {
			max = 9;
			std::cout << "REMIS" << std::endl;
			music.playLostMusic();
			waiting(1);
			return STATE_REMIS;
		}
	}
	else {

		if (checkWin(window, false) == KRZYZYK) {
			std::cout << "WYGRANA KRZYZYKA" << std::endl;
			max = 9;
			music.playWinMusic();
			waiting(1);
			return STATE_WIN;
		}

		if (checkWin(window, false) == KOLKO) {
			max = 9;
			std::cout << "WYGRANA KOLKA" << std::endl;
			music.playWinMusic();
			waiting(1);
			return STATE_LOSE;
		}
	}

	return pauseButton(mouse, event,STATE_GAME_MULTIPLAYER_OFFLINE);
}

int GameState::gameMultiplayerOffline5x5(RenderWindow& window, Event& event, Vector2f mouse) {
	gameload5x5(window, event);
	playerFunctionMultiplayer(event, mouse, 5, 5, true);
	drawKrzyzykAndKolko(window, 5, 5, true);

	if (max5x5 == 0) {
		if (checkWin(window, true) == KRZYZYK) {
			std::cout << "WYGRANA KZYZYKA" << std::endl;
			max = 25;
			music.playWinMusic();
			waiting(1);
			return STATE_WIN;
		}
		else if (checkWin(window, true) == KOLKO) {
			max = 25;
			std::cout << "WYGRANA KOLKA" << std::endl;
			music.playWinMusic();
			waiting(1);
			return STATE_LOSE;
		}
		else {
			max = 25;
			std::cout << "REMIS" << std::endl;
			music.playLostMusic();
			waiting(1);
			return STATE_REMIS;
		}
	}
	else {

		if (checkWin(window, true) == KRZYZYK) {
			std::cout << "WYGRANA KRZYZYKA" << std::endl;
			max = 25;
			music.playWinMusic();
			waiting(1);
			return STATE_WIN;
		}

		if (checkWin(window, true) == KOLKO) {
			max = 25;
			std::cout << "WYGRANA KOLKA" << std::endl;
			music.playWinMusic();
			waiting(1);
			return STATE_LOSE;
		}
	}

	return pauseButton(mouse, event, STATE_GAME_MULTIPLAYER_OFFLINE_5x5);
}