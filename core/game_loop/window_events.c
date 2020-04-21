#include <SFML/Graphics.h>

#include "../../include/game_state.h"

void close_window(global_state *state)
{
    if (state->event.type == sfEvtClosed)
        sfRenderWindow_close(state->win);
}