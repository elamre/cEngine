/*
 * buttons.c
 *
 * Created: 11/16/2013 4:49:33 PM
 *  Author: Elmar
 */

#include <Drivers/Buttons/buttons.h>

void button_init() {
	buttons[BUTTONS_LEFT] = &button_left;
	buttons[BUTTONS_RIGHT] = &button_right;
	buttons[BUTTONS_UP] = &button_up;
	buttons[BUTTONS_DOWN] = &button_down;
	buttons[BUTTONS_SELECT] = &button_select;
	uint8_t i = 0;
	for (i = 0; i < 5; i++) {
		buttons[i]->handled = 0;
		buttons[i]->pressed = 0;
		buttons[i]->runTime = 0;
		buttons[i]->startTime = 0;
	}
}

void buttons_update() {
	uint8_t i;
	for (i = 0; i < 5; i++) {
		if (buttons[i]->handled) {
			buttons[i]->typed = 0;
		}
	}
}

uint8_t button_isTyped(uint8_t id) {
	if (buttons[id]->typed)
		buttons[id]->handled = 1;
	return buttons[id]->typed;
}

uint8_t button_isPressed(uint8_t id) {
	return buttons[id]->pressed;
}

void button_setPressed(uint8_t id, uint8_t pressed) {
	if (!buttons[id]->pressed && pressed)
		buttons[id]->typed = 1;
	buttons[id]->pressed = pressed;
}

