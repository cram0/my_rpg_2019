#include "../../include/game_state.h"

#include "game_loop_private.h"

int manage_events(global_state *state)
{
    close_window(state);
    press_any_key(state);
    return (0);
}