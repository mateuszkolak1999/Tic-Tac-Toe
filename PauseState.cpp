#include "PauseState.h"

int PauseState::pause(RenderWindow& window, Event& event, Vector2f mouse) {
	if (!texture.loadFromFile("Resources/res/Resume Button.png"))
		std::cout << "Blad ladowania textury" << std::endl;

	if (!texture_background.loadFromFile("Resources/res/Pause Background.png"))
		std::cout << "Blad ladowania tekstury" << std::endl;

	background.setTexture(texture_background);
	window.draw(background);

	playagain.setTexture(texture);
	playagain.setPosition(425, 350);
	window.draw(playagain);

	if (playagain.getGlobalBounds().contains(mouse)) {
		if (event.type == Event::MouseButtonPressed) {
			if (event.mouseButton.button == Mouse::Left) {
				std::cout << "Wcisnalem start" << std::endl;
				return STATE_GAME;
			}
		}
	}
	return STATE_PAUSE;
}