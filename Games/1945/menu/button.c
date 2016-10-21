/*
 * button.c
 *
 * Created: 3/20/2014 12:13:33 PM
 *  Author: Elmar
 */ 
#include "button.h"

GUI_Button * new_button(char * text, uint8_t textLength, uint8_t x, uint8_t y)
{
	GUI_Button * button = malloc(sizeof(GUI_Button));
	button->buttonNormal = sprite_new(BUTTON_1_WIDTH, BUTTON_1_HEIGHT ,(uint8_t *)normal_button);
	button->buttonSelected = sprite_new(BUTTON_1_WIDTH, BUTTON_1_HEIGHT ,(uint8_t *)pressed_button);
	button->x = x;
	button->y = y;	
	button->selected = 0;
	button->font = new_font(text, textLength, x + BUTTON_1_WIDTH/2 - (((textLength)/2) * 13), y + BUTTON_1_HEIGHT/2 - 8);
	return button;
}

void button_draw(GUI_Button * button) 
{
	if(button->selected){
		sprite_draw(button->x, button->y, button->buttonSelected);
	} else {
		sprite_draw(button->x, button->y, button->buttonNormal);
	}
	font_draw(button->font);
}