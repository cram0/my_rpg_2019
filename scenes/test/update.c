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

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    house *hous = &state->my_map;
    link *lnk = &state->my_link;
    mob *mobs = state->my_map.m.mobs;

    animation_update(&lnk->ani, 30);

    sfVector2f save;
    map_move(&hous->m, lnk->is_running, lnk->diagonals, &save);
    if (animation_collide_with_map(&lnk->ani, &hous->m, state->zoom_level, lnk->diagonals)) {
        hous->m.pos = save;
        map_update(&hous->m);
    }

    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        mob_update(&mobs[i], 30);
    }

    return (0);
}