#ifndef BOOMERANG_COLISION_H
#define BOOMERANG_COLISION_H

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

void boomerang_colision(boomerang *boomr, mob *mobs);

#endif