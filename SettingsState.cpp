#include "SettingsState.h"

int SettingsState::play(RenderWindow& window, Event& event, Vector2f mouse) {
	loadBackground();
	loadPlayButton();
	loadExitButton();
	loadTextureBoard();
	window.draw(background);
	window.draw(spriteName);
	window.draw(napisPlansza);
	window.draw(plus);
	window.draw(minus);
	window.draw(napisSymulacja);
	window.draw(tloIloscSymulacji);
	Text textIloscSymulacji(std::to_string(iloscSymulacji), fontIloscSymulacji);
	textIloscSymulacji.setCharacterSize(100);
	textIloscSymulacji.setFillColor(Color::White);
	textIloscSymulacji.setPosition(650, 480);
	window.draw(textIloscSymulacji);
	window.draw(minusSymulacja);
	window.draw(plusSymulacja);
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
	if (numer == 15)
		checker2 = false;
	else
		checker2 = true;

	if (numer == 3)
		checker3 = false;
	else
		checker3 = true;

	if (iloscSymulacji == 0)
		checker4 = false;
	else
		checker4 = true;

	if (iloscSymulacji == 100) {
		checker5 = false;
		textIloscSymulacji.setCharacterSize(50);
		textIloscSymulacji.setPosition(640, 480);
	}
	else {
		checker5 = true;
		textIloscSymulacji.setCharacterSize(100);
		textIloscSymulacji.setPosition(650, 480);
	}

	switch (numer) {
	case 3:
		ilosc.setTexture(textureIlosc[0]);
		window.draw(ilosc);
		break;
	case 4:
		ilosc.setTexture(textureIlosc[1]);
		window.draw(ilosc);
		break;
	case 5:
		ilosc.setTexture(textureIlosc[2]);
		window.draw(ilosc);
		break;
	case 6:
		ilosc.setTexture(textureIlosc[3]);
		window.draw(ilosc);
		break;
	case 7:
		ilosc.setTexture(textureIlosc[4]);
		window.draw(ilosc);
		break;
	case 8:
		ilosc.setTexture(textureIlosc[5]);
		window.draw(ilosc);
		break;
	case 9:
		ilosc.setTexture(textureIlosc[6]);
		window.draw(ilosc);
		break;
	case 10:
		ilosc.setTexture(textureIlosc[7]);
		window.draw(ilosc);
		break;
	case 11:
		ilosc.setTexture(textureIlosc[8]);
		window.draw(ilosc);
		break;
	case 12:
		ilosc.setTexture(textureIlosc[9]);
		window.draw(ilosc);
		break;
	case 13:
		ilosc.setTexture(textureIlosc[10]);
		window.draw(ilosc);
		break;
	case 14:
		ilosc.setTexture(textureIlosc[11]);
		window.draw(ilosc);
		break;
	case 15:
		ilosc.setTexture(textureIlosc[12]);
		window.draw(ilosc);
		break;
	}

	if (checker2) {
		if (plus.getGlobalBounds().contains(mouse)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					if (!status2) {
						numer++;
						status2 = true;
					}
					else
						status2 = false;
				}
			}
		}
	}

	if (checker3) {
		if (minus.getGlobalBounds().contains(mouse)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					if (!status3) {
						numer--;
						status3 = true;
					}
					else
						status3 = false;
				}
			}
		}
	}

	if (checker5) {
		if (plusSymulacja.getGlobalBounds().contains(mouse)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					if (!status5) {
						iloscSymulacji++;
						status5 = true;
					}
					else
						status5 = false;
				}
			}
		}
	}

	if (checker4) {
		if (minusSymulacja.getGlobalBounds().contains(mouse)) {
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					if (!status4) {
						iloscSymulacji--;
						status4 = true;
					}
					else
						status4 = false;
				}
			}
		}
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
	musicGame.setPosition(380, 640);

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

void SettingsState::loadTextureBoard() {
	if (!textureNapisPlansza.loadFromFile("Resources/res/Wielkosc planszy.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	napisPlansza.setTexture(textureNapisPlansza);
	napisPlansza.setPosition(150, 300);
	if (!texturePlus.loadFromFile("Resources/res/+.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	plus.setTexture(texturePlus);
	plus.setPosition(770,335);
	plus.setScale(0.5,0.5);
	if (!textureMinus.loadFromFile("Resources/res/-.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	minus.setTexture(textureMinus);
	minus.setPosition(520,335);
	minus.setScale(0.5, 0.5);

	if (!textureIlosc[0].loadFromFile("Resources/res/3.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[1].loadFromFile("Resources/res/4.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[2].loadFromFile("Resources/res/5.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[3].loadFromFile("Resources/res/6.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[4].loadFromFile("Resources/res/7.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[5].loadFromFile("Resources/res/8.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[6].loadFromFile("Resources/res/9.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[7].loadFromFile("Resources/res/10.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[8].loadFromFile("Resources/res/11.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[9].loadFromFile("Resources/res/12.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[10].loadFromFile("Resources/res/13.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[11].loadFromFile("Resources/res/14.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	if (!textureIlosc[12].loadFromFile("Resources/res/15.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	ilosc.setTexture(textureIlosc[0]);
	ilosc.setPosition(610, 300);

	//symulacja
	fontIloscSymulacji.loadFromFile("Resources/fonts/ITCKRIST.ttf");
	if (!textureNapisSymulacja.loadFromFile("Resources/res/Ilosc symulacji.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	napisSymulacja.setTexture(textureNapisSymulacja);
	napisSymulacja.setPosition(150, 470);
	if (!textureTloIloscSymulacji.loadFromFile("Resources/res/Tlo Ilosc Symulacji.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	tloIloscSymulacji.setTexture(textureTloIloscSymulacji);
	tloIloscSymulacji.setPosition(610, 470);
	if (!texturePlusSymulacja.loadFromFile("Resources/res/+.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	plusSymulacja.setTexture(texturePlusSymulacja);
	plusSymulacja.setPosition(770, 505);
	plusSymulacja.setScale(0.5, 0.5);
	if (!textureMinusSymulacja.loadFromFile("Resources/res/-.png"))
		std::cout << "Blad ladowania textury" << std::endl;
	minusSymulacja.setTexture(textureMinusSymulacja);
	minusSymulacja.setPosition(520, 505);
	minusSymulacja.setScale(0.5, 0.5);
}

int SettingsState::getNumer() {
	return numer;
}

int SettingsState::getIloscSymulacji() {
	return iloscSymulacji;
}