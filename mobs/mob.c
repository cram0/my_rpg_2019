#include <SFML/Graphics.h>

#include "mob.h"

#include "../include/sfml_helpers.h"

mob overworld_mobs[1] = {
    { .type = NUL_MOB}
};

mob overworld2_mobs[7] = {
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(630, 1820), .id = 1},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(850, 1800), .id = 2},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(866, 1912), .id = 3},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(300, 1444), .id = 4},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(510, 1340), .id = 5},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(695, 1705), .id = 6},
    { .type = NUL_MOB}
};