#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"

#include "../lib/animation.h"
#include "../lib/helpers.h"

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    animation_update(&state->my_link.ani, 30);

    return (0);
}
