/*
 * water.h
 *
 * Created: 3/20/2014 1:18:45 PM
 *  Author: Elmar
 */ 


#ifndef WATER_H_
#define WATER_H_

#include <Libs/Game/game.h>

static const uint8_t water_image[32][32][3] = {{{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179}},
{{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 99,191},{  0, 99,191},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 99,191},{  0, 99,191},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179}},
{{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191}},
{{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179}},
{{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 67,171},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}},
{{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 99,191},{  0, 99,191},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179},{  0, 83,179}}
};




#endif /* WATER_H_ */