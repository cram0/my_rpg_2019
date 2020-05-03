#include "interactions.h"

#include "../state.h"

#include "../../../include/debug.h"

#include "../../../objects/objects.h"

#include "../../lib/animation.h"

#include "../../../components/textboxes/textbox.h"

const char NPC_DIALOG_QUEST[] = "Hi Link !\nPress G to use your sword,\nPress I to open your inventory,\nPress E to interact with\nthe world and select\nitems in your inventory,\nPress Spacebar to rearrange\nyour inventory,\nPress F to use your\nequipped item,\nPress R to release what\nyou have in your hands.\nNow, go and kill enemies to\nget to level two,\nand then get back to me\noutside !";
const char NPC_DIALOG_QUEST_DONE[] = "Wow ! You did it !\nyou reached level two !\nBut you will need\nmore training to help\nPrincess Zelda ..\nYou can quit the game\n by pressing Q,\nor you can roam around\nand have fun killing\nenemies !";

void link_pick_object(link *lnk, object *objects)
{
    if (!lnk->object_carried) {
        lnk->object_carried = sfSprite_create();
    }
        sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(lnk->ani.hitbox);
        lnk->object_carried = sfSprite_copy(objects->ani.sprite);
        sfSprite_setPosition(lnk->object_carried, vec_create(hitbox.left, hitbox.top - (hitbox.height * 1.5)));
}

void throw_direction(link *lnk)
{

}

void link_throw_object(link *lnk)
{
    lnk->is_carrying = 0;

    switch (lnk->direction) {
        case 0 : lnk->throw_direction = 0;
    }
}

void link_interaction(link *lnk, object *objects, map *maps)
{
    if (lnk->is_carrying == 1) {
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
                objects[i].not_draw = 1;
                lnk->is_carrying = 1;
                link_pick_object(lnk, &objects[i]);
            }
            if (objects[i].type == NPC) {
                if (lnk->link_item.level < 2)
                    setstring_textbox(&maps->tuto_textbox, NPC_DIALOG_QUEST);
                if ((lnk->link_item.level >= 2))
                    setstring_textbox(&maps->tuto_textbox, NPC_DIALOG_QUEST_DONE);
            }
            if (objects[i].type == CHEST && objects[i].interacted) {
                m_animation_set_rects(&objects[i].ani, object_chest_open);
            }
        }
    }
}

void interaction_event(sfEvent event, link *lnk, object *objects, map *maps)
{
    if (event.key.code == sfKeyE && event.type == sfEvtKeyPressed)
        link_interaction(lnk, objects, maps);
    if (event.key.code == sfKeyR && event.type == sfEvtKeyPressed)
        link_throw_object(lnk);
}