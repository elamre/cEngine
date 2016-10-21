/*
 * mainMenu.c
 *
 * Created: 3/19/2014 7:23:22 PM
 *  Author: Elmar
 */ 

#include "mainMenu.h"

static void create(Screen * screen);
static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);

Screen * MainMenu()
{
	Screen * screen = newScreen();
	screen->create = create;
	screen->update = update;
	screen->draw = draw;
	singlePlayerButton = new_button("SINGLE", 6, (CANVASS_WIDTH / 2) - (BUTTON_1_WIDTH / 2), 89);
	multiplayerButton = new_button("single", 5, (CANVASS_WIDTH / 2) - (BUTTON_1_WIDTH / 2), 48);
	optionsButton = new_button("Single", 7, (CANVASS_WIDTH / 2) - (BUTTON_1_WIDTH / 2), 7);
	return screen;
}

static void create(Screen * screen)
{
	singlePlayerButton->selected = 1;
}

static void update(Screen * screen, GameDetails * gameDetails)
{

	if(gameDetails->gameInput->button_isTyped(BUTTONS_SELECT)){
		if(singlePlayerButton->selected == 1){
			game_setScreen(newIngame());
			game_addEntity(new_player(CANVASS_WIDTH/2 - 15,0));
		} else if(multiplayerButton->selected == 1){
			game_setScreen(newIngame());
			game_addEntity(new_player(CANVASS_WIDTH/2 - 15,0));
		} else if(optionsButton->selected == 1){
			
		}
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_DOWN)){
		if(singlePlayerButton->selected == 1){
			singlePlayerButton->selected = 0;
			multiplayerButton->selected = 1;
			} else if(multiplayerButton->selected == 1){
			multiplayerButton->selected = 0;
			optionsButton->selected = 1;
			} else if(optionsButton->selected == 1){
			optionsButton->selected = 0;
			singlePlayerButton->selected = 1;
		}
		} else if(gameDetails->gameInput->button_isTyped(BUTTONS_UP)){
			if(singlePlayerButton->selected){
				singlePlayerButton->selected = 0;
				optionsButton->selected = 1;
			} else if(multiplayerButton->selected){
				singlePlayerButton->selected = 1;
				multiplayerButton->selected = 0;
			} else if(optionsButton->selected){
				optionsButton->selected = 0;
				multiplayerButton->selected = 1;
			}
	}
}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	button_draw(singlePlayerButton);
	button_draw(multiplayerButton);
	button_draw(optionsButton);
}


