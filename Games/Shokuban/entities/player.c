/*
 * player.c
 *
 * Created: 11/30/2013 11:41:24 PM
 *  Author: Elmar
 */
#include <Games/Shokuban/entities/player.h>

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);
static void move(int8_t deltaX, int8_t deltaY, Player * self);
static uint8_t isVictory(EntityManager * entityManager);

void * player_constructor(EntityManager * entityManager, uint8_t x, uint8_t y) {
	Player * player = (Player*) malloc(sizeof(Player));
	player->entity = *newEntity();
	player->entity.xPos = x;
	player->entity.yPos = y;
	player->moves = 0;
	player->entityManager = entityManager;
	player->entity.type = PLAYER_TYPE;
	player->entity.update = update;
	player->entity.draw = draw;
	player->entity.width = CELL_SIZE;
	player->entity.height = CELL_SIZE;
	return player;
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT) {
	Player * self = (Player *) entity;
	if (gameDetails->gameInput->button_isTyped(BUTTONS_UP)) {
		move(0, CELL_SIZE, self);
	} else if (gameDetails->gameInput->button_isTyped(BUTTONS_DOWN)) {
		move(0, -CELL_SIZE, self);
	} else if (gameDetails->gameInput->button_isTyped(BUTTONS_LEFT)) {
		move(-CELL_SIZE, 0, self);
	} else if (gameDetails->gameInput->button_isTyped(BUTTONS_RIGHT)) {
		move(CELL_SIZE, 0, self);
	}
	if (isVictory(self->entityManager)) {
		self->victory(self);
	}
}

static void move(int8_t deltaX, int8_t deltaY, Player * self) {
	Entity * other = (Entity*) self->entityManager->getEntity(
			self->entityManager,
			self->entity.xPos + self->entity.width / 2 + (deltaX),
			self->entity.yPos + self->entity.height / 2 + (deltaY));
	if (other == NULL) {
		self->entity.yPos += deltaY;
		self->entity.xPos += deltaX;
		self->moves++;
	} else if (other->type == CRATE_TYPE) {
		Entity * crateOther = (Entity*) self->entityManager->getEntity(
				self->entityManager,
				other->xPos + self->entity.width / 2 + deltaX,
				other->yPos + self->entity.height / 2 + deltaY);
		if (crateOther == NULL) {
			self->entity.yPos += deltaY;
			self->entity.xPos += deltaX;
			other->yPos += deltaY;
			other->xPos += deltaX;
			self->moves++;
		} else if (crateOther->type == GAP_TYPE) {
			self->entity.yPos += deltaY;
			self->entity.xPos += deltaX;
			other->yPos += deltaY;
			other->xPos += deltaX;
			self->moves++;
			game_addEntity(filledgap_constructor(other->xPos, other->yPos));
			other->alive = 0;
			crateOther->alive = 0;
		}
	} else if (other->type == GAP_TYPE) {
		self->entity.yPos += deltaY;
		self->entity.xPos += deltaX;
		//you can walk over gaps, for now
	} else if (other->type == FILLEDGAP_TYPE) {
		Entity * crateOther = (Entity*) self->entityManager->getEntity(
				self->entityManager,
				other->xPos + self->entity.width / 2 + deltaX,
				other->yPos + self->entity.height / 2 + deltaY);
		if (crateOther == NULL) {
			self->entity.yPos += deltaY;
			self->entity.xPos += deltaX;
			other->alive = 0;
			game_addEntity(
					gap_constructor(self->entity.xPos, self->entity.yPos));
			game_addEntity(
					crate_constructor(other->xPos + deltaX,
							other->yPos + deltaY));
		} else if (crateOther->type == GAP_TYPE) {
			crateOther->alive = 0;
			other->alive = 0;
			self->entity.yPos += deltaY;
			self->entity.xPos += deltaX;
			game_addEntity(
					gap_constructor(self->entity.xPos, self->entity.yPos));
			game_addEntity(
					filledgap_constructor(other->xPos + deltaX,
							other->yPos + deltaY));
		}
	} else {
	}
}

static uint8_t isVictory(EntityManager * entityManager) {
	Entity * entity;
	Node * tempNode = entityManager->entityList->head;
	while (tempNode->nextNode != NULL) {
		entity = (Entity*) tempNode->data;
		if (entity->type == GAP_TYPE) {
			return 0;	//No gaps are allowed
		}
		tempNode = tempNode->nextNode;
	}
	return 1;
}

static void draw(GameDetails * gameDetails, void * entity) {
	Player * self = (Player *) entity;
	graphical_drawCircle(self->entity.xPos + CELL_SIZE / 2,
			self->entity.yPos + CELL_SIZE / 2, CELL_SIZE / 2 - 1, 1, GREEN);
	graphical_drawCircle(self->entity.xPos + CELL_SIZE / 2,
			self->entity.yPos + CELL_SIZE / 2, CELL_SIZE / 2 - 1, 0, BLACK);
}
