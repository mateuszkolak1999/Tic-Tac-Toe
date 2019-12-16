#include "MenuState.h"

int MenuState::play(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadPlayButton();
	loadExitButton();
	window.draw(background);
	window.draw(spriteName);
	window.draw(playSprite);
	window.draw(multiplayerButton);
	window.draw(settingsButton);
	window.draw(achievementsButton);
	window.draw(exitButton);

	if (playSprite.getGlobalBounds().contains(mouse)) {
		playSprite.setTexture(texture_checked);
		window.draw(playSprite);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem singleplayer" << std::endl;
				return STATE_MENU_SINGLEPLAYER;
			}
		}
	}

	if (multiplayerButton.getGlobalBounds().contains(mouse)) {
		multiplayerButton.setTexture(multiplayerButton_checked);
		window.draw(multiplayerButton);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem gra multiplayer" << std::endl;
				return STATE_MENU_MULTIPLAYER;
			}
		}
	}

	if (settingsButton.getGlobalBounds().contains(mouse)) {
		settingsButton.setTexture(settingsButton_checked);
		window.draw(settingsButton);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem ustawienia" << std::endl;
				return STATE_SETTINGS;
			}
		}
	}

	if (achievementsButton.getGlobalBounds().contains(mouse)) {
		achievementsButton.setTexture(textureAchievements_checked);
		window.draw(achievementsButton);
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
	if (!texture.loadFromFile("Resources/res/Tryb jednoosobowy.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	playSprite.setTexture(texture);
	playSprite.setPosition(280, 300);

	if (!texture_checked.loadFromFile("Resources/res/Tryb jednoosobowy — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureMultiplayer.loadFromFile("Resources/res/Tryb wieloosobowy.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	multiplayerButton.setTexture(textureMultiplayer);
	multiplayerButton.setPosition(480, 400);

	if (!multiplayerButton_checked.loadFromFile("Resources/res/Tryb wieloosobowy — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureSettings.loadFromFile("Resources/res/Ustawienia.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	settingsButton.setTexture(textureSettings);
	settingsButton.setPosition(280, 500);

	if (!settingsButton_checked.loadFromFile("Resources/res/Ustawienia — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureAchievements.loadFromFile("Resources/res/Osiągnięcia.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	achievementsButton.setTexture(textureAchievements);
	achievementsButton.setPosition(480, 600);

	if (!textureAchievements_checked.loadFromFile("Resources/res/Osiągnięcia — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!texture_name.loadFromFile("Resources/res/Game Title.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	spriteName.setTexture(texture_name);
	spriteName.setPosition(150, 60);

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