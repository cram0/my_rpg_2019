#include <SFML/Graphics.h>

#include "mob.h"

#include "../include/sfml_helpers.h"

mob overworld_mobs[6] = {
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(100, 100), .id = 1},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(50, 50), .id = 2},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(150, 150), .id = 3},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(150, 150), .id = 4},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(150, 150), .id = 5},
    { .type = NUL_MOB}
};