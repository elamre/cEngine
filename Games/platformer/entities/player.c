/*
 * player.c
 *
 * Created: 3/16/2014 10:29:42 AM
 *  Author: Elmar
 */
#include "player.h"

static void draw(GameDetails * gameDetails, PlatformerEntity * entity);
static void update(GameDetails * gameDetails, PlatformerEntity * entity, uint16_t deltaT);

void * newPlayer(uint16_t x, uint16_t y) {
	Player * player = malloc(sizeof(Player));
	player->platformEntity = newPlatformerEntity();
	player->platformEntity.mass = 1;
	player->platformEntity.entity.xPos = x;
	player->platformEntity.entity.yPos = y;
	player->platformEntity.entity.type = TYPE_PLAYER;
	player->platformEntity.drawPlatformeEntity = draw;
	player->platformEntity.updatePlatformEntity = update;
	player->jumpForce = 120;
	return player;
}

static void update(GameDetails * gameDetails, PlatformerEntity * entity, uint16_t deltaT) {
	Player * self = (Player *) entity;
	/*if (self->platformEntity->onFloor()) {
		self->canJump = 1;
		self->platformEntity.gravity = 0;
		self->jumpForce = 120;
	}*/
	if (gameDetails->gameInput->button_isPressed(BUTTONS_UP)) {
		if (self->canJump) {
			self->platformEntity.entity.yPos += 3;
			self->platformEntity.gravity -= 0;
			self->jumpForce -= 4;
			if (self->jumpForce <= 2) {
				self->canJump = 0;
			}
		}
	}

	if (gameDetails->gameInput->button_isPressed(BUTTONS_DOWN)) {
		//self->platformEntity.entity.yPos--;	
	}
	if (gameDetails->gameInput->button_isPressed(BUTTONS_LEFT)) {
		/*if (level1[16 - ((self->platformEntity.entity.yPos / 16) + 1)][(((self->platformEntity.entity.xPos- 1) / 16))] != 1) {*/
		self->platformEntity.xVelocity = -1;
		/*} else {
		 self->platformEntity.xVelocity = 0;
		 }*/
	} else if (gameDetails->gameInput->button_isPressed(BUTTONS_RIGHT)) {
		/*if (level1[16 - (((self->platformEntity.entity.yPos + 8) / 16))][(1 + ((self->platformEntity.entity.xPos + 1) / 16))] != 1) {*/
		self->platformEntity.xVelocity = 1;
		/*} else {
		 self->platformEntity.xVelocity = 0;
		 }*/
	} else {
		self->platformEntity.xVelocity = 0;
	}
}

static void draw(GameDetails * gameDetails, PlatformerEntity * entity) {
	Player * self = (Player *) entity;
	graphical_drawRectangle(self->platformEntity.drawX, self->platformEntity.drawY, self->platformEntity.drawX + 16, self->platformEntity.drawY + 16, 1, GREEN);
}
