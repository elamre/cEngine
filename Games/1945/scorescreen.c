/*
 * scorescreen.c
 *
 * Created: 4/18/2014 11:48:48 AM
 *  Author: Elmar
 */ 
#include "scorescreen.h"

static void create(Screen * screen);
static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);

static uint32_t score;

static Font * elmarFont;

Screen * ScoreScreen(uint32_t tempScore)
{
	Screen * screen = newScreen();
	screen->create = create;
	screen->update = update;
	screen->draw = draw;
	score = tempScore;
	return screen;
}

static void create(Screen * screen)
{
	elmarFont = new_font("SCORE ",13,CANVASS_WIDTH,CANVASS_HEIGHT/2 - 8);
}

static void update(Screen * screen, GameDetails * gameDetails)
{
	if(gameDetails->gameInput->button_isTyped(BUTTONS_SELECT)){
		game_setScreen(MainMenu());
	}
}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	font_draw(elmarFont);
}