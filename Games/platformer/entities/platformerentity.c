/*
 * platformerentitie.c
 *
 * Created: 12/25/2013 4:36:11 PM
 *  Author: Elmar
 */
#include <Games/platformer/entities/platformerentity.h>
#include "../platformergame.h"

static void platformUpdate(GameDetails * gameDetails, PlatformerEntity * entity, uint16_t deltaT);
static void platformDraw(GameDetails * gameDetails, PlatformerEntity * entity);
static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);
static uint8_t onFloor(PlatformerEntity * entity);

PlatformerEntity newPlatformerEntity() {
	PlatformerEntity * platformerEntity = (PlatformerEntity *) calloc(1, sizeof(PlatformerEntity));
	platformerEntity->entity = *newEntity();
	platformerEntity->entity.update = update;
	platformerEntity->entity.draw = draw;
	platformerEntity->drawPlatformeEntity = platformDraw;
	platformerEntity->updatePlatformEntity = platformUpdate;
	platformerEntity->onFloor = onFloor;
	platformerEntity->width = 16;
	platformerEntity->height = 16;
	platformerEntity->xVelocity = 0;
	platformerEntity->yVelocity = 0;
	platformerEntity->mass = 0;
	return *platformerEntity;
}

static uint8_t onFloor(PlatformerEntity * entity) {
	return entity->yVelocity == 0;
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT) {
	PlatformerEntity * platformEntity = (PlatformerEntity *) entity;
	//if((platformEntity->entity.xPos + 16 > camera->xPos) && (platformEntity->entity.xPos < (camera->xPos + CANVASS_WIDTH))){
	//if((platformEntity->entity.yPos > camera->yPos + 16) && (platformEntity->entity.yPos < (camera->yPos + CANVASS_HEIGHT))){
	platformEntity->updatePlatformEntity(gameDetails, platformEntity, deltaT);
	Entity * ent = &platformEntity->entity;
	printf("Entity id: %d type: %d\n", ent->id, ent->type);
	if (platformEntity->xVelocity != 0) {
		if (platformEntity->xVelocity > 0) {
			if (level1[16 - (((platformEntity->entity.yPos + 8) / 16))][(1 + ((platformEntity->entity.xPos + 1) / 16))] == 1) {
				platformEntity->xVelocity = 0;
			}
		} else if (platformEntity->xVelocity < 0) {
			if (level1[16 - (((platformEntity->entity.yPos + 8) / 16))][(1 + ((platformEntity->entity.xPos - 1) / 16))] == 1) {
				platformEntity->xVelocity = 0;
			}
		}
		int32_t newXpos = ent->xPos + platformEntity->xVelocity;
		int8_t delta = 0;
		if (platformEntity->xVelocity > 0) {
			delta = 1;
		} else {
			delta = -1;
		}
		if (level1[ent->yPos / 16][newXpos / 16] != 1) {
			ent->xPos = newXpos;
		} else {
			ent->xPos = newXpos + delta;
		}
	}
	if (platformEntity->mass) {	//TODO incorporate this more
		uint32_t checkY = ((platformEntity->entity.yPos - 3) / 16);
		uint32_t checkX1 = ((platformEntity->entity.xPos) / 16);
		uint32_t checkX2 = ((platformEntity->entity.xPos) / 16) + 1;
		if (getType(checkX1, checkY) != 1 && getType(checkX2, checkY) != 1) {
			platformEntity->gravity += 8;
			platformEntity->entity.yPos -= (platformEntity->gravity / 2000) + 2;
		}
	}
	if (platformEntity->yVelocity != 0) {
		int32_t newYpos = ent->yPos + platformEntity->yVelocity;
		ent->yPos += newYpos;
	}
	//	}
	//}
}

static void draw(GameDetails * gameDetails, void * entity) {
	PlatformerEntity * platformEntity = (PlatformerEntity *) entity;
	int checkX = platformEntity->entity.xPos + platformEntity->width;
	int checkY = platformEntity->entity.yPos + platformEntity->height;
	if ((checkX >= camera->xPos) && (platformEntity->entity.xPos < (camera->xPos + CANVASS_WIDTH))) {
		if ((checkY >= camera->yPos) && (platformEntity->entity.yPos < (camera->yPos + CANVASS_HEIGHT))) {
			platformEntity->drawX = platformEntity->entity.xPos - camera->xPos;
			platformEntity->drawY = platformEntity->entity.yPos - camera->yPos;
			platformEntity->drawPlatformeEntity(gameDetails, entity);
		}
	}
}

static void platformUpdate(GameDetails * gameDetails, PlatformerEntity * platformEntity, uint16_t deltaT) {

//Intentionally left empty
}

static void platformDraw(GameDetails * gameDetails, PlatformerEntity * entity) {
//Intentionally left empty
}
