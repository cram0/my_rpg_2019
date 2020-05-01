#ifndef UPDATE_OBJECTS_H_
#define UPDATE_OBJECTS_H_

#include <SFML/Graphics.h>

#include "../../../objects/objects.h"

void obj_update_ani(object *objects, float time);
void obj_move_by_offset(object *objects, sfVector2f offset);

#endif