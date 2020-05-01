#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.h>

#include "animation.h"
#include "map.h"

int animation_collide_with_map(animation *ani, map *m, float zoom, int direction);

#endif