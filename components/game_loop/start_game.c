#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/game_state.h"

#include "../textboxes/textboxes.h"

#include "game_loop_private.h"

int manage_events(global_state *state)
{
    close_window(state);
    press_any_key(state);
    return (0);
}

int update_state(global_state *state)
{
    update_textbox(&state->textbox);
    return (0);
}

int draw_sprites(global_state *state)
{
    if (draw_textbox(&state->textbox, state->win) < 0)
        return (-1);
    return (0);
}

int game_loop(global_state *state)
{
    DEBUG("game_loop: entered");
    while (sfRenderWindow_isOpen(state->win)) {
        while (sfRenderWindow_pollEvent(state->win, &state->event))
            manage_events(state);
        sfRenderWindow_clear(state->win, sfBlack);
        if (update_state(state) < 0 ||
            draw_sprites(state) < 0) {
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
    }
    return (0);
}