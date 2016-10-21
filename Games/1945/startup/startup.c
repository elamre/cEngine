/*
 * startup.c
 *
 * Created: 3/22/2014 6:49:25 PM
 *  Author: Elmar
 */ 

#include "startup.h"


static void create(Screen * screen);
static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);

static Player * player;
static Enemy_2 * enemy_1;
static Enemy_2 * enemy_2;
static Enemy_2 * enemy_3;
static Enemy_2 * enemy_4;
static uint8_t playerTimer;
static uint8_t playerState;
static uint8_t stateTimer;
static Font * elmarFont;

Screen * StartUp()
{
	Screen * screen = newScreen();
	screen->create = create;
	screen->update = update;
	screen->draw = draw;
	return screen;
}

static void create(Screen * screen)
{
	player = new_player(CANVASS_WIDTH/2 - PLAYER_ANIMATION_WIDTH/2, 0);
	player->canMove = 0;
	enemy_1 = new_enemy_2(0,0 - 40);
	enemy_2 = new_enemy_2(ENEMY_2_ANIMATION_WIDTH + 10, 10 - 40);
	enemy_3 = new_enemy_2(CANVASS_WIDTH - ENEMY_2_ANIMATION_WIDTH * 2 - 10, 10 - 40);
	enemy_4 = new_enemy_2(CANVASS_WIDTH - ENEMY_2_ANIMATION_WIDTH, 0 - 40);
	elmarFont = new_font("MADE BY ELMAR",13,CANVASS_WIDTH,CANVASS_HEIGHT/2 - 8);
	font_addNumber(elmarFont,12345);
	playerTimer = 0;
	playerState = 10;
	stateTimer = 0;
	game_addEntity(player);
	game_addEntity(enemy_1);
	game_addEntity(enemy_2);
	game_addEntity(enemy_3);
	game_addEntity(enemy_4);
}

static void update(Screen * screen, GameDetails * gameDetails)
{
	printf("select pressed %d hold %d.\n",gameDetails->gameInput->button_isPressed(BUTTONS_SELECT),gameDetails->gameInput->button_isTyped(BUTTONS_SELECT));
	if(gameDetails->gameInput->button_isTyped(BUTTONS_SELECT)) {
		game_getEntityManager()->clear(game_getEntityManager());
		game_setScreen(MainMenu());
	}
	playerTimer++;
	switch(playerState){
		case 10:
			if(playerTimer>=2){
				player->entity.yPos++;
				if(player->entity.yPos>=CANVASS_HEIGHT + 5){
					playerState++;
					player->entity.yPos = 0-PLAYER_ANIMATION_WIDTH;
				}
				playerTimer-=2;
			}
		break;
		case 11:
		if(playerTimer>=2){
			elmarFont->x--;
			if((elmarFont->x+ 14 * 13) <= 0){
				playerState = 0;
			}
			playerTimer-=2;
		}
		break;
		case 0:
			if(playerTimer>=3){
				player->entity.yPos++;
				if(player->entity.yPos>=50){
					playerState++;
				}
				playerTimer-=3;
			}
		break;
		case 1:
			if(playerTimer>=5){
				player->entity.yPos--;
				if(player->entity.yPos<=10){
					playerState++;
				}
				playerTimer-=5;
			}
		break;
		case 2:
		if(playerTimer>=5){
			player->entity.yPos++;
			if(player->entity.yPos>=20){
				playerState++;
			}
			playerTimer-=5;
		}
		break;
		case 3:
			if(playerTimer>=2){
				player->entity.yPos++;
				if(player->entity.yPos>=30){
					playerState++;
				}
				enemy_1->entity.yPos++;
				enemy_2->entity.yPos++;
				enemy_3->entity.yPos++;
				enemy_4->entity.yPos++;
				playerTimer-=2;
			}
		break;
		case 4:
			if(playerTimer>=1){
				playerTimer-=1;
				if(player->entity.yPos<CANVASS_HEIGHT)
					player->entity.yPos+=2;
				if(enemy_1->entity.yPos<CANVASS_HEIGHT)
					enemy_1->entity.yPos += 2;
				if(enemy_2->entity.yPos<CANVASS_HEIGHT)
					enemy_2->entity.yPos += 1;
				if(enemy_3->entity.yPos<CANVASS_HEIGHT){
					enemy_3->entity.yPos += 1;
				} else {
					playerTimer = 0;
					playerState++;			
				}
				if(enemy_4->entity.yPos<CANVASS_HEIGHT){
					enemy_4->entity.yPos += 2;
				}
			}
		break;
		case 5:
			playerTimer++;
			if(playerTimer>=50){
				game_getEntityManager()->clear(game_getEntityManager());
				game_setScreen(MainMenu());
			}	
		break;
		
	}
}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	//if(playerState== 11)
	font_draw(elmarFont);
}


