#include "enemy_1.h"

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);
static void destructor(void * entity);

void * new_enemy_1(uint8_t level, uint8_t x, uint8_t y)
{
	Enemy_1 * enemy_1 = malloc(sizeof(Enemy_1));
	enemy_1->level = level;
	enemy_1->entity = *newEntity();
	enemy_1->entity.xPos = x;
	enemy_1->entity.yPos = y;
	enemy_1->entity.update = update;
	enemy_1->entity.draw = draw;
	enemy_1->entity.destructor = destructor;
	enemy_1->sprite = sprite_new(ENEMY_1_WIDTH, ENEMY_1_HEIGHT , (uint8_t *)enemy_1_image);
	enemy_1->entity.width = ENEMY_1_ANIMATION_WIDTH;
	enemy_1->entity.height = enemy_1->sprite->sizeY;
	enemy_1->animationIndex = 0;
	enemy_1->animationTimer = 0;
	enemy_1->entity.type = ENEMY_1_TYPE;
	return enemy_1;
}

static void destructor(void * entity)
{
	Enemy_1 * enemy = (Enemy_1*) entity;
	uint8_t level = enemy->level;
	if(level%10 == 0){
		game_addEntity(new_enemy_1(enemy->level+1, rand()%(CANVASS_WIDTH-ENEMY_1_ANIMATION_WIDTH),CANVASS_HEIGHT+10));
		game_addEntity(new_enemy_1(enemy->level+1, rand()%(CANVASS_WIDTH-ENEMY_1_ANIMATION_WIDTH),CANVASS_HEIGHT+10));
	} else {
		game_addEntity(new_enemy_1(enemy->level+1, rand()%(CANVASS_WIDTH-ENEMY_1_ANIMATION_WIDTH),CANVASS_HEIGHT+10));
	}
	free(enemy->sprite);
	free(enemy);
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT)
{
	Enemy_1 * enemy = (Enemy_1 *) entity;
	enemy->animationTimer++;
	if(enemy->animationTimer>=2)	{
		enemy->animationTimer = 0;
		enemy->animationIndex++;
		if(enemy->animationIndex >= ENEMY_1_ANIMATION_LENGTH){
			enemy->animationIndex = 0;
		}
	}
	switch(enemy->level){
		case 1:
		break;
	}
	enemy->entity.yPos--;
	if((enemy->entity.yPos + ENEMY_1_HEIGHT )<= 0){
		enemy->entity.alive = 0;
	}
}
static void draw(GameDetails * gameDetails, void * entity)
{
	Enemy_1 * enemy = (Enemy_1 *) entity;
	sprite_drawSubsection(enemy->entity.xPos,enemy->entity.yPos,enemy->sprite,enemy->animationIndex*ENEMY_1_ANIMATION_WIDTH,0,enemy->animationIndex*ENEMY_1_ANIMATION_WIDTH+ENEMY_1_ANIMATION_WIDTH,ENEMY_1_HEIGHT);
}