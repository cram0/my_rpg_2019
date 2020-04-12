#include <stdlib.h>

#include <SFML/Graphics.h>

#include "textbox.h"

void destroy_textbox(textbox_state *state)
{
    reset_textbox(state);

    sfRenderTexture_destroy(state->texture);
    state->texture = NULL;

    sfFont_destroy(state->font);
    state->font = NULL;
}