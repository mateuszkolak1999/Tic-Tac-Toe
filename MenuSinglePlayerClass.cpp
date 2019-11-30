#include "MenuSinglePlayerClass.h"

int MenuSinglePlayerClass::play(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadPlayButton();
	loadExitButton();
	window.draw(background);
	window.draw(spriteName);
	window.draw(playEasy);
	window.draw(playHard);
	window.draw(backButton);
	window.draw(exitButton);

	if (playEasy.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << STATE << std::endl;
				std::cout << "Wcisnalem tryb easy" << std::endl;
				return STATE_GAME;
			}
		}
	}

	if (playHard.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << STATE << std::endl;
				std::cout << "Wcisnalem tryb hard" << std::endl;
				return STATE_GAME_HARD;
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

	return STATE_MENU_SINGLEPLAYER;
}

void MenuSinglePlayerClass::loadPlayButton() {
	if (!textureEasy.loadFromFile("Resources/res/Easy.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	playEasy.setTexture(textureEasy);
	playEasy.setPosition(100, 450);

	if (!textureHard.loadFromFile("Resources/res/Hard.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	playHard.setTexture(textureHard);
	playHard.setPosition(500, 450);


	if (!texture_name.loadFromFile("Resources/res/Game Title.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	spriteName.setTexture(texture_name);
	spriteName.setPosition(260, 70);

	if (!textureBack.loadFromFile("Resources/res/Back Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	backButton.setTexture(textureBack);
	backButton.setPosition(100, 770);

}

void MenuSinglePlayerClass::loadExitButton() {
	if (!textureExit.loadFromFile("Resources/res/Close Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	exitButton.setTexture(textureExit);
	exitButton.setPosition(700, 750);
}

void MenuSinglePlayerClass::loadBackground() {
	if (!textureBackground.loadFromFile("Resources/res/Main_Menu_Background.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
}
