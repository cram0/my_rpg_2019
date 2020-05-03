#ifndef OBJECTS_H_
#define OBJECTS_H_

#include <SFML/Graphics.h>

#include "../scenes/lib/animation.h"

#include "../mobs/mob.h"

enum {
    BUSH,
    POT,
    CHEST,
    ROCK,
    BIG_ROCK,
    NPC,
    DOOR,
    NUL_OBJECT
};

struct object;

struct map_change {
    char *map_path;
    char *color_path;
    mob *mobs;
    struct object *object;
    sfVector2f map_position;
};

typedef struct object {

    int type;

    animation ani;

    sfVector2f abs_pos;
    sfVector2f rel_pos;

    int interacted;
    int not_draw;

    struct map_change mc;

} object;

object overworld_objects[6];
object overworld2_objects[100];

void init_overworld_objects(void);

#endif