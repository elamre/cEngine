/*
 * player.c
 *
 * Created: 3/19/2014 7:19:35 PM
 *  Author: Elmar
 */ 

#include "player.h"

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);
static void destructor(void * entity);

void * new_player(int16_t x, int16_t y)
{
	Player * player = malloc(sizeof(Player));
	player->entity = *newEntity();
	player->entity.width = PLAYER_ANIMATION_WIDTH;
	player->entity.height = PLAYER_HEIGHT;
	player->entity.xPos = x;
	player->entity.yPos = y;
	player->entity.draw = draw;
	player->entity.update = update;
	player->entity.destructor = destructor;
	player->animationIndex = 0;
	player->shootTimer = 0;
	player->animationTimer = 0;
	player->entity.type = PLAYER_TYPE;
	player->canShoot = 0;
	player->canMove = 1;
	player->sprite = sprite_new(PLAYER_WIDTH, PLAYER_HEIGHT , (uint8_t *)player_image);
	player->lifes = 3;
	player->life = sprite_new(LIFE_WIDTH, LIFE_HEIGHT, (uint8_t *)life_image);
	return player;
}

static void destructor(void * entity)
{
	Player * player = (Player *) entity;
	free(player->sprite);
	free(player->life);
	free(player);
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT)
{
	Player * player = (Player *) entity;
	player->animationTimer++;
	if(player->animationTimer>=2)	{
		player->animationTimer = 0;
		player->animationIndex++;
		if(player->animationIndex >= PLAYER_ANIMATION_SIZE){
			player->animationIndex = 0;
		}
	}
	if(player->canMove){
		if(gameDetails->gameInput->button_isPressed(BUTTONS_LEFT)){
			if((player->entity.xPos)>0)
				player->entity.xPos--;
		}
		if(gameDetails->gameInput->button_isPressed(BUTTONS_RIGHT)){
			if((player->entity.xPos+PLAYER_ANIMATION_WIDTH)<CANVASS_WIDTH)
				player->entity.xPos++;
		}
		if(gameDetails->gameInput->button_isPressed(BUTTONS_UP)){
			if((player->entity.yPos+player->sprite->sizeY)<CANVASS_HEIGHT)
				player->entity.yPos++;
		}
		if(gameDetails->gameInput->button_isPressed(BUTTONS_DOWN)){
			if((player->entity.yPos)>0)
				player->entity.yPos--;
		}
		if(gameDetails->gameInput->button_isPressed(BUTTONS_SELECT)){
			if(player->canShoot){
				game_addEntity(new_bullet(player->entity.xPos + (PLAYER_ANIMATION_WIDTH/2) - 1,player->entity.yPos + player->sprite->sizeY / 2));
				player->canShoot = 0;
			}
		}
		if(player->canShoot == 0){
			player->shootTimer++;
			if(player->shootTimer >= 2){
				player->canShoot = 1;
				player->shootTimer = 0;
			}
		}
	}
	Entity * entity2 = game_getEntityManager()->getEntityExclude(game_getEntityManager(),&player->entity,BULLET_TYPE);
	if(entity2 != NULL){
		if(entity2->type != 2){
			entity2->alive = 0;
			player->lifes--;
			if(player->lifes == 0){
				
			}
		}
	}
}
static void draw(GameDetails * gameDetails, void * entity)
{
	Player * player = (Player *) entity;
	sprite_drawSubsection(player->entity.xPos,player->entity.yPos,player->sprite,player->animationIndex*PLAYER_ANIMATION_WIDTH,0,player->animationIndex*PLAYER_ANIMATION_WIDTH+PLAYER_ANIMATION_WIDTH,PLAYER_HEIGHT);
	uint8_t i = 0, x = player->entity.xPos + PLAYER_ANIMATION_WIDTH/2 - (player->lifes * LIFE_WIDTH/2), y;
	if(player->entity.yPos>=LIFE_HEIGHT){
		y = player->entity.yPos - LIFE_HEIGHT;
	} else {
		y = 0;
	}
	for(;i<player->lifes; i++){
		sprite_draw(x + LIFE_WIDTH * i, y , player->life);
	}
}