#include <stdlib.h>

#include <string.h>

#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"

#include "../../lib/substring.h"

#include "textbox.h"

static sfText *generate_text_object(textbox_state *state)
{
    sfRenderTexture_clear(state->texture, sfTransparent);
    sfText *text = sfText_create();
    if (!text)
        return (NULL);

    sfVector2u textbox_size = sfRenderTexture_getSize(state->texture);
    int charsize = textbox_size.y / 3.0 - 5 * sfText_getLineSpacing(text) - 4;
    sfText_setCharacterSize(text, charsize);
    sfText_setFillColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlue);
    sfText_setOutlineThickness(text, 4);
    sfText_setFont(text, state->font);

    sfText_move(text, (sfVector2f){0, -3 * sfText_getLineSpacing(text) - 1});

    if (state->offset > 2)
        sfText_move(text, (sfVector2f){0,
            -(state->offset - 2) * (sfText_getCharacterSize(text) + 4) -
            (state->offset - 2) * (sfText_getLineSpacing(text))
            - (state->offset - 2) * 3 });

    return (text);
}

const int sleep_newline = 700;
const int sleep_normal = 40;
const int sleep_finished = 2000;

int update_textbox(textbox_state *state)
{
    if (state->on) {

        if (!state->clock) {
            state->clock = sfClock_create();
            if (!state->clock)
                return (-1);
            sfClock_restart(state->clock);
            return (0);
        }

        float elaps = GET_ELAPSED_MSECS(state->clock);
        float to_wait = (state->string[state->charcount] == '\n' ? sleep_newline : sleep_normal);

        if (elaps > to_wait) {
            int finished = state->charcount >= strlen(state->string);
            if (!finished) {
                state->charcount++;
                if (state->string[state->charcount - 1] == '\n')
                    state->offset++;
                sfClock_restart(state->clock);
            } else if (elaps > sleep_finished) {
                state->on = 0;
            }
        }

        sfText *text = generate_text_object(state);
        if (!text)
            return (-1);

        char *s = substring(state->string, 0, state->charcount);
        sfText_setString(text, s);
        sfRenderTexture_drawText(state->texture, text, NULL);
        sfText_destroy(text);
        free(s);
    }
    return (0);
}