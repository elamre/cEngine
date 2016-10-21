/*
 * _1945.c
 *
 * Created: 3/19/2014 7:20:36 PM
 *  Author: Elmar
 */ 
#include "1945.h"
//#include "entities/player.h"

static void update(GameDetails * gamedetails);
static void draw(GameDetails * gameDetails);

static Sprite * water;
static uint8_t waterY;
static uint8_t waterTimer;

BaseGame * new1945Game()
{
	BaseGame * game = calloc(1, sizeof(BaseGame));
	game_setEntityManager(syncManager_constructor(0));
	game->updateSpeficific = update;
	game->drawSpecific = draw;
	game_setScreen(StartUp());
	waterY = 0;
	waterTimer = 0;
	water = sprite_new(32, 32, (uint8_t *)water_image);
	return game;
}

static void update(GameDetails * gamedetails)
{
	waterTimer++;
	if(waterTimer>1){
		waterTimer = 0;
		waterY++;
		if(waterY > 31){
			waterY = 0;
		}
	}	
}

static void draw(GameDetails * gameDetails)
{
	int16_t x = 0;
	int16_t y = 0;
	for(x = 0; x<(CANVASS_WIDTH/32) + 1; ++x){
		for(y = -1; y<(CANVASS_HEIGHT/32) + 1; ++y){
			sprite_draw(x*32, 32- waterY + (y*32), water);
		}
	}	
}
