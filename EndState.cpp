#include "EndState.h"

void EndState::retryLoad(RenderWindow& window) {
	if (!retryTexture.loadFromFile("Resources/res/Retry Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	retryButton.setTexture(retryTexture);
	retryButton.setPosition(385, 400);
	window.draw(retryButton);
}

void EndState::homeLoad(RenderWindow& window) {
	if (!homeTexture.loadFromFile("Resources/res/Home Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	homeButton.setTexture(homeTexture);
	homeButton.setPosition(100, 750);
	window.draw(homeButton);
}

void EndState::closeLoad(RenderWindow& window) {
	if (!closeTexture.loadFromFile("Resources/res/Close Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	closeButton.setTexture(closeTexture);
	closeButton.setPosition(700, 750);
	window.draw(closeButton);
}

void EndState::winLoadKrzyzyk(RenderWindow& window) {
	if (!winKrzyzykTexture.loadFromFile("Resources/res/X Win.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	winKrzyzyk.setTexture(winKrzyzykTexture);
	winKrzyzyk.setPosition(385, 100);
	window.draw(winKrzyzyk);
}

void EndState::winLoadKolko(RenderWindow& window) {
	if (!winKolkoTexture.loadFromFile("Resources/res/O Win.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	winKolko.setTexture(winKolkoTexture);
	winKolko.setPosition(385, 100);
	window.draw(winKolko);
}

void EndState::loadBackground(RenderWindow& window) {
	if (!textureBackground.loadFromFile("Resources/res/Main_Menu_Background.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
	window.draw(background);
}

void EndState::loadRemisGraphics(RenderWindow& window) {
	if (!winKolkoTexture.loadFromFile("Resources/res/O Win.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	winKolko.setTexture(winKolkoTexture);
	if (!winKrzyzykTexture.loadFromFile("Resources/res/X Win.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	winKrzyzyk.setTexture(winKrzyzykTexture);

	winKrzyzyk.setPosition(285, 100);
	winKolko.setPosition(485, 100);
	window.draw(winKrzyzyk);
	window.draw(winKolko);
}

int EndState::lose(RenderWindow& window, Event& event, Vector2f mouse) {
	
	loadBackground(window);
	retryLoad(window);
	homeLoad(window);
	closeLoad(window);
	winLoadKolko(window);

	if (retryButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				return STATE_GAME;
			}
		}
	}

	if (homeButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem home" << std::endl;
				return STATE_MENU;
			}
		}
	}

	if (closeButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				window.close();
			}
		}
	}

	return STATE_LOSE;
}

int EndState::win(RenderWindow& window, Event& event, Vector2f mouse) {

	loadBackground(window);
	retryLoad(window);
	homeLoad(window);
	closeLoad(window);
	winLoadKrzyzyk(window);

	if (retryButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				return STATE_GAME;
			}
		}
	}

	if (homeButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem home" << std::endl;
				return STATE_MENU;
			}
		}
	}

	if (closeButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				window.close();
			}
		}
	}

	return STATE_WIN;
}

int EndState::remis(RenderWindow& window, Event& event, Vector2f mouse) {

	loadBackground(window);
	retryLoad(window);
	homeLoad(window);
	closeLoad(window);
	loadRemisGraphics(window);

	if (retryButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				return STATE_GAME;
			}
		}
	}

	if (homeButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem home" << std::endl;
				return STATE_MENU;
			}
		}
	}

	if (closeButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				window.close();
			}
		}
	}

	return STATE_REMIS;
}
