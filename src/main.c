#include <stdlib.h>
#include <Drivers/Buttons/buttons.h>
#include <Libs/Graphical/graphical.h>
#include <Libs/Game/game.h>
#include <Games/Shokuban/sokuban.h>
#include <Games/1945/1945.h>
#include <Games/pong/pong.h>
#include <Games/platformer/platformer.h>
//#include <>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// all variables initialized to 1.0, meaning
// the triangle will initially be white
float red = 1.0f, blue = 1.0f, green = 1.0f;

// angle for rotating triangle
float angle = 0.0f;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	//gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
	game_render();
	display_screenRefresh();
}

void keyUp(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		button_setPressed(BUTTONS_UP, 0);
		break;
	case 's':
		button_setPressed(BUTTONS_DOWN, 0);
		break;
	case 'a':
		button_setPressed(BUTTONS_LEFT, 0);
		break;
	case 'd':
		button_setPressed(BUTTONS_RIGHT, 0);
		break;
	case 'e':
		button_setPressed(BUTTONS_SELECT, 0);
		break;

	}
}

void processNormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		button_setPressed(BUTTONS_UP, 1);
		break;
	case 's':
		button_setPressed(BUTTONS_DOWN, 1);
		break;
	case 'a':
		button_setPressed(BUTTONS_LEFT, 1);
		break;
	case 'd':
		button_setPressed(BUTTONS_RIGHT, 1);
		break;
	case 'e':
		button_setPressed(BUTTONS_SELECT, 1);
		break;

	}
	if (key == 27)
		exit(0);
}

void processSpecialKeys(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_F1:
		red = 1.0;
		green = 0.0;
		blue = 0.0;
		break;
	case GLUT_KEY_F2:
		red = 0.0;
		green = 1.0;
		blue = 0.0;
		break;
	case GLUT_KEY_F3:
		red = 0.0;
		green = 0.0;
		blue = 1.0;
		break;
	}
}

int main(int argc, char **argv) {
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 256);
	glutCreateWindow("Elmariscool");

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// here are the new entries
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events
	display_init();
	graphical_init(BLACK);
	game_init();
	//game_loadGame(platformer());
	//game_loadGame(pongGame());
	//game_loadGame(sokubanGame());
	//game_loadGame(new1945Game());
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
