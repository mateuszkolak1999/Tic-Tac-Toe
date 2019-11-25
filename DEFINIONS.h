#pragma once
#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900

#define STATE_MENU -0
#define STATE_MENU_SINGLEPLAYER 1
#define STATE_GAME 2
#define STATE_GAME_HARD 3
#define STATE_PAUSE 4
#define STATE_PLAYAGAIN 5
#define STATE_WIN 6
#define STATE_LOSE 7
#define STATE_REMIS 8

#define BOARD_LENGTH_3 3
#define BOARD_WIDTH_3 3

#define BOARD_LENGTH_5 5
#define BOARD_WIDTH_5 5

#define BOARD_MARGIN_X 230
#define BOARD_MARGIN_Y 200

#define KRZYZYK 2
#define KOLKO 1
#define PUSTE_POLE 0

#define MUSIC_STATE_LOUDLY 1
#define MUSIC_STATE_QUIETLY 0

static int STATE;