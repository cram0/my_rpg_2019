#ifndef MOBS_ATTACK_H
#define MOBS_ATTACK_H

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
#include "../lib/hud.h"

void find_target(mob *mobs, animation *lnk);
void move_to_target(mob *mobs, animation *lnk, equipment *stuff);

#endif