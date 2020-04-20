#include "../../include/game_state.h"

#include "../textboxes/textbox.h"

int update_state(global_state *state)
{
    if (update_textbox(&state->textbox) < 0)
        return (-1);
    return (0);
}