#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <SFML/Graphics.h>

#include "../scenes/lib/animation.h"

enum {
    BUSH,
    POT,
    CHEST,
    ROCK,
    BIG_ROCK,
    NPC,
    NUL_OBJECT
};

typedef struct {

    int type;

    animation ani;

    sfVector2f abs_pos;
    sfVector2f rel_pos;

    int interacted;
    int not_draw;

} object;

object overworld_objects[5];

#endif