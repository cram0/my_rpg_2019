#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/game_state.h"

#include "game_loop.h"

void change_scene(global_state *state)
{
    sfKeyCode codes[] = {sfKeyNum1, sfKeyNum2, 0};
    if (state->event.type == sfEvtKeyPressed) {
        for (int i = 0; codes[i]; i++) {
            if (codes[i] == state->event.key.code) {
                DEBUG("Changing scene: from %d to %d", state->scene_id, i);
                load_scene(state, i);
            }
        }
    }
}