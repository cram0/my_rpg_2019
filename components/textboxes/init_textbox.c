#include <SFML/Graphics.h>

#include "../../include/debug.h"

#include "textbox.h"

int init_textbox(textbox_state *state, float width, float height)
{
    DEBUG("init_textbox: entered");

    state->win_height = height;
    state->win_width = width;

    state->texture = sfRenderTexture_create(width * 0.82,
                                                    height * 0.27, sfFalse);

    state->font = sfFont_createFromFile("fonts/textboxes.ttf");

    DEBUG("init_textbox: exited");

    return (state->texture && state->font ? 0 : -1);
}