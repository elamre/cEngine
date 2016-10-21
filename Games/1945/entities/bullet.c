/*
 * bullet.c
 *
 * Created: 3/20/2014 4:48:43 PM
 *  Author: Elmar
 */ 
#include "bullet.h"

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);
static void destructor(void * entity);

void * new_bullet(uint8_t x, uint8_t y)
{
	Bullet * bullet = malloc(sizeof(Bullet));
	bullet->entity = *newEntity();
	bullet->sprite = sprite_new(BULLET_WIDTH, BULLET_HEIGHT , (uint8_t *)bullet_image);
	bullet->entity.width = bullet->sprite->sizeX;
	bullet->entity.height = bullet->sprite->sizeY;
	bullet->entity.xPos = x;
	bullet->entity.yPos = y;
	bullet->entity.update = update;
	bullet->entity.draw = draw;
	bullet->entity.type = BULLET_TYPE;
	bullet->entity.destructor = destructor;
	return bullet;
}

static void destructor(void * entity)
{
	Bullet * bullet = (Bullet *) entity;
	free(bullet->sprite);
	free(bullet);
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT)
{
	Bullet * bullet = (Bullet *) entity;
	bullet->entity.yPos+=3;
	if(bullet->entity.yPos>CANVASS_HEIGHT){
		bullet->entity.alive = 0;
	}
	Entity * entity2 = game_getEntityManager()->getEntity_2(game_getEntityManager(),&bullet->entity);
	if(entity2 != NULL){
		if(entity2->type == 2 || entity2->type == BULLET_TYPE){
		}else {
			entity2->alive = 0;
			bullet->entity.alive = 0;
		}
	}
	
}

static void draw(GameDetails * gameDetails, void * entity)
{
	Bullet * bullet = (Bullet *) entity;
	sprite_draw(bullet->entity.xPos,bullet->entity.yPos,bullet->sprite);
}