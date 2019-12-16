#include "SettingsState.h"

int SettingsState::play(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadPlayButton();
	loadExitButton();
	window.draw(background);
	window.draw(spriteName);
	window.draw(musicGame);
	window.draw(backButton);
	window.draw(exitButton);

	if (!status) {
		musicGame.setTexture(textureMusicGame_checked);
		window.draw(musicGame);
	}

	if (status) {
		musicGame.setTexture(textureMusicGame);
		window.draw(musicGame);
	}

	if (musicGame.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (checker) {
				if (event.mouseButton.button == Mouse::Left) {
					checker = false;
					if (!status)
						status = true;
					else
						status = false;
				}
			}
		}
		else {
			checker = true;
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

	return STATE_SETTINGS;
}

void SettingsState::loadPlayButton() {
	if (!textureMusicGame.loadFromFile("Resources/res/Sound Off.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	musicGame.setTexture(textureMusicGame);
	musicGame.setPosition(380, 400);

	if (!textureMusicGame_checked.loadFromFile("Resources/res/Sound On.png"))
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

void SettingsState::loadExitButton() {
	if (!textureExit.loadFromFile("Resources/res/Close Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	exitButton.setTexture(textureExit);
	exitButton.setPosition(700, 750);
}

void SettingsState::loadBackground() {
	if (!textureBackground.loadFromFile("Resources/res/Main_Menu_Background.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
}

bool SettingsState::getStatus() {
	return status;
}