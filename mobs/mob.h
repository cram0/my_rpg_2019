#ifndef MOB_H_
#define MOB_H_

#include <SFML/Graphics.h>

#include "../scenes/lib/animation.h"
#include "../include/debug.h"

enum {
    BLUE_KNIGHT,
    GREEN_KNIGHT,
    YELLOW_KNIGHT,
    TROOPER,
    MOUSE,
    SERPENT,
    CRAB,
    NUL_MOB
};

typedef struct {
    animation ani;

    int type;

    sfClock *mov_clk;
    sfClock *mov_clk_cd;
    int direction;
    int is_walking;
    int is_alive;
    int is_aggro;
    int life;

    sfVector2f abs_pos;
    sfVector2f rel_pos;

    sfClock *hit_clock;
    int hit;
    int clining;
    int loop;

    int room_id;
    int id;
    int xp;
} mob;

mob overworld_mobs[6];

#endif