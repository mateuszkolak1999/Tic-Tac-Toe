#include "PauseState.h"

int PauseState::pause(RenderWindow& window, Event& event, Vector2f mouse) {
	if (!texture.loadFromFile("Resources/res/Close Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!textureMenu.loadFromFile("Resources/res/Home Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!texture_background.loadFromFile("Resources/res/Pause Background.png"))
		std::cout << "Blad ladowania tekstury" << std::endl;

	background.setTexture(texture_background);
	window.draw(background);

	close.setTexture(texture);
	close.setPosition(300, 350);
	close.setScale(1.25, 1.25);
	menu.setTexture(textureMenu);
	menu.setPosition(500, 350);
	window.draw(close);
	window.draw(menu);

	if (close.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem start" << std::endl;
				window.close();
			}
		}
	}

	if (menu.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem menu" << std::endl;
				return STATE_MENU;
			}
		}
	}
	return STATE_PAUSE;
}