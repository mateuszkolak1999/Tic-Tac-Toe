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

void EndState::loadText(RenderWindow& window) {
	winFont.loadFromFile("Resources/fonts/ITCKRIST.ttf");
	loseFont.loadFromFile("Resources/fonts/ITCKRIST.ttf");
	remisFont.loadFromFile("Resources/fonts/ITCKRIST.ttf");

	if (!winXSymulacjaTexture.loadFromFile("Resources/res/Wygrana X symulacja.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	winXSymulacja.setTexture(winXSymulacjaTexture);
	if (!winOSymulacjaTexture.loadFromFile("Resources/res/Wygrana O symulacja.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	winOSymulacja.setTexture(winOSymulacjaTexture);
	if (!remisSymulacjaTexture.loadFromFile("Resources/res/Remis symulacja.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	remisSymulacja.setTexture(remisSymulacjaTexture);

	winXSymulacja.setPosition(285, 150);
	winOSymulacja.setPosition(285, 300);
	remisSymulacja.setPosition(285, 450);
	window.draw(winXSymulacja);
	window.draw(winOSymulacja);
	window.draw(remisSymulacja);

	if (!retryTexture.loadFromFile("Resources/res/Retry Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	retryButton.setTexture(retryTexture);
	retryButton.setPosition(385, 700);
	window.draw(retryButton);
}


int EndState::lose(RenderWindow& window, Event& event, Vector2f mouse, int state) {
	
	loadBackground(window);
	retryLoad(window);
	homeLoad(window);
	closeLoad(window);
	winLoadKolko(window);

	if (retryButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				return state;
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

int EndState::win(RenderWindow& window, Event& event, Vector2f mouse, int state) {

	loadBackground(window);
	retryLoad(window);
	homeLoad(window);
	closeLoad(window);
	winLoadKrzyzyk(window);

	if (retryButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				return state;
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

int EndState::remis(RenderWindow& window, Event& event, Vector2f mouse, int state) {

	loadBackground(window);
	retryLoad(window);
	homeLoad(window);
	closeLoad(window);
	loadRemisGraphics(window);

	if (retryButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				return state;
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

int EndState::symulacja(RenderWindow& window, Event& event, Vector2f mouse, int win, int lose, int remis, int state) {
	loadBackground(window);
	homeLoad(window);
	closeLoad(window);
	loadText(window);
	Text winText(std::to_string(win), winFont);
	Text loseText(std::to_string(lose), loseFont);
	Text remisText(std::to_string(remis), remisFont);
	winText.setCharacterSize(70);
	loseText.setCharacterSize(70);
	remisText.setCharacterSize(70);
	winText.setFillColor(Color::White);
	loseText.setFillColor(Color::White);
	remisText.setFillColor(Color::White);
	winText.setPosition(442,205);
	loseText.setPosition(442, 355);
	remisText.setPosition(442, 505);
	window.draw(winText);
	window.draw(loseText);
	window.draw(remisText);

	if (retryButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				return state;
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

	return STATE_SYMULATION_RESULT;
}
