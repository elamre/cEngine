/*
 * platformerentity.h
 *
 * Created: 12/25/2013 4:36:41 PM
 *  Author: Elmar
 */

#ifndef PLATFORMERENTITY_H_
#define PLATFORMERENTITY_H_

#include <Libs/Game/game.h>

typedef struct PlatformerEntity PlatformerEntity;

struct PlatformerEntity {
	Entity entity;
	int32_t gravity;
	int32_t drawX;
	int32_t drawY;
	int16_t xVelocity;
	int16_t yVelocity;
	//used for camera check
	uint8_t mass;
	uint8_t width;
	uint8_t height;
	uint8_t (*onFloor)(PlatformerEntity *);
	void (*updatePlatformEntity)(GameDetails *, PlatformerEntity *, uint16_t);
	void (*drawPlatformeEntity)(GameDetails *, PlatformerEntity *);
};
#include "platformertypes.h"

PlatformerEntity newPlatformerEntity(void);

#endif /* PLATFORMERENTITY_H_ */
