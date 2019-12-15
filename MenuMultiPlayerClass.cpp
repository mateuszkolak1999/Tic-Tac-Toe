#include "MenuMultiPlayerClass.h"

int MenuMultiPlayerClass::play(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadPlayButton();
	loadExitButton();
	window.draw(background);
	window.draw(spriteName);
	window.draw(play3x3);
	window.draw(play5x5);
	window.draw(backButton);
	window.draw(exitButton);

	if (play3x3.getGlobalBounds().contains(mouse)) {
		play3x3.setTexture(texture3x3_checked);
		window.draw(play3x3);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << STATE << std::endl;
				std::cout << "Wcisnalem tryb 3x3" << std::endl;
				return STATE_GAME_MULTIPLAYER_OFFLINE;
			}
		}
	}

	if (play5x5.getGlobalBounds().contains(mouse)) {
		play5x5.setTexture(texture5x5_checked);
		window.draw(play5x5);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << STATE << std::endl;
				std::cout << "Wcisnalem tryb 5x5" << std::endl;
				return STATE_GAME_MULTIPLAYER_OFFLINE_5x5;
			}
		}
	}

	if (backButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << STATE << std::endl;
				std::cout << "Wcisnalem powrot" << std::endl;
				return STATE_MENU;
			}
		}
	}

	if (exitButton.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				window.close();
			}
		}
	}

	return STATE_MENU_MULTIPLAYER;
}

void MenuMultiPlayerClass::loadPlayButton() {
	if (!texture3x3.loadFromFile("Resources/res/3x3.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	play3x3.setTexture(texture3x3);
	play3x3.setPosition(250, 400);

	if (!texture3x3_checked.loadFromFile("Resources/res/3x3 — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!texture5x5.loadFromFile("Resources/res/5x5.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	play5x5.setTexture(texture5x5);
	play5x5.setPosition(520, 400);

	if (!texture5x5_checked.loadFromFile("Resources/res/5x5 — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;


	if (!texture_name.loadFromFile("Resources/res/Game Title.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	spriteName.setTexture(texture_name);
	spriteName.setPosition(150, 60);

	if (!textureBack.loadFromFile("Resources/res/Back Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	backButton.setTexture(textureBack);
	backButton.setPosition(100, 770);

}

void MenuMultiPlayerClass::loadExitButton() {
	if (!textureExit.loadFromFile("Resources/res/Close Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	exitButton.setTexture(textureExit);
	exitButton.setPosition(700, 750);
}

void MenuMultiPlayerClass::loadBackground() {
	if (!textureBackground.loadFromFile("Resources/res/Main_Menu_Background.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
}
