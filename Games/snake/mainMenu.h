/*
 * menu.h
 *
 * Created: 12/14/2013 1:17:48 AM
 *  Author: Elmar
 */

#ifndef MENU3_H_
#define MENU3_H_

typedef struct MainMenu MainMenu;

#include <Libs/Game/game.h>
#include <Libs/Game/guiButton.h>

struct MainMenu {
	Screen screen;
	List * buttons;
};

MainMenu * newMainMenu();

#endif /* MENU_H_ */
