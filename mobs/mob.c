#include <SFML/Graphics.h>

#include "mob.h"

#include "../include/sfml_helpers.h"

mob overworld_mobs[1] = {
    { .type = NUL_MOB}
};

mob overworld2_mobs[25] = {
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(630, 1820), .id = 1},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(850, 1800), .id = 2},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(866, 1912), .id = 3},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(300, 1444), .id = 4},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(510, 1340), .id = 5},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(695, 1705), .id = 6},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(550, 1938), .id = 7},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(720, 1980), .id = 8},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(840, 1850), .id = 9},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(680, 1580), .id = 10},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(823, 1517), .id = 11},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(865, 1209), .id = 12},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(882, 1100), .id = 13},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(871, 967), .id = 14},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(863, 854), .id = 15},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(857, 721), .id = 16},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(302, 1216), .id = 18},
    { .type = BLUE_KNIGHT, .abs_pos = vec_create(127, 1177), .id = 19},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(865, 1209), .id = 20},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(127, 1067), .id = 21},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(86, 808), .id = 22},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(126, 989), .id = 23},
    { .type = GREEN_KNIGHT, .abs_pos = vec_create(143, 743), .id = 24},
    { .type = NUL_MOB}
};