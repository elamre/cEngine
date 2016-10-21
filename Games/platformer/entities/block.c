/*
 * block.c
 *
 * Created: 12/25/2013 6:04:44 PM
 *  Author: Elmar
 */ 

#include <Games/platformer/entities/block.h>

static void draw(GameDetails * gameDetailsm, void * entity);

void * newBlock(int32_t x, int32_t y)
{
	Block * block = (Block *) malloc(sizeof(Block));
	block->platformEntity = newPlatformerEntity();
	block->platformEntity.entity.xPos = x;
	block->platformEntity.entity.yPos = y;
	block->platformEntity.entity.type = TYPE_BLOCK;
	block->platformEntity.drawPlatformeEntity = draw;
	block->sprite = sprite_new(BLOCK_WIDTH,BLOCK_HEIGHT, &block_image);
	block->platformEntity.width = block->sprite->sizeX;
	block->platformEntity.height = block->sprite->sizeY;
	return block;
}

static void draw(GameDetails * gameDetails, void * entity)
{
	Block * block = (Block *) entity;
	sprite_draw(block->platformEntity.drawX,block->platformEntity.drawY,block->sprite);
}
