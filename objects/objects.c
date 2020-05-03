#include <SFML/Graphics.h>

#include "objects.h"
#include "../mobs/mob.h"

#include "../include/sfml_helpers.h"

object overworld_objects[5] = {
    { .type = POT, .abs_pos = vec_create(42, 57)},
    { .type = POT, .abs_pos = vec_create(42, 73)},
    { .type = CHEST, .abs_pos = vec_create(191, 144)},
    { .type = DOOR, .abs_pos = vec_create(120, 185)},
    { .type = NUL_OBJECT}
};

object overworld2_objects[1] = {
    { .type = NUL_OBJECT },
};

void init_overworld_objects(void)
{
    overworld_objects[3].mc = (struct map_change){
        "./assets/maps/overworld.png",
        "./maps_hitboxes/overworld.png",
        &overworld2_mobs[0],
        &overworld2_objects[0],
        //vec_create(0, 0)
        vec_create(-1732.548706, -5175.224121),
    };
}