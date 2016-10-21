/*
 * Box.c
 *
 * Created: 12/2/2013 12:52:27 AM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/entities/box.h>

static void draw(GameDetails * gameDetails, void * entity);

void * box_constructor(uint8_t x, uint8_t y)
{
	Box * box = (Box*) malloc(sizeof(Box));
	box->entity = *newEntity();
	box->entity.xPos = x;
	box->entity.yPos = y;
	box->entity.draw = draw;
	box->entity.type = BOX_TYPE;
	box->entity.width = CELL_SIZE;
	box->entity.height = CELL_SIZE;
	return box;
}


static void draw(GameDetails * gameDetails, void * entity)
{
	Box * self = (Box *) entity;
	graphical_drawRectangle(self->entity.xPos,self->entity.yPos,self->entity.xPos + CELL_SIZE, self->entity.yPos + CELL_SIZE, 0, BLACK);
	graphical_drawRectangle(self->entity.xPos+1,self->entity.yPos+1,self->entity.xPos + CELL_SIZE-CELL_SIZE/8, self->entity.yPos + CELL_SIZE-CELL_SIZE/8, 1, RED);	
}
