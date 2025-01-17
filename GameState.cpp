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
	pause.setPosition(Vector2f(725, 50));
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

Texture GameState::getScaledTexture(const sf::Texture& texture, Vector2f scale) {
	return texture;
}

int GameState::getLiczba_win() {
	return liczba_win;
}

int GameState::getLiczba_lose() {
	return liczba_lose;
}

int GameState::getLiczba_remis() {
	return liczba_remis;
}

void GameState::gameload(RenderWindow& window, Event& event, int numer) {
	Board board(numer, numer);
	tablica = board;
	loadBackground();
	window.draw(background);
	board.boardSetTexture();
	board.drawMap(window);
	setTextureKrzyzyk();
	setTextureKolko();
	setTextureKolkoWin();
	setTextureKrzyzykWin();
	krzyzyk.setOrigin(board.getA(), board.getA());
	kolko.setOrigin(board.getA(), board.getA());
	krzyzyk.setScale(float(board.getA() / 160.0), float(board.getA() / 160.0));
	kolko.setScale(float(board.getA() / 160.0), float(board.getA() / 160.0));
	newScaleKrzyzykAndKolko = krzyzyk.getScale();
	scaleKrzyzykAndKolko = krzyzyk.getScale().x * 160;
}

void GameState::doIt(RenderWindow& window, int numer)
{
	loadBackground();
	window.draw(background);
	tablica.drawMap(window);
	setTextureKrzyzyk();
	setTextureKolko();
	setTextureKolkoWin();
	setTextureKrzyzykWin();
	krzyzyk.setOrigin(tablica.getA(), tablica.getA());
	kolko.setOrigin(tablica.getA(), tablica.getA());
}

void GameState::waiting(int liczba_sekund)
{
	clock_t a;
	a = clock() + liczba_sekund * CLOCKS_PER_SEC;
	while (clock() < a) {}
}

void GameState::clearBoard(int length, int width) {
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			tablica.getBoard()[i][j].setStatus(PUSTE_POLE);
}

void GameState::drawKrzyzykAndKolko(RenderWindow& window, int length, int width) {

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tablica.getBoard()[i][j].getStatus() == KRZYZYK)
			{
				x = tablica.getBoard()[i][j].getField().getPosition().x - (1 - newScaleKrzyzykAndKolko.x) * scaleKrzyzykAndKolko;
				y = tablica.getBoard()[i][j].getField().getPosition().y - (1 - newScaleKrzyzykAndKolko.y) * scaleKrzyzykAndKolko;
				krzyzyk.setPosition(x, y);
				window.draw(krzyzyk);
			}
			if (tablica.getBoard()[i][j].getStatus() == KOLKO)
			{
				x = tablica.getBoard()[i][j].getField().getPosition().x - (1 - newScaleKrzyzykAndKolko.x) * scaleKrzyzykAndKolko;
				y = tablica.getBoard()[i][j].getField().getPosition().y - (1 - newScaleKrzyzykAndKolko.y) * scaleKrzyzykAndKolko;
				kolko.setPosition(x, y);
				window.draw(kolko);
			}
		}
	}
}

void GameState::playerFunction(Event& event, Vector2f mouse, int length, int width) {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (tablica.getBoard()[i][j].getField().getGlobalBounds().contains(mouse)) {
				if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
					if (tablica.getBoard()[i][j].getStatus() == PUSTE_POLE) {
						a = i;
						b = j;
						tablica.getBoard()[a][b].setStatus(KRZYZYK);
						music.playKrzyzykMusic();
						AI_check = true;
					}
				}
			}
		}
	}
}

bool GameState::checkWin(Player player, Board& board, int length, int width) {
	int playerChar;
	if (player == Player::HUMAN) playerChar = KRZYZYK;
	else playerChar = KOLKO;

	if (length == 3 && width == 3) {
		for (int i = 0; i < 3; i++) {
			// Check horizontals
			if (board.getBoard()[i][0].getStatus() == playerChar && board.getBoard()[i][1].getStatus() == playerChar
				&& board.getBoard()[i][2].getStatus() == playerChar)
				return true;

			// Check verticals
			if (board.getBoard()[0][i].getStatus() == playerChar && board.getBoard()[1][i].getStatus() == playerChar
				&& board.getBoard()[2][i].getStatus() == playerChar)
				return true;
		}

		// Check diagonals
		if (board.getBoard()[0][0].getStatus() == playerChar && board.getBoard()[1][1].getStatus() == playerChar
			&& board.getBoard()[2][2].getStatus() == playerChar) {
			return true;
		}
		if (board.getBoard()[0][2].getStatus() == playerChar && board.getBoard()[1][1].getStatus() == playerChar
			&& board.getBoard()[2][0].getStatus() == playerChar) {
			return true;
		}

		return false;
	}
	else if (length == 4 && width == 4) {
		for (int i = 0; i < 4; i++) {
			// Check horizontals
			if (board.getBoard()[i][0].getStatus() == playerChar && board.getBoard()[i][1].getStatus() == playerChar
				&& board.getBoard()[i][2].getStatus() == playerChar && board.getBoard()[i][3].getStatus() == playerChar)
				return true;

			// Check verticals
			if (board.getBoard()[0][i].getStatus() == playerChar && board.getBoard()[1][i].getStatus() == playerChar
				&& board.getBoard()[2][i].getStatus() == playerChar && board.getBoard()[3][i].getStatus() == playerChar)
				return true;
		}

		// Check diagonals
		if (board.getBoard()[0][0].getStatus() == playerChar && board.getBoard()[1][1].getStatus() == playerChar
			&& board.getBoard()[2][2].getStatus() == playerChar && board.getBoard()[2][2].getStatus() == playerChar) {
			return true;
		}
		if (board.getBoard()[0][3].getStatus() == playerChar && board.getBoard()[1][2].getStatus() == playerChar
			&& board.getBoard()[2][1].getStatus() == playerChar && board.getBoard()[3][0].getStatus() == playerChar) {
			return true;
		}

		return false;
	}
	else {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < length - 4; j++) {
				// Check horizontals
				if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i][j + 1].getStatus() == playerChar
					&& board.getBoard()[i][j + 2].getStatus() == playerChar && board.getBoard()[i][j + 3].getStatus() == playerChar
					&& board.getBoard()[i][j + 4].getStatus() == playerChar)
					return true;

				// Check verticals
				if (board.getBoard()[j][i].getStatus() == playerChar && board.getBoard()[j + 1][i].getStatus() == playerChar
					&& board.getBoard()[j + 2][i].getStatus() == playerChar && board.getBoard()[j + 3][i].getStatus() == playerChar
					&& board.getBoard()[j + 4][i].getStatus() == playerChar)
					return true;
			}
		}

		for (int i = 0; i < width - 4; i++) {
			for (int j = 0; j < length - 4; j++) {
				// Check diagonals
				if (board.getBoard()[i + 4][j].getStatus() == playerChar && board.getBoard()[i + 3][j + 1].getStatus() == playerChar
					&& board.getBoard()[i + 2][j + 2].getStatus() == playerChar && board.getBoard()[i + 1][j + 3].getStatus() == playerChar
					&& board.getBoard()[i][j + 4].getStatus() == playerChar) {
					return true;
				}
				if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
					&& board.getBoard()[i + 2][j + 2].getStatus() == playerChar && board.getBoard()[i + 3][j + 3].getStatus() == playerChar
					&& board.getBoard()[i + 4][j + 4].getStatus() == playerChar) {
					return true;
				}
			}
		}
	}
	return false;
}

bool GameState::gameOver(Board& board, int length, int width) {
	if (checkWin(Player::HUMAN, board, length, width)) return true;
	else if (checkWin(Player::AI, board, length, width)) return true;

	bool emptySpace = false;
	if (length == 3 && width == 3) {
		for (int i = 0; i < length; i++) {
			if (board.getBoard()[i][0].getStatus() == PUSTE_POLE || board.getBoard()[i][1].getStatus() == PUSTE_POLE || board.getBoard()[i][2].getStatus() == PUSTE_POLE)
				emptySpace = true;
		}
		return !emptySpace;
	}
	else if (length == 4 && width == 4) {
		for (int i = 0; i < length; i++) {
			if (board.getBoard()[i][0].getStatus() == PUSTE_POLE || board.getBoard()[i][1].getStatus() == PUSTE_POLE || board.getBoard()[i][2].getStatus() == PUSTE_POLE || board.getBoard()[i][3].getStatus() == PUSTE_POLE)
				emptySpace = true;
		}
		return !emptySpace;
	}
	else {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < width; j++) {
				if (board.getBoard()[i][j].getStatus() == PUSTE_POLE)
					emptySpace = true;
			}
		}
		return !emptySpace;
	}
}

int GameState::score(Board& board, int length, int width) {
	if (checkWin(Player::HUMAN, board, length, width)) { return 10; }
	else if (checkWin(Player::AI, board, length, width)) { return -10; }
	return 0; // draw
}

bool GameState::isMovesLeft(Board& board, int length, int width) {
	for (int i = 0; i < length; i++)
		for (int j = 0; j < width; j++)
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE)
				return true;
	return false;
}

Move GameState::minimax(Board& board, int length, int width)
{
	int bestMoveScore = 100; // -100 is arbitrary
	Move bestMove;
	bestMove.i = -1;
	bestMove.j = -1;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j].setStatus(KOLKO);
				int tempMoveScore = maxSearch(board, length, width);
				if (tempMoveScore <= bestMoveScore) {
					bestMoveScore = tempMoveScore;
					bestMove.i = i;
					bestMove.j = j;
				}
				board.getBoard()[i][j].setStatus(PUSTE_POLE);
			}
		}
	}

	return bestMove;
}

int GameState::maxSearch(Board& board, int length, int width) {
	if (gameOver(board, length, width)) return score(board, length, width);
	Move bestMove;
	bestMove.i = -1;
	bestMove.j = -1;

	int bestMoveScore = -1000;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j].setStatus(KRZYZYK);
				int tempMoveScore = minSearch(board, length, width);
				if (tempMoveScore >= bestMoveScore) {
					bestMoveScore = tempMoveScore;
					bestMove.i = i;
					bestMove.j = j;
				}
				board.getBoard()[i][j].setStatus(PUSTE_POLE);
			}
		}
	}

	return bestMoveScore;
}

int GameState::minSearch(Board& board, int length, int width) {
	if (gameOver(board, length, width)) return score(board, length, width);
	Move bestMove;
	bestMove.i = -1;
	bestMove.j = -1;

	int bestMoveScore = 1000;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j].setStatus(KOLKO);
				int tempMove = maxSearch(board, length, width);
				if (tempMove <= bestMoveScore) {
					bestMoveScore = tempMove;
					bestMove.i = i;
					bestMove.j = j;
				}
				board.getBoard()[i][j].setStatus(PUSTE_POLE);
			}
		}
	}

	return bestMoveScore;
}

bool GameState::AIFunction(Player player, Board& board, int length, int width) {
	int playerChar;
	int playeropponent;
	if (player == Player::HUMAN) { playerChar = KRZYZYK; playeropponent = KOLKO; }
	else {
		playerChar = KOLKO; playeropponent = KRZYZYK;
	}

	//komputer gdy ma 4 daje znak aby wygrac
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length - 4; j++) {
			// Check horizontals
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 4].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i][j + 1].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i][j + 2].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == PUSTE_POLE
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i][j + 3].setStatus(playeropponent);
				return true;
			}

			// Check verticals
			if (board.getBoard()[j][i].getStatus() == playeropponent && board.getBoard()[j + 1][i].getStatus() == playeropponent
				&& board.getBoard()[j + 2][i].getStatus() == playeropponent && board.getBoard()[j + 3][i].getStatus() == playeropponent
				&& board.getBoard()[j + 4][i].getStatus() == PUSTE_POLE) {
				board.getBoard()[j + 4][i].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[j][i].getStatus() == PUSTE_POLE && board.getBoard()[j + 1][i].getStatus() == playeropponent
				&& board.getBoard()[j + 2][i].getStatus() == playeropponent && board.getBoard()[j + 3][i].getStatus() == playeropponent
				&& board.getBoard()[j + 4][i].getStatus() == playeropponent) {
				board.getBoard()[j][i].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[j][i].getStatus() == playeropponent && board.getBoard()[j + 1][i].getStatus() == PUSTE_POLE
				&& board.getBoard()[j + 2][i].getStatus() == playeropponent && board.getBoard()[j + 3][i].getStatus() == playeropponent
				&& board.getBoard()[j + 4][i].getStatus() == playeropponent) {
				board.getBoard()[j + 1][i].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[j][i].getStatus() == playeropponent && board.getBoard()[j + 1][i].getStatus() == playeropponent
				&& board.getBoard()[j + 2][i].getStatus() == PUSTE_POLE && board.getBoard()[j + 3][i].getStatus() == playeropponent
				&& board.getBoard()[j + 4][i].getStatus() == playeropponent) {
				board.getBoard()[j + 2][i].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[j][i].getStatus() == playeropponent && board.getBoard()[j + 1][i].getStatus() == playeropponent
				&& board.getBoard()[j + 2][i].getStatus() == playeropponent && board.getBoard()[j + 3][i].getStatus() == PUSTE_POLE
				&& board.getBoard()[j + 4][i].getStatus() == playeropponent) {
				board.getBoard()[j + 2][i].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < width - 4; i++) {
		for (int j = 0; j < length - 4; j++) {
			// Check diagonals
			if (board.getBoard()[i + 4][j].getStatus() == playeropponent && board.getBoard()[i + 3][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 1][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 4].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i + 4][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 3][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 1][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i + 4][j].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i + 4][j].getStatus() == playeropponent && board.getBoard()[i + 3][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 1][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i + 3][j + 1].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i + 4][j].getStatus() == playeropponent && board.getBoard()[i + 3][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i + 2][j + 2].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i + 4][j].getStatus() == playeropponent && board.getBoard()[i + 3][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 1][j + 3].getStatus() == PUSTE_POLE
				&& board.getBoard()[i][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i + 1][j + 3].setStatus(playeropponent);
				return true;
			}

			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i + 1][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 3][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i + 4][j + 4].getStatus() == PUSTE_POLE) {
				board.getBoard()[i + 4][j + 4].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 3][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i + 4][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i + 1][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 3][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i + 4][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i + 1][j + 1].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i + 1][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i + 3][j + 3].getStatus() == playeropponent
				&& board.getBoard()[i + 4][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i + 2][j + 2].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i + 1][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 3][j + 3].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 4][j + 4].getStatus() == playeropponent) {
				board.getBoard()[i + 3][j + 3].setStatus(playeropponent);
				return true;
			}
		}
	}

	//komputer gdy ma 3 zaznaczenia daje 4 aby dazyc do wygranej
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < length - 3; j++) {
			// Check horizontals
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 3].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i][j + 1].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i][j + 2].setStatus(playeropponent);
				return true;
			}

			// Check verticals
			if (board.getBoard()[j][i].getStatus() == playeropponent && board.getBoard()[j + 1][i].getStatus() == playeropponent
				&& board.getBoard()[j + 2][i].getStatus() == playeropponent && board.getBoard()[j + 3][i].getStatus() == PUSTE_POLE) {
				board.getBoard()[j + 3][i].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[j][i].getStatus() == PUSTE_POLE && board.getBoard()[j + 1][i].getStatus() == playeropponent
				&& board.getBoard()[j + 2][i].getStatus() == playeropponent && board.getBoard()[j + 3][i].getStatus() == playeropponent) {
				board.getBoard()[j][i].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[j][i].getStatus() == playeropponent && board.getBoard()[j + 1][i].getStatus() == PUSTE_POLE
				&& board.getBoard()[j + 2][i].getStatus() == playeropponent && board.getBoard()[j + 3][i].getStatus() == playeropponent) {
				board.getBoard()[j + 1][i].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[j][i].getStatus() == playeropponent && board.getBoard()[j + 1][i].getStatus() == playeropponent
				&& board.getBoard()[j + 2][i].getStatus() == PUSTE_POLE && board.getBoard()[j + 3][i].getStatus() == playeropponent) {
				board.getBoard()[j + 2][i].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < width - 3; i++) {
		for (int j = 0; j < length - 3; j++) {
			// Check diagonals
			if (board.getBoard()[i + 3][j].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 1].getStatus() == playeropponent && board.getBoard()[i + 1][j + 2].getStatus() == playeropponent
				&& board.getBoard()[i][j + 3].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 3].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i + 3][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 2][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 1][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i + 3][j].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i + 3][j].getStatus() == playeropponent && board.getBoard()[i + 2][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 1][j + 2].getStatus() == playeropponent && board.getBoard()[i][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i + 2][j + 1].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i + 3][j].getStatus() == playeropponent && board.getBoard()[i + 2][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 1][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i + 1][j + 2].setStatus(playeropponent);
				return true;
			}

			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i + 1][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 3][j + 3].getStatus() == PUSTE_POLE) {
				board.getBoard()[i + 3][j + 3].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 3][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i + 1][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 2][j + 2].getStatus() == playeropponent && board.getBoard()[i + 3][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i + 1][j + 1].setStatus(playeropponent);
				return true;
			}
			if (board.getBoard()[i][j].getStatus() == playeropponent && board.getBoard()[i + 1][j + 1].getStatus() == playeropponent
				&& board.getBoard()[i + 2][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i + 3][j + 3].getStatus() == playeropponent) {
				board.getBoard()[i + 2][j + 2].setStatus(playeropponent);
				return true;
			}
		}
	}

	//komputer blokuje gracza gdy ma 3 zaznaczenia
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i][j + 1].getStatus() == playerChar && board.getBoard()[i][j + 2].getStatus() == playerChar
				&& board.getBoard()[i][j + 3].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 3].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 1].getStatus() == playerChar && board.getBoard()[i][j + 2].getStatus() == playerChar
				&& board.getBoard()[i][j + 3].getStatus() == playerChar) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i][j + 1].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 2].getStatus() == playerChar
				&& board.getBoard()[i][j + 3].getStatus() == playerChar) {
				board.getBoard()[i][j + 1].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i][j + 1].getStatus() == playerChar && board.getBoard()[i][j + 2].getStatus() == PUSTE_POLE
				&& board.getBoard()[i][j + 3].getStatus() == playerChar) {
				board.getBoard()[i][j + 2].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j].getStatus() == playerChar
				&& board.getBoard()[i + 2][j].getStatus() == playerChar && board.getBoard()[i + 3][j].getStatus() == PUSTE_POLE) {
				board.getBoard()[i + 3][j].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j].getStatus() == playerChar
				&& board.getBoard()[i + 2][j].getStatus() == playerChar && board.getBoard()[i + 3][j].getStatus() == playerChar) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 2][j].getStatus() == playerChar && board.getBoard()[i + 3][j].getStatus() == playerChar) {
				board.getBoard()[i + 1][j].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j].getStatus() == playerChar
				&& board.getBoard()[i + 2][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 3][j].getStatus() == playerChar) {
				board.getBoard()[i + 2][j].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 2][j + 2].getStatus() == playerChar && board.getBoard()[i + 3][j + 3].getStatus() == PUSTE_POLE) {
				board.getBoard()[i + 3][j + 3].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 2][j + 2].getStatus() == playerChar && board.getBoard()[i + 3][j + 3].getStatus() == playerChar) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 2][j + 2].getStatus() == playerChar && board.getBoard()[i + 3][j + 3].getStatus() == playerChar) {
				board.getBoard()[i + 1][j + 1].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 2][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i + 3][j + 3].getStatus() == playerChar) {
				board.getBoard()[i + 2][j + 2].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i + 3][j].getStatus() == playerChar && board.getBoard()[i + 2][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 1][j + 2].getStatus() == playerChar && board.getBoard()[i][j + 3].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 3].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i + 3][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 2][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 1][j + 2].getStatus() == playerChar && board.getBoard()[i][j + 3].getStatus() == playerChar) {
				board.getBoard()[i + 3][j].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i + 3][j].getStatus() == playerChar && board.getBoard()[i + 2][j + 1].getStatus() == PUSTE_POLE
				&& board.getBoard()[i + 1][j + 2].getStatus() == playerChar && board.getBoard()[i][j + 3].getStatus() == playerChar) {
				board.getBoard()[i + 2][j + 1].setStatus(playeropponent);
				return true;
			}
		}
	}
	for (int i = 0; i < length - 3; i++) {
		for (int j = 0; j < width - 3; j++) {
			if (board.getBoard()[i + 3][j].getStatus() == playerChar && board.getBoard()[i + 2][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 1][j + 2].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 3].getStatus() == playerChar) {
				board.getBoard()[i + 1][j + 2].setStatus(playeropponent);
				return true;
			}
		}
	}

	//komputer blokuje gracza gdy ma 2 zaznaczenia
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i][j + 1].getStatus() == playerChar && board.getBoard()[i][j + 2].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 2].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i][j + 1].getStatus() == playerChar && board.getBoard()[i][j + 2].getStatus() == playerChar) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 2; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j].getStatus() == playerChar
				&& board.getBoard()[i + 2][j].getStatus() == PUSTE_POLE) {
				board.getBoard()[i + 2][j].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 2; i++) {
		for (int j = 0; j < width; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j].getStatus() == playerChar
				&& board.getBoard()[i + 2][j].getStatus() == playerChar) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 2; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i][j].getStatus() == playerChar && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 2][j + 2].getStatus() == PUSTE_POLE) {
				board.getBoard()[i + 2][j + 2].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 2; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
				&& board.getBoard()[i + 2][j + 2].getStatus() == playerChar) {
				board.getBoard()[i][j].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 2; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i + 2][j].getStatus() == playerChar && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
				&& board.getBoard()[i][j + 2].getStatus() == PUSTE_POLE) {
				board.getBoard()[i][j + 2].setStatus(playeropponent);
				return true;
			}
		}
	}

	for (int i = 0; i < length - 2; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (board.getBoard()[i + 2][j].getStatus() == PUSTE_POLE && board.getBoard()[i + 1][j + 1].getStatus() == playerChar
				&& board.getBoard()[i][j + 2].getStatus() == playerChar) {
				board.getBoard()[i + 2][j].setStatus(playeropponent);
				return true;
			}
		}
	}

	//komputer strzela w losowe miejsce
	while (true) {
		x_rand = rand() % length;
		y_rand = rand() % width;

		if (tablica.getBoard()[x_rand][y_rand].getStatus() == KRZYZYK || tablica.getBoard()[x_rand][y_rand].getStatus() == KOLKO)
			continue;
		else {
			tablica.getBoard()[x_rand][y_rand].setStatus(playeropponent);
			licznik++;
			break;
		}
	}
	return true;
}

void GameState::playerFunctionMultiplayer(Event& event, Vector2f mouse, int length, int width) {

	Vector2u tempSpriteSize;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (tablica.getBoard()[i][j].getField().getGlobalBounds().contains(mouse)) {
				if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
					if (tablica.getBoard()[i][j].getStatus() == PUSTE_POLE) {
						a = i;
						b = j;
						if (opponent) {
							a = i;
							b = j;
							tablica.getBoard()[a][b].setStatus(KOLKO);
							music.playKrzyzykMusic();
							opponent = false;
						}
						else {
							a = i;
							b = j;
							tablica.getBoard()[a][b].setStatus(KRZYZYK);
							music.playKrzyzykMusic();
							opponent = true;
						}
					}
				}
			}
		}
	}
}

int GameState::game(RenderWindow& window, Event& event, Vector2f mouse, int numer) {
	if (checker)
	{
		gameload(window, event, numer);
		srand(time(NULL));
		checker = false;
	}
	doIt(window, numer);
	drawKrzyzykAndKolko(window, numer, numer);
	playerFunction(event, mouse, numer, numer);
	if (checkWin(Player::HUMAN, tablica, numer, numer)) {
		checker = true;
		return STATE_WIN;
	}
	if (!isMovesLeft(tablica, numer, numer)) {
		checker = true;
		return STATE_REMIS;
	}
	if (AI_check)
	{
		if (numer == 3) {
			Move AImove = minimax(tablica, numer, numer);
			tablica.getBoard()[AImove.i][AImove.j].setStatus(KOLKO);
			if (checkWin(Player::AI, tablica, numer, numer)) {
				checker = true;
				licznik = 0;
				return STATE_LOSE;
			}
		}
		else if (numer == 4) {
			AIFunction(Player::HUMAN, tablica, numer, numer);
			if (checkWin(Player::AI, tablica, numer, numer)) {
				checker = true;
				licznik = 0;
				return STATE_LOSE;
			}
		}
		else {
			AIFunction(Player::HUMAN, tablica, numer, numer);
			if (checkWin(Player::AI, tablica, numer, numer)) {
				checker = true;
				licznik = 0;
				return STATE_LOSE;
			}
		}
		AI_check = false;
	}
	return pauseButton(mouse, event, STATE_GAME);
}

int GameState::gameMultiplayerOffline(RenderWindow& window, Event& event, Vector2f mouse, int numer) {
	if (checker)
	{
		gameload(window, event, numer);
		srand(time(NULL));
		checker = false;
	}
	doIt(window, numer);
	drawKrzyzykAndKolko(window, numer, numer);
	playerFunctionMultiplayer(event, mouse, numer, numer);
	if (checkWin(Player::HUMAN, tablica, numer, numer)) {
		checker = true;
		return STATE_WIN;
	}
	if (!isMovesLeft(tablica, numer, numer)) {
		checker = true;
		return STATE_REMIS;
	}
	if (checkWin(Player::AI, tablica, numer, numer)) {
		checker = true;
		licznik = 0;
		return STATE_LOSE;
	}
	return pauseButton(mouse, event, STATE_GAME_MULTIPLAYER_OFFLINE);
}
int GameState::symulation(RenderWindow& window, Event& event, Vector2f mouse, int licznik_symulacji, int numer) {
	srand(time(NULL));
	liczba_win = 0;
	liczba_lose = 0;
	liczba_remis = 0;
	for (int i = 0; i < licznik_symulacji; i++) {
		if (checker)
		{
			gameload(window, event, numer);
			checker = false;
			checker_simulate = true;
		}
		while (true) {
			doIt(window, numer);
			drawKrzyzykAndKolko(window, numer, numer);
			if (checkWin(Player::HUMAN, tablica, numer, numer)) {
				checker = true;
				liczba_win++;
				licznik = 0;
				break;
			}
			if (!isMovesLeft(tablica, numer, numer)) {
				checker = true;
				liczba_remis++;
				licznik = 0;
				break;
			}
			if (checkWin(Player::AI, tablica, numer, numer)) {
				checker = true;
				licznik = 0;
				liczba_lose++;
				break;
			}
			if (AI_check)
			{
				if (numer == 3) {
					Move AImove = minimax(tablica, numer, numer);
					tablica.getBoard()[AImove.i][AImove.j].setStatus(KOLKO);
				}
				else if (numer == 4) {
					AIFunction(Player::HUMAN, tablica, numer, numer);
				}
				else {
					AIFunction(Player::HUMAN, tablica, numer, numer);
				}
				AI_check = false;
			}
			else {
				if (numer == 3) {
					if (checker_simulate) {
						tablica.getBoard()[1][1].setStatus(KRZYZYK);
						checker_simulate = false;
					}
					else {
						Move AImove = minimax(tablica, numer, numer);
						tablica.getBoard()[AImove.i][AImove.j].setStatus(KRZYZYK);
						music.playKrzyzykMusic();
					}
				}
				else if (numer == 4) {
					AIFunction(Player::AI, tablica, numer, numer);
					music.playKrzyzykMusic();
				}
				else {
					AIFunction(Player::AI, tablica, numer, numer);
					music.playKrzyzykMusic();
				}
				AI_check = true;
			}
			window.display();
		}
		window.display();
	}
	return STATE_SYMULATION_RESULT;
}