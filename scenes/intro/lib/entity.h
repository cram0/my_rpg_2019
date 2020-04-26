#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.h>

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfClock *clocks[5];

    int is_drawable;
} entity;

int entity_load_spritesheet(entity *ent, char *fp);
void entity_set_position(entity *ent, sfVector2f pos);
long entity_get_elapsed_mil(entity *ent, int idx);
void entity_clock_restart(entity *ent, int idx);
void entity_draw(entity *ent, sfRenderWindow *win, sfRenderStates *states);
void entity_set_zoom(entity *ent, float zoom);

#define init_entity(ent, fp, pos) \
    entity_load_spritesheet(ent, fp); \
    entity_set_position(ent, pos);

#endif