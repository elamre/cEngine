/*
 * platformer.c
 *
 * Created: 12/25/2013 4:27:54 PM
 *  Author: Elmar
 */ 
#include <Games/platformer/platformer.h>

BaseGame * platformer()
{
	BaseGame * game = calloc(1, sizeof(BaseGame));
	game_setEntityManager(syncManager_constructor(0));
	game_setScreen(newPlatformerGame());
	return game;
}