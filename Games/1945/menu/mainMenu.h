/*
 * mainMenu.h
 *
 * Created: 3/19/2014 7:23:13 PM
 *  Author: Elmar
 */ 


#ifndef MAINMENU_H_
#define MAINMENU_H_

#include "../water.h"
#include "../1945.h"
#include "../game.h"
#include "button.h" 

GUI_Button * singlePlayerButton;
GUI_Button * multiplayerButton;
GUI_Button * optionsButton;

Screen * MainMenu();

#endif /* MAINMENU_H_ */