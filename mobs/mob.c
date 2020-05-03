#include <SFML/Graphics.h>

#include "mob.h"

#include "../include/sfml_helpers.h"

mob overworld_mobs[1] = {
    { .type = NUL_MOB}
};

mob overworld2_mobs[7] = {
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(630, 1820)},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(850, 1800)},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(866, 1912)},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(300, 1444)},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(510, 1340)},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(695, 1705)},
    { .type = NUL_MOB}
};