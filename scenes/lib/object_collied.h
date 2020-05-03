#ifndef OBJECT_COLLIED_H
#define OBJECT_COLLIED_H

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
#include "../lib/inventory.h"

void collied_objects(object *objects, animation *ani, int attacks);

#endif