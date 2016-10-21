/*
 * display.h
 *
 * Created: 20-9-2013 0:29:34
 *  Author: Aran Dokoupil
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#define HEIGHT 128 /**< \brief Specifies the height of the display */
#define WIDTH 160 /**< \brief  Specifies the width of the display*/
#define COLOUR 3 /**< \brief Specifies the amount of coloured sub pixels the display has */

#include <GL/glut.h>
#include <Libs/Graphical/graphical.h>

/*prototypes*/
void display_init();
void display_screenRefresh();

#endif /* DISPLAY_H_ */
