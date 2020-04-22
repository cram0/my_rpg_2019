#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "decorator.h"

#include "../lib/animation.h"

enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct {
    animation ani;
    int direction;

    /* to fill with stuff */
} link;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;

    sfSprite *sprite_color;
    sfTexture *texture_color;

    sfImage *hitbox_dump;

    sfVector2f pos;

} map;

typedef struct {
    float zoom_level;

    link my_link;
    map my_map;

    /* in case you really need to access the global_state object */
    void *game_state;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif