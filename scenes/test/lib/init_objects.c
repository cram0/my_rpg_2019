#include "init_objects.h"

#include <SFML/Graphics.h>

#include "../state.h"
#include "../decorator.h"

#include "../../../generated_code/origins.h"
#include "../../../generated_code/rects.h"

#include "../../../objects/objects.h"

#include "../../../include/sfml_helpers.h"
#include "../../../include/debug.h"

#include "../../../scenes/lib/animation.h"

const char OBJECTS_PATH[] = "assets/objects.gif";

sfVector2f obj_rel_position(sfVector2f map_pos, sfVector2f abs_pos, float zoom)
{
    return (vec_create(zoom * abs_pos.x + map_pos.x, zoom * abs_pos.y + map_pos.y));
}

int DECORATE(objects_init)(DECORATE(state) *state)
{
    if (!state->my_map.m.objects)
        state->my_map.m.objects = overworld_objects;
    object *objects = state->my_map.m.objects;

    for (int i = 0; objects[i].type != NUL_OBJECT; i++) {
        sfVector2f rel = obj_rel_position(state->my_map.m.pos, objects[i].abs_pos, state->zoom_level);
        switch (objects[i].type) {
            case BUSH : m_animation_init(&objects[i].ani, state->zoom_level, OBJECTS_PATH, rel, object_bush, vec_create(15, 16), vec_create(22.5, 24));
                break;
            case CHEST : m_animation_init(&objects[i].ani, state->zoom_level, OBJECTS_PATH, rel, object_chest_closed, vec_create(16, 16), vec_create(24, 24));
                break;
            case ROCK : m_animation_init(&objects[i].ani, state->zoom_level, OBJECTS_PATH, rel, object_rock, vec_create(16, 16), vec_create(24, 24));
                break;
            case BIG_ROCK : m_animation_init(&objects[i].ani, state->zoom_level, OBJECTS_PATH, rel, object_big_rock, vec_create(32, 32), vec_create(48, 48));
                break;
            case POT : m_animation_init(&objects[i].ani, state->zoom_level, OBJECTS_PATH, rel, object_pot, vec_create(12, 13), vec_create(18, 19.5));
                break;
            case DOOR: m_animation_init(&objects[i].ani, state->zoom_level, OBJECTS_PATH, rel, doors, vec_create(12, 13), vec_create(18, 19.5));
            default : break;
        }
    }

    return (0);
}