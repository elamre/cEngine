#include "enemy_2.h"

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);

void * new_enemy_2(int_fast16_t x, int_fast16_t y)
{
	Enemy_2 * enemy_2 = malloc(sizeof(Enemy_2));
	enemy_2->entity = *newEntity();
	enemy_2->entity.xPos = x;
	enemy_2->entity.yPos = y;
	enemy_2->entity.update = update;
	enemy_2->entity.draw = draw;
	enemy_2->sprite = sprite_new(ENEMY_2_WIDTH, ENEMY_2_HEIGHT , (uint8_t *)enemy_2_image);
	enemy_2->entity.width = ENEMY_2_ANIMATION_WIDTH;
	enemy_2->entity.height = enemy_2->sprite->sizeY;
	enemy_2->animationIndex = 0;
	enemy_2->animationTimer = 0;
	return enemy_2;
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT)
{
	Enemy_2 * enemy = (Enemy_2 *) entity;
	enemy->animationTimer++;
	if(enemy->animationTimer>=2)	{
		enemy->animationTimer = 0;
		enemy->animationIndex++;
		if(enemy->animationIndex >= ENEMY_2_ANIMATION_LENGTH){
			enemy->animationIndex = 0;
		}
	}
}
static void draw(GameDetails * gameDetails, void * entity)
{
	Enemy_2 * enemy = (Enemy_2 *) entity;
	sprite_drawSubsection(enemy->entity.xPos,enemy->entity.yPos,enemy->sprite,enemy->animationIndex*ENEMY_2_ANIMATION_WIDTH,0,enemy->animationIndex*ENEMY_2_ANIMATION_WIDTH+ENEMY_2_ANIMATION_WIDTH,ENEMY_2_HEIGHT);
}