#include <stdlib.h>

#include <string.h>

#include <SFML/Graphics.h>

#include "textbox.h"

void reset_textbox(textbox_state *state)
{
    state->on = 0;
    state->charcount = 0;
    state->offset = 0;

    sfClock_destroy(state->clock);
    state->clock = NULL;

    memset(state->string, 0, 1024);
}