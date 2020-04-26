#ifndef OVERALL_STATE_H
#define OVERALL_STATE_H

#include "decorator.h"

#include "../../components/textboxes/textbox.h"
#include "../lib/animation.h"
#include "../lib/map.h"

enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct {
    animation ani;

    /* yours to modify */
    int direction;
    int diagonals; /* ie. Left-Up: 5 */
    int is_running;
} link;

typedef struct {
    map m;

    /* yours to modify */
} outland;

typedef struct {
    float zoom_level;
    float width, height;

    link my_link;
    outland my_map;

    /* in case you really need to access the global_state object */
    void *game_state;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif