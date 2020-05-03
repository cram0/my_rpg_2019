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
#include "../lib/equiped_stuff.h"

typedef struct {
    sfClock *att_clock;
    sfIntRect *rects;
    sfVector2f *origins;

    sfIntRect *oldrect;
    sfVector2f *oldorigins;

    int power;
    int last_mob_id;
    int dir;
    int index;
    int loop;
    int attack;
} body_att;

void init_body_attack(body_att *attack);
void body_attack(body_att *attack, int direction, equipment *stuff,
                sfEvent event);
void attack_animation(body_att *attck, animation *ani);
void attack_colision(animation *ani, mob *mobs, body_att *attck);

#endif