/*
 * platformergame.c
 *
 * Created: 12/25/2013 4:30:03 PM
 *  Author: Elmar
 */
#include <Games/platformer/platformergame.h>

static void draw(Screen * screen, GameDetails * gameDetails);
static void create(Screen * screen);
static void update(Screen * screen, GameDetails * gameDetails);

Screen * newPlatformerGame() {
	camera = newEntity();
	player = newPlayer(50, 80);
	sky = graphical_createRGBColour(97, 183, 214);
	Screen * screen = newScreen();
	screen->create = create;
	screen->draw = draw;
	screen->update = update;
	return screen;
}

static void create(Screen * screen) {
	uint8_t x = 0;
	uint8_t y = 0;
	for (x = 0; x < 16; x++) {
		for (y = 0; y < 16; y++) {
			switch (level2[y][x]) {
			case 1:
				game_addEntity(newBlock(x * 16, (16 - y) * 16));
				break;
			case 2:
				game_addEntity(newCloud(x * 16, (16 - y) * 16));
				break;
			}
		}
	}
	game_addEntity(camera);
	game_addEntity(player);
}

static void update(Screen * screen, GameDetails * gameDetails) {
	uint32_t newCamX, newCamY;
	newCamX = (0 > player->platformEntity.entity.xPos - CANVASS_WIDTH / 2) ? 0 : player->platformEntity.entity.xPos - CANVASS_WIDTH / 2;
	newCamY = (0 > player->platformEntity.entity.yPos - CANVASS_HEIGHT / 2) ? 0 : player->platformEntity.entity.yPos - CANVASS_HEIGHT / 2;
	camera->xPos = newCamX;
	camera->yPos = newCamY + 16 + 1;
}

static void draw(Screen * screen, GameDetails * gameDetails) {
	graphical_drawRectangle(0, 0, CANVASS_WIDTH, CANVASS_HEIGHT, 1, sky);
}
