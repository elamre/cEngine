/*
 * platformergame.h
 *
 * Created: 12/25/2013 4:29:55 PM
 *  Author: Elmar
 */ 


#ifndef PLATFORMERGAME_H_
#define PLATFORMERGAME_H_

#include <Libs/Game/game.h>
#include <Libs/Game/screen.h>
#include "entities/block.h"
#include "entities/cloud.h"
#include "entities/player.h"
#include "entities/map.h"

Entity * camera;
Player * player;
struct RGBcolour * sky;
Screen * newPlatformerGame(void);




#endif /* PLATFORMERGAME_H_ */
