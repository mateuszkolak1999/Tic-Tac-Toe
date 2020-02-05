#include "MenuState.h"

int MenuState::play(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadPlayButton();
	loadExitButton();
	window.draw(background);
	window.draw(spriteName);
	window.draw(playSprite);
	window.draw(multiplayerButton);
	window.draw(symulacjaButton);
	window.draw(settingsButton);
	window.draw(rulesButton);
	window.draw(exitButton);

	if (playSprite.getGlobalBounds().contains(mouse)) {
		playSprite.setTexture(texture_checked);
		window.draw(playSprite);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem singleplayer" << std::endl;
				return STATE_GAME;
			}
		}
	}

	if (multiplayerButton.getGlobalBounds().contains(mouse)) {
		multiplayerButton.setTexture(multiplayerButton_checked);
		window.draw(multiplayerButton);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem gra multiplayer" << std::endl;
				return STATE_GAME_MULTIPLAYER_OFFLINE;
			}
		}
	}

	if (symulacjaButton.getGlobalBounds().contains(mouse)) {
		symulacjaButton.setTexture(symulacjaButton_checked);
		window.draw(symulacjaButton);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem symulacje" << std::endl;
				return STATE_SIMULATE;
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

	if (rulesButton.getGlobalBounds().contains(mouse)) {
		rulesButton.setTexture(textureRules_checked);
		window.draw(rulesButton);
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem zasady gry" << std::endl;
				return STATE_RULES;
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
	if (!texture.loadFromFile("Resources/res/Tryb jednoosobowy.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	playSprite.setTexture(texture);
	playSprite.setPosition(200, 300);

	if (!texture_checked.loadFromFile("Resources/res/Tryb jednoosobowy — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureMultiplayer.loadFromFile("Resources/res/Tryb wieloosobowy.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	multiplayerButton.setTexture(textureMultiplayer);
	multiplayerButton.setPosition(400, 300);

	if (!multiplayerButton_checked.loadFromFile("Resources/res/Tryb wieloosobowy — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureSymulacja.loadFromFile("Resources/res/Symulacja.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	symulacjaButton.setTexture(textureSymulacja);
	symulacjaButton.setPosition(600, 300);

	if (!symulacjaButton_checked.loadFromFile("Resources/res/Symulacja - zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureSettings.loadFromFile("Resources/res/Ustawienia.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	settingsButton.setTexture(textureSettings);
	settingsButton.setPosition(300, 500);

	if (!settingsButton_checked.loadFromFile("Resources/res/Ustawienia — zaznaczony.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureRules.loadFromFile("Resources/res/Osi¹gniêcia.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	rulesButton.setTexture(textureRules);
	rulesButton.setPosition(500, 500);

	if (!textureRules_checked.loadFromFile("Resources/res/Osi¹gniêcia — zaznaczony.png"))
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