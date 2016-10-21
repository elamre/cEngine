/*
 * game.c
 *
 * Created: 3/20/2014 4:18:30 PM
 *  Author: Elmar
 */ 

#include "game.h"

static void draw(Screen * screen, GameDetails * gameDetails);
static void create(Screen * screen);
static void update(Screen * screen, GameDetails * gameDetails);

Screen * newIngame()
{
	Screen * screen = newScreen();
	screen->create = create;
	screen->draw = draw;
	screen->update = update;
	return screen;
}

static void create(Screen * screen)
{
	game_addEntity(new_enemy_1(1,CANVASS_WIDTH/2,CANVASS_HEIGHT));

}

static void update(Screen * screen, GameDetails * gameDetails)
{

}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	
}