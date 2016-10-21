/*
 * snake.c
 *
 *  Created on: Oct 21, 2016
 *      Author: elmar
 */

#include <Games/snake/snake.h>

static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);

static struct SnakeContainer * pongContainer;

static void empty(GameDetails * gameDetails);

static void empty(GameDetails * gameDetails) {

}

BaseGame * pongGame() {
	BaseGame * game = calloc(1, sizeof(BaseGame));
	game->drawSpecific = empty;
	game->updateSpeficific = empty;
	game_setEntityManager(syncManager_constructor(0));
	pongContainer = malloc(sizeof(struct SnakeContainer));

	game_setEntityManager(syncManager_constructor(0));
	game_setScreen(newSokobanMenu());

	return game;
}
