#include "update_objects.h"

#include <SFML/Graphics.h>

#include "../../../objects/objects.h"

#include "../../lib/map.h"

#include "../../../generated_code/rects.h"
#include "../../../generated_code/origins.h"

#include "../state.h"

void obj_move_by_offset(object *objects, sfVector2f offset)
{
    objects->ani.position.x += offset.x;
    objects->ani.position.y += offset.y;
}

int obj_type_skip_collision(object *objects)
{
    switch (objects->type) {
        case CHEST : return (0);
        case ROCK : return (0);
        case BIG_ROCK : return (0);
        case NPC : return (0);
        default : if (objects->interacted) return (1);
    }
    return (0);
}

int obj_mob_collision(object *objects, mob *mobs, int direction)
{
    if (obj_type_skip_collision(objects))
        return (0);

    sfRectangleShape *hitbox_spr_mobs = mobs->ani.hitbox;
    sfFloatRect hitbox_mobs = sfRectangleShape_getGlobalBounds(hitbox_spr_mobs);

    sfRectangleShape *hitbox_spr_obj = objects->ani.hitbox;
    sfFloatRect hitbox_obj = sfRectangleShape_getGlobalBounds(hitbox_spr_obj);

    float start_x = 0, start_y = 0, end_x = 0, end_y = 0;
    if (direction & 1) {
        start_y = hitbox_mobs.top - 2;
        end_y = start_y + 2;
        start_x = hitbox_mobs.left;
        end_x = hitbox_mobs.left + hitbox_mobs.width;
    }
    else if (direction & 2) {
        start_y = hitbox_mobs.top + hitbox_mobs.height;
        end_y = start_y + 2;
        start_x = hitbox_mobs.left;
        end_x = hitbox_mobs.left + hitbox_mobs.width;
    }
    if (direction & 4) {
        start_y = hitbox_mobs.top;
        end_y = hitbox_mobs.top + hitbox_mobs.height;
        start_x = hitbox_mobs.left - 2;
        end_x = start_x + 2;
    }
    else if (direction & 8) {
        start_y = hitbox_mobs.top;
        end_y = hitbox_mobs.top + hitbox_mobs.height;
        start_x = hitbox_mobs.left + hitbox_mobs.width;
        end_x = start_x + 2;
    }

    for (float i = start_x; i < end_x; i++) {
        for (float j = start_y; j < end_y; j++) {
            if (sfFloatRect_contains(&hitbox_obj, i, j)) {
                return (1);
            }
        }
    }
    return (0);
}

int obj_link_collision(object *objects, link *lnk, int direction)
{
    if (obj_type_skip_collision(objects))
        return (0);

    sfRectangleShape *hitbox_spr_lnk = lnk->ani.hitbox;
    sfFloatRect hitbox_lnk = sfRectangleShape_getGlobalBounds(hitbox_spr_lnk);

    sfRectangleShape *hitbox_spr_obj = objects->ani.hitbox;
    sfFloatRect hitbox_obj = sfRectangleShape_getGlobalBounds(hitbox_spr_obj);

    float start_x = 0, start_y = 0, end_x = 0, end_y = 0;
    if (direction & 1) {
        start_y = hitbox_lnk.top - 2;
        end_y = start_y + 2;
        start_x = hitbox_lnk.left;
        end_x = hitbox_lnk.left + hitbox_lnk.width;
    }
    else if (direction & 2) {
        start_y = hitbox_lnk.top + hitbox_lnk.height;
        end_y = start_y + 2;
        start_x = hitbox_lnk.left;
        end_x = hitbox_lnk.left + hitbox_lnk.width;
    }
    if (direction & 4) {
        start_y = hitbox_lnk.top;
        end_y = hitbox_lnk.top + hitbox_lnk.height;
        start_x = hitbox_lnk.left - 2;
        end_x = start_x + 2;
    }
    else if (direction & 8) {
        start_y = hitbox_lnk.top;
        end_y = hitbox_lnk.top + hitbox_lnk.height;
        start_x = hitbox_lnk.left + hitbox_lnk.width;
        end_x = start_x + 2;
    }

    for (float i = start_x; i < end_x; i++) {
        for (float j = start_y; j < end_y; j++) {
            if (sfFloatRect_contains(&hitbox_obj, i, j))
                return (1);
        }
    }
    return (0);
}

void obj_update_ani(object *objects, float time)
{
    animation_update(&objects->ani, time);
}