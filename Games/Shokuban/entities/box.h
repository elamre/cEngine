/*
 * Box.h
 *
 * Created: 12/2/2013 12:52:18 AM
 *  Author: Elmar
 */ 


#ifndef BOX_H_
#define BOX_H_

#include <Libs/Game/game.h>
#include <Games/Shokuban/entities/types.h>

typedef struct Box Box;

struct Box{
	Entity entity;
};
void * box_constructor(uint8_t x, uint8_t y);


#endif /* BOX_H_ */
