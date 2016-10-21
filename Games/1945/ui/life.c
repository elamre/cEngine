/*
 * life.c
 *
 * Created: 4/17/2014 5:43:16 PM
 *  Author: Elmar
 */ 

#include "life.h"

Life * life_new(void){
	Life * life = malloc(sizeof(Life));
	life->sprite = sprite_new(LIFE_WIDTH,LIFE_HEIGHT,(uint8_t *) life_image);
	return life;
}

void life_remove(Life * life){
	free(life->sprite);
	free(life);
}
