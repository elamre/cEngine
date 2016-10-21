/*
 * filledgap.c
 *
 * Created: 12/20/2013 1:03:10 PM
 *  Author: Elmar
 */ 

#include "filledgap.h"

static void draw(GameDetails * gameDetails, void * entity);

void * filledgap_constructor(uint8_t x, uint8_t y)
{
	FilledGap * filledGap = (FilledGap*) malloc(sizeof(FilledGap));
	filledGap->entity = *newEntity();
	filledGap->entity.xPos = x;
	filledGap->entity.yPos = y;
	filledGap->entity.type = FILLEDGAP_TYPE;
	filledGap->entity.draw = draw;
	return filledGap;
}


static void draw(GameDetails * gameDetails, void * entity)
{
	FilledGap * self = (FilledGap *) entity;
graphical_drawRectangle(self->entity.xPos,self->entity.yPos,self->entity.xPos + CELL_SIZE, self->entity.yPos + CELL_SIZE, 0, BLACK);
graphical_drawRectangle(self->entity.xPos+1,self->entity.yPos+1,self->entity.xPos + CELL_SIZE - CELL_SIZE/8, self->entity.yPos + CELL_SIZE - CELL_SIZE/8, 1, DARKBLUE);
}