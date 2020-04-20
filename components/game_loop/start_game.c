#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/game_state.h"

#include "../textboxes/textbox.h"

#include "game_loop_private.h"

int game_loop(global_state *state)
{
    DEBUG("game_loop: entered");

    while (sfRenderWindow_isOpen(state->win)) {
        while (sfRenderWindow_pollEvent(state->win, &state->event))
            manage_events(state);

        sfRenderWindow_clear(state->win, sfBlack);

        if (update_state(state) < 0 || draw_sprites(state) < 0) {
            return (-1);
        }

        sfRenderWindow_display(state->win);
    }

    DEBUG("game_loop: exited");

    return (0);
}

int start_game(global_state *state)
{
    if (init_textbox(&state->textbox, state->width, state->height) < 0 ||
        game_loop(state) < 0) {
        state->exit_code = 84;
        return (-1);
    } else {
        return (0);
    }
}