/*
 * player.h
 *
 * Created: 3/16/2014 10:29:54 AM
 *  Author: Elmar
 */ 


#ifndef PLAYER_H_
#define PLAYER_H_

#include <Libs/Game/game.h>
#include "platformerentity.h"
#include "map.h"

typedef struct Player Player;

struct Player {
	PlatformerEntity platformEntity;
	uint8_t canJump;
	uint8_t jumpForce;
};

void * newPlayer(uint16_t x, uint16_t y);

#endif /* PLAYER_H_ */
