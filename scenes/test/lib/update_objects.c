#include "update_objects.h"

#include <SFML/Graphics.h>

#include "../../../objects/objects.h"

#include "../../lib/map.h"

#include "../../../generated_code/rects.h"
#include "../../../generated_code/origins.h"

void obj_move_by_offset(object *objects, sfVector2f offset)
{
    objects->ani.position.x += offset.x;
    objects->ani.position.y += offset.y;
}

void obj_update_ani(object *objects, float time)
{
    animation_update(&objects->ani, time);
}