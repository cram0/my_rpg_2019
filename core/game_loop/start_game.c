#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/game_state.h"

#include "game_loop_private.h"

#define CONTINUE_IF_NEEDED() \
    if (state->continue_loop) { \
       continue; \
    }

#define BREAK_IF_NEEDED() \
    if (state->continue_loop) { \
       break; \
    }

int game_loop(global_state *state)
{
    DEBUG("game_loop: entered");

    while (sfRenderWindow_isOpen(state->win)) {
        int id = state->scene_id;

        state->continue_loop = 0;

        while (sfRenderWindow_pollEvent(state->win, &state->event)) {
            manage_events(state);
            BREAK_IF_NEEDED();
            state->scenes_db[id].handle_events(state->scene_state, state->event);
        }
        CONTINUE_IF_NEEDED();

        sfRenderWindow_clear(state->win, sfBlack);

        if (update_state(state) < 0 ||
            state->scenes_db[id].update(state->scene_state) < 0)
            return (-1);

        CONTINUE_IF_NEEDED();

        if (draw_sprites(state) < 0 ||
            state->scenes_db[id].draw(state->scene_state, state->win) < 0) {
            return (-1);
        }

        sfRenderWindow_display(state->win);
    }

    DEBUG("game_loop: exited");

    return (0);
}

void load_scene(global_state *state, int new_id)
{
    int old_id = state->scene_id;

    if (old_id > -1)
        state->scenes_db[old_id].destroy(state->scene_state);
    
    state->scene_id = new_id;
    state->scene_state = state->scenes_db[new_id].init(state);

    state->continue_loop = 1;
}

int start_game(global_state *state)
{
    load_scene(state, 0);
    if (game_loop(state) < 0) {
        state->exit_code = 84;
        return (-1);
    } else {
        return (0);
    }
}