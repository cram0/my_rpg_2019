#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "../lib/collision.h"
#include "../lib/animation.h"
#include "../lib/map.h"
#include "../lib/helpers.h"
#include "../lib/mobs_verif.h"

#include "../../mobs/mob.h"

#include "lib/update_mob.h"
#include "lib/update_objects.h"

#include "lib/map_change.h"

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    world *hous = &state->my_map;
    link *lnk = &state->my_link;
    mob *mobs = state->my_map.m.mobs;
    object *objects = state->my_map.m.objects;
    update_textbox(&state->text_gmv);
    if (lnk->link_stuff.health <= 0) return;
    if (lnk->attck.attack == 1) {
        attack_animation(&lnk->attck, &lnk->ani);
    }
    animation_update(&lnk->ani, 30);
    lose_health_animation(&lnk->link_stuff);
    health_regeneration(&lnk->link_stuff);
    synchro_boomrang(&lnk->boomr, &lnk->link_item);

    synchro_level(&lnk->link_stuff, &lnk->link_item);
    update_textbox(&state->my_map.m.tuto_textbox);

    sfVector2f save = hous->m.pos;
    map_move(&hous->m, lnk->is_running, lnk->diagonals);

    for (int i = 0; objects[i].type != NUL_OBJECT; i++) {
        if (obj_link_collision(&objects[i], lnk, lnk->diagonals)) {
            hous->m.pos = save;
            map_update(&hous->m);
        }
    }
    if (animation_collide_with_map(&lnk->ani, &hous->m, state->zoom_level, lnk->diagonals)) {
        hous->m.pos = save;
        map_update(&hous->m);
    }

    boomerang_colision(&lnk->boomr, mobs);
    attack_colision(&lnk->ani, mobs, &lnk->attck);
    mobs_is_alive(mobs, &lnk->link_item);

    sfVector2f offset = { hous->m.pos.x - save.x, hous->m.pos.y - save.y };

    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        find_target(&mobs[i], &lnk->ani);

        if (mobs[i].is_alive == 0) continue;
        mob_move_by_offset(&mobs[i], offset);
        save = mobs[i].ani.position;
        mob_update_ani(&mobs[i], 200);

        sfVector2f save = mobs[i].ani.position;
        if (mobs[i].is_aggro == 0)
            mob_movement(&state->my_map.m, &mobs[i]);
        else
            move_to_target(&mobs[i], &lnk->ani, &lnk->link_stuff);
        if (animation_collide_with_map(&mobs[i].ani, &hous->m, state->zoom_level, mobs[i].direction)) {
            mobs[i].ani.position = save;
            mob_update_ani(&mobs[i], 200);
        }

        for (int j = 0; objects[j].type != NUL_OBJECT; j++) {
            if (obj_mob_collision(&objects[j], &mobs[i], mobs[i].direction)) {
                mobs[i].ani.position = save;
                mob_update_ani(&mobs[i], 200);
            }
        }

        mob_set_rects(&mobs[i]);
    }

    for (int i = 0; objects[i].type != NUL_OBJECT; i++) {
        obj_move_by_offset(&objects[i], offset);
        obj_update_ani(&objects[i], 30);
        if (objects[i].type == DOOR) {
            if (map_change(lnk, &objects[i], &hous->m) == 1) {
                DECORATE(mobs_init)(state);
                DECORATE(objects_init)(state);
                break;
            }
        }
    }

    return (0);
}