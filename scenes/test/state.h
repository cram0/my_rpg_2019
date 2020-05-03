#ifndef TEST_STATE_H
#define TEST_STATE_H

#include "decorator.h"

#include "../../components/textboxes/textbox.h"
#include "../lib/animation.h"
#include "../lib/map.h"
#include "../lib/hud.h"
#include "../lib/inventory.h"
#include "../lib/boomerang.h"
#include "../lib/equiped_stuff.h"

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
    int is_carrying;

    sfSprite *object_carried;
    int throw_direction;
    sfVector2f interact_point;

    equipment link_stuff;
    items link_item;
    boomerang boomr;
} link;

typedef struct {
    map m;

    /* yours to modify */
} world;

typedef struct {
    float zoom_level;
    float width, height;

    link my_link;
    world my_map;

    /* in case you really need to access the global_state object */
    void *game_state;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif