#include "interactions.h"

#include "../state.h"

#include "../../../include/debug.h"

#include "../../../objects/objects.h"

void link_pick_object(link *lnk, object *objects)
{
    if (!lnk->object_carried) {
        lnk->object_carried = sfSprite_create();
    }
        sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(lnk->ani.hitbox);
        lnk->object_carried = sfSprite_copy(objects->ani.sprite);
        sfSprite_setPosition(lnk->object_carried, vec_create(hitbox.left, hitbox.top - (hitbox.height * 1.5)));
}

void link_throw_object(link *lnk)
{

}

void link_interaction(link *lnk, object *objects)
{
    if (lnk->is_carrying) {
        link_throw_object(lnk);
        return;
    }

    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(lnk->ani.hitbox);
    sfVector2f pos = {.x = hitbox.left + hitbox.width / 2, .y = hitbox.top + hitbox.height / 2};

    if (lnk->direction == 0) {
        pos = vec_create(pos.x, pos.y - 30);
    }
    if (lnk->direction == 1) {
        pos = vec_create(pos.x, pos.y + 30);
    }
    if (lnk->direction == 2) {
        pos = vec_create(pos.x - 30, pos.y);
    }
    if (lnk->direction == 3) {
        pos = vec_create(pos.x + 30, pos.y);
    }

    for (int i = 0; objects[i].type != NUL_OBJECT; i++) {
        sfFloatRect obj_hitbox = sfRectangleShape_getGlobalBounds(objects[i].ani.hitbox);
        if (sfFloatRect_contains(&obj_hitbox, pos.x, pos.y)) {
            objects[i].interacted = 1;
            if (objects[i].type == POT || objects[i].type == BUSH) {
                lnk->is_carrying = 1;
                link_pick_object(lnk, &objects[i]);
            }
        }
    }
}

void interaction_event(sfEvent event, link *lnk, object *objects)
{
    if (event.key.code == sfKeyE && event.type == sfEvtKeyPressed)
        link_interaction(lnk, objects);
}