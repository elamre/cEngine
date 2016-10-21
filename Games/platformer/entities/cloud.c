/*
 * cloud.c
 *
 * Created: 3/18/2014 9:01:34 PM
 *  Author: Elmar
 */ 

#include <Games/platformer/entities/cloud.h>

static void draw(GameDetails * gameDetailsm, void * entity);
static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);

void * newCloud(int32_t x, int32_t y)
{
	Cloud * cloud = (Cloud *) malloc(sizeof(Cloud));
	cloud->platformEntity = newPlatformerEntity();
	cloud->platformEntity.entity.xPos = x;
	cloud->platformEntity.entity.yPos = y;
	cloud->platformEntity.drawPlatformeEntity = draw;
	cloud->platformEntity.updatePlatformEntity = update;
	cloud->sprite = sprite_new(CLOUD_WIDTH,CLOUD_HEIGHT,&cloud_image);
	cloud->platformEntity.width = cloud->sprite->sizeX;
	cloud->platformEntity.height = cloud->sprite->sizeY;
	cloud->platformEntity.entity.type = TYPE_CLOUD;
	cloud->moveTimer = 0;
	return cloud;
}

static void draw(GameDetails * gameDetails, void * entity)
{
	Cloud * cloud = (Cloud *) entity;
	sprite_draw(cloud->platformEntity.drawX,cloud->platformEntity.drawY,cloud->sprite);
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT)
{
	Cloud * cloud = (Cloud *) entity;
	cloud->moveTimer+=deltaT;
	if(cloud->moveTimer >= 5){
		cloud->platformEntity.entity.xPos--;
		if((int)(cloud->platformEntity.entity.xPos + cloud->sprite->sizeX)<0){
			cloud->platformEntity.entity.xPos = LEVEL1_SIZE;
		}
		cloud->moveTimer-=5;
	}	
}
