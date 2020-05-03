#include <string.h>

#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/game_state.h"

void press_q_to_quit(global_state *state)
{
    if (state->event.type == sfEvtKeyPressed) {
        if (state->event.key.code == sfKeyQ) {
            int old_id = state->scene_id;
            if (old_id > -1)
                state->scenes_db[old_id].destroy(state->scene_state);

            sfRenderWindow_close(state->win);
        }
    }
}