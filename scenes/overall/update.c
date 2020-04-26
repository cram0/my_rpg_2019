#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "../lib/animation.h"
#include "../lib/map.h"
#include "../lib/helpers.h"

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    outland *outl = &state->my_map;
    link *lnk = &state->my_link;

    DEBUG("%f - %f", state->my_map.m.pos.x, state->my_map.m.pos.y);
    map_move(&outl->m, lnk->is_running, lnk->diagonals);
    animation_update(&lnk->ani, 30);

    return (0);
}
