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

#include "../../mobs/mob.h"

#include "lib/update_mob.h"
#include "lib/update_objects.h"

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    world *hous = &state->my_map;
    link *lnk = &state->my_link;
    mob *mobs = state->my_map.m.mobs;
    object *objects = state->my_map.m.objects;

    animation_update(&lnk->ani, 30);
    lose_health_animation(&lnk->link_stuff);
    health_regeneration(&lnk->link_stuff);
    synchro_boomrang(&lnk->boomr, &lnk->link_item);

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


    sfVector2f offset = { hous->m.pos.x - save.x, hous->m.pos.y - save.y };

    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        mob_move_by_offset(&mobs[i], offset);
        save = mobs[i].ani.position;
        mob_update_ani(&mobs[i], 200);

        sfVector2f save = mobs[i].ani.position;
        mob_movement(&state->my_map.m, &mobs[i]);
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
    }

    return (0);
}