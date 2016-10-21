/*
 * display.c
 *
 * Created: 20-9-2013 0:29:21
 *  Author: Aran Dokoupil
 */

#include <Drivers/Display/display.h>

/*! \brief Initializes the display for use with the microcontroller
 *
 *	writes all the needed commands to correctly interface with the display
 *
 */
void display_init() {
	//glutInitWindowSize(320, 320);   // Set the window's initial width & height
	//glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
}

/*! \brief refreshes the screen buffer to the display
 *
 *	writes <b>all</b> the data of the screen buffer to the display to make the screen buffer viable to the outside world
 *
 */
void display_screenRefresh() {
	double w = glutGet( GLUT_WINDOW_WIDTH);
	double h = glutGet( GLUT_WINDOW_HEIGHT);

	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1, 1);

	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	RGBcolour colour;
	for (int x = WIDTH - 1; x >= 0; x--) {
		for (int y = HEIGHT - 1; y >= 0; y--) { //and proceed to write the content of the frame buffer to the display
			colour = screenBuffer[x][y];
			glColor4ub(colour.red, colour.green, colour.blue, 255);
			glRecti(x* 2, y * 2, x*2 + 2, y*2 + 2);
		}
	}
	glutSwapBuffers();
}
