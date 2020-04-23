#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "decorator.h"

#include "../lib/animation.h"

typedef struct {
    animation ani;

    /* to fill with stuff */
} link;

typedef struct {
    float zoom_level;

    link my_link;

    /* in case you really need to access the global_state object */
    void *game_state;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif