#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.h>

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} entity;

int entity_load_spritesheet(entity *ent, char *fp);

#endif