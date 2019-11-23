#include "MusicClass.h"

void MusicClass::playGameMusic() {
	if (!gameMusicNow.openFromFile("Resources/music/Game_music.ogg"))
		std::cout << "Blad ladowania muzyki" << std::endl;
	gameMusicNow.play();
	gameMusicNow.setVolume(50.f);
}

void MusicClass::playLostMusic() {
	if (!lostMusicNow.openFromFile("Resources/music/Lost_music.ogg"))
		std::cout << "Blad ladowania muzyki" << std::endl;
	lostMusicNow.play();
}

void MusicClass::stopGameMusic() {
	gameMusicNow.stop();
}

void MusicClass::playKrzyzykMusic() {
	if (!krzyzykMusicNow.openFromFile("Resources/music/Krzyzyk_music.ogg"))
		std::cout << "Blad ladowania muzyki" << std::endl;
	krzyzykMusicNow.play();
}

void MusicClass::playWinMusic() {
	if (!winMusicNow.openFromFile("Resources/music/Win_music.ogg"))
		std::cout << "Blad ladowania muzyki" << std::endl;
	winMusicNow.play();
}

void MusicClass::musicValueLoudly() {
	gameMusicNow.setVolume(50.f);
	krzyzykMusicNow.setVolume(100.f);
	winMusicNow.setVolume(100.f);
	lostMusicNow.setVolume(100.f);
}

void MusicClass::musicValueQuietly() {
	gameMusicNow.setVolume(0.f);
	krzyzykMusicNow.setVolume(0.f);
	winMusicNow.setVolume(0.f);
	lostMusicNow.setVolume(0.f);
}
