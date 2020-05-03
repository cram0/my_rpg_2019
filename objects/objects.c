#include <SFML/Graphics.h>

#include "objects.h"
#include "../mobs/mob.h"

#include "../include/sfml_helpers.h"

object overworld_objects[6] = {
    { .type = POT, .abs_pos = vec_create(42, 57)},
    { .type = POT, .abs_pos = vec_create(42, 73)},
    { .type = CHEST, .abs_pos = vec_create(191, 144)},
    { .type = NPC, .abs_pos = vec_create(150, 150)},
    { .type = DOOR, .abs_pos = vec_create(120, 185)},
    { .type = NUL_OBJECT}
};

object overworld2_objects[49] = {
    { .type = NPC, .abs_pos = vec_create(880, 1480)},
    { .type = BUSH, .abs_pos = vec_create(740, 1816)},
    { .type = BUSH, .abs_pos = vec_create(756, 1816)},
    { .type = BUSH, .abs_pos = vec_create(756, 1832)},
    { .type = BUSH, .abs_pos = vec_create(740, 1832)},
    { .type = BUSH, .abs_pos = vec_create(660, 1816)},
    { .type = BUSH, .abs_pos = vec_create(644, 1816)},
    { .type = BUSH, .abs_pos = vec_create(628, 1816)},
    { .type = BUSH, .abs_pos = vec_create(660, 1832)},
    { .type = BUSH, .abs_pos = vec_create(644, 1832)},
    { .type = BUSH, .abs_pos = vec_create(628, 1832)},
    { .type = BUSH, .abs_pos = vec_create(564, 1816)},
    { .type = BUSH, .abs_pos = vec_create(564, 1832)},
    { .type = BUSH, .abs_pos = vec_create(548, 1816)},
    { .type = BUSH, .abs_pos = vec_create(548, 1832)},
    { .type = BUSH, .abs_pos = vec_create(932, 1880)},
    { .type = BUSH, .abs_pos = vec_create(932, 1896)},
    { .type = BUSH, .abs_pos = vec_create(948, 1896)},
    { .type = BUSH, .abs_pos = vec_create(948, 1912)},
    { .type = BUSH, .abs_pos = vec_create(964, 1912)},
    { .type = BUSH, .abs_pos = vec_create(820, 1608)},
    { .type = BUSH, .abs_pos = vec_create(788, 1592)},
    { .type = BUSH, .abs_pos = vec_create(692, 1592)},
    { .type = BUSH, .abs_pos = vec_create(676, 1608)},
    { .type = BUSH, .abs_pos = vec_create(771, 1461)},
    { .type = BUSH, .abs_pos = vec_create(787, 1461)},
    { .type = BUSH, .abs_pos = vec_create(771, 1477)},
    { .type = BUSH, .abs_pos = vec_create(787, 1477)},
    { .type = BUSH, .abs_pos = vec_create(723, 1461)},
    { .type = BUSH, .abs_pos = vec_create(723, 1477)},
    { .type = BUSH, .abs_pos = vec_create(707, 1461)},
    { .type = BUSH, .abs_pos = vec_create(707, 1477)},
    { .type = BUSH, .abs_pos = vec_create(899, 1461)},
    { .type = BUSH, .abs_pos = vec_create(931, 1461)},
    { .type = BUSH, .abs_pos = vec_create(915, 1445)},
    { .type = BUSH, .abs_pos = vec_create(899, 1429)},
    { .type = BUSH, .abs_pos = vec_create(179, 1477)},
    { .type = BUSH, .abs_pos = vec_create(179, 1493)},
    { .type = BUSH, .abs_pos = vec_create(163, 1477)},
    { .type = BUSH, .abs_pos = vec_create(147, 1461)},
    { .type = BUSH, .abs_pos = vec_create(131, 1461)},
    { .type = BUSH, .abs_pos = vec_create(115, 1461)},
    { .type = BUSH, .abs_pos = vec_create(99, 1445)},
    { .type = BUSH, .abs_pos = vec_create(83, 1429)},
    { .type = BUSH, .abs_pos = vec_create(67, 1429)},
    { .type = BUSH, .abs_pos = vec_create(51, 1429)},
    { .type = BUSH, .abs_pos = vec_create(548, 1848)},
    { .type = BUSH, .abs_pos = vec_create(564, 1848)},
    { .type = NUL_OBJECT },
};

void init_overworld_objects(void)
{
    overworld_objects[4].mc = (struct map_change){
        "./assets/maps/overworld.png",
        "./maps_hitboxes/overworld.png",
        &overworld2_mobs[0],
        &overworld2_objects[0],
        //vec_create(0, 0)
        vec_create(-1732.548706, -5175.224121),
    };
}