

#include "../../include/debug.h"
#include "../../include/game_state.h"

int init_window(global_state *state)
{
    DEBUG("init_window: entered");
    state->mode = (sfVideoMode){state->width, state->height, 32};
    state->win = sfRenderWindow_create(state->mode, NULL, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(state->win, 30);
    DEBUG("init_window: exited");
    return (state->win ? 0 : -1);
}