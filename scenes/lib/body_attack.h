#ifndef BODY_ATTACK_H
#define BODY_ATTACH_H

#include <SFML/Graphics.h>
#include <math.h>

#include "../../generated_code/rects.h"
#include "../../generated_code/origins.h"

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"
#include "../../mobs/mob.h"

#include "../lib/boomerang.h"
#include "../lib/animation.h"
#include "../lib/map.h"

typedef struct {
    sfClock *att_clock;
    sfIntRect *rects;
    sfVector2f *origins;

    sfIntRect *oldrect;
    sfVector2f *oldorigins;

    int dir;
    int index;
    int loop;
    int attack;
} body_att;

void init_body_attack(body_att *attack);
void body_attack(body_att *attack, int direction, sfEvent event);
void attack_animation(body_att *attck, animation *ani);

#endif