/*
 * filledgap.h
 *
 * Created: 12/20/2013 1:03:24 PM
 *  Author: Elmar
 */ 


#ifndef FILLEDGAP_H_
#define FILLEDGAP_H_

#include <Libs/Game/game.h>
#include <Games/Shokuban/entities/types.h>

typedef struct FilledGap FilledGap;

struct FilledGap{
	Entity entity;
};

void * filledgap_constructor(uint8_t x, uint8_t y);

#endif /* FILLEDGAP_H_ */
