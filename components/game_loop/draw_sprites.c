#include "../../include/game_state.h"

#include "../textboxes/textbox.h"

int draw_sprites(global_state *state)
{
    if (draw_textbox(&state->textbox, state->win) < 0)
        return (-1);
    return (0);
}