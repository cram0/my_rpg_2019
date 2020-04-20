#include <string.h>

#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/game_state.h"

void press_q_to_quit(global_state *state)
{
    if (state->event.type == sfEvtKeyPressed) {
        if (state->event.key.code == 'q')
            sfRenderWindow_close(state->win);
    }
}