#ifndef UPDATE_OBJECTS_H_
#define UPDATE_OBJECTS_H_

#include <SFML/Graphics.h>

#include "../../../objects/objects.h"

#include "../state.h"

void obj_update_ani(object *objects, float time);
void obj_move_by_offset(object *objects, sfVector2f offset);
int obj_link_collision(object *objects, link *lnk, int direction);
int obj_mob_collision(object *objects, mob *mobs, int direction);

#endif