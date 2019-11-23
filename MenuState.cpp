#include "MenuState.h"

int MenuState::play(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadPlayButton();
	loadExitButton();
	window.draw(background);
	window.draw(spriteName);
	window.draw(playSprite);
	window.draw(exitButton);

	if (playSprite.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << STATE << std::endl;
				std::cout << "Wcisnalem start" << std::endl;
				return STATE_GAME;
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

	return STATE_MENU;
}

void MenuState::loadPlayButton() {
	if (!texture.loadFromFile("Resources/res/Play Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	playSprite.setTexture(texture);
	playSprite.setPosition(375, 450);


	if (!texture_name.loadFromFile("Resources/res/Game Title.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	spriteName.setTexture(texture_name);
	spriteName.setPosition(260, 70);

}

void MenuState::loadExitButton() {
	if (!textureExit.loadFromFile("Resources/res/Close Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	exitButton.setTexture(textureExit);
	exitButton.setPosition(700, 750);
}

void MenuState::loadBackground() {
	if (!textureBackground.loadFromFile("Resources/res/Main_Menu_Background.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
}