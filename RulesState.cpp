#include "RulesState.h"

int RulesState::load(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadRules();
	loadBackButton();
	loadTitle();
	loadExitButton();
	window.draw(background);
	window.draw(spriteName);
	window.draw(rules);
	window.draw(backButton);
	window.draw(exitButton);

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

	return STATE_RULES;
}

void RulesState::loadRules() {
	if (!textureRules.loadFromFile("Resources/res/Zasady gry.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	rules.setTexture(textureRules);
	rules.setPosition(160, 300);
}

void RulesState::loadTitle() {
	if (!texture_name.loadFromFile("Resources/res/Game Title.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	spriteName.setTexture(texture_name);
	spriteName.setPosition(150, 60);
}

void RulesState::loadBackButton() {
	if (!textureBack.loadFromFile("Resources/res/Back Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	backButton.setTexture(textureBack);
	backButton.setPosition(100, 770);
}

void RulesState::loadExitButton() {
	if (!textureExit.loadFromFile("Resources/res/Close Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	exitButton.setTexture(textureExit);
	exitButton.setPosition(700, 750);
}

void RulesState::loadBackground() {
	if (!textureBackground.loadFromFile("Resources/res/Main_Menu_Background.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	background.setTexture(textureBackground);
	background.setPosition(0, 0);
}
