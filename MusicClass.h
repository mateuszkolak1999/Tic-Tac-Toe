#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
class MusicClass
{
private:
	Music gameMusicNow;
	Music lostMusicNow;
	Music krzyzykMusicNow;
	Music winMusicNow;

public:
	void playGameMusic();
	void playLostMusic();
	void stopGameMusic();
	void playKrzyzykMusic();
	void playWinMusic();
	void musicValueLoudly();
	void musicValueQuietly();
	void musicVolumeLoudyDodatkowe();
	void musicVolumeQuietlyDodatkowe();
};

