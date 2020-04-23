#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "../lib/animation.h"
#include "../lib/helpers.h"

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    house *hous = &state->my_map;
    link *lnk = &state->my_link;

    map_move(&hous->m, lnk->is_running, lnk->diagonals);
    animation_update(&lnk->ani, 30);

    return (0);
}
