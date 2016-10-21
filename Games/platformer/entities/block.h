/*
 * block.h
 *
 * Created: 12/25/2013 6:06:11 PM
 *  Author: Elmar
 */ 


#ifndef BLOCK_H_
#define BLOCK_H_

#include <Libs/Game/game.h>
#include <Games/platformer/entities/platformerentity.h>

#define BLOCK_WIDTH 16
#define BLOCK_HEIGHT 16

static const uint8_t block_image[16][16][3] = {{{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{253,  0,  0},{253,  0,  0},{ 64,  0,  0},{253,  0,  0},{253,  0,  0},{ 64,  0,  0},{253,  0,  0},{253,  0,  0},{ 64,  0,  0},{253,  0,  0},{253,  0,  0},{ 64,  0,  0},{253,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0},{192,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{164,  0,  0},{253,  0,  0},{ 64,  0,  0},{164,  0,  0},{253,  0,  0},{ 64,  0,  0},{164,  0,  0},{253,  0,  0},{ 64,  0,  0},{164,  0,  0},{253,  0,  0},{ 64,  0,  0},{164,  0,  0},{253,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{164,  0,  0},{164,  0,  0},{ 64,  0,  0},{164,  0,  0},{164,  0,  0},{ 64,  0,  0},{164,  0,  0},{164,  0,  0},{ 64,  0,  0},{164,  0,  0},{164,  0,  0},{ 64,  0,  0},{164,  0,  0},{164,  0,  0},{ 64,  0,  0}},
										{{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0},{ 64,  0,  0}}
										};

typedef struct Block Block;

struct Block {
	PlatformerEntity platformEntity;	
	Sprite * sprite;
};

void * newBlock(int32_t x, int32_t y);

#endif /* BLOCK_H_ */