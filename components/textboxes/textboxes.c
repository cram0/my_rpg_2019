#include <stdlib.h>

#include <string.h>

#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"

#include "../../lib/substring.h"

#include "textboxes.h"

int init_textbox(textbox_state *state, float width, float height)
{
    state->win_height = height;
    state->win_width = width;

    DEBUG("init_textbox: entered");
    state->texture = sfRenderTexture_create(width * 0.82,
                                                    height * 0.27, sfFalse);

    state->font = sfFont_createFromFile("fonts/textboxes.ttf");

    DEBUG("init_textbox: exited");
    return (state->texture && state->font ? 0 : -1);
}

void reset_textbox(textbox_state *state)
{
    state->on = 0;
    state->charcount = 0;
    sfClock_destroy(state->clock);
    state->clock = NULL;
    state->offset = 0;
    memset(state->string, 0, 1024);
}

void destroy_textbox(textbox_state *state)
{
    reset_textbox(state);
    sfRenderTexture_destroy(state->texture);
    state->texture = NULL;
    sfFont_destroy(state->font);
    state->font = NULL;
}

int draw_textbox(textbox_state *state, sfRenderWindow *window)
{
    if (state->on) {
        sfRenderTexture_display(state->texture);

        sfSprite *sprite = sfSprite_create();
        if (!sprite)
            return (-1);

        sfVector2u textbox_size = sfRenderTexture_getSize(state->texture);
        sfVector2f textbox_pos = { .x = (state->win_width - textbox_size.x) / 2 };

        textbox_pos.y = (state->win_height - textbox_size.y) - textbox_pos.x;
        sfSprite_setPosition(sprite, textbox_pos);

        sfTexture *texture = (sfTexture *)sfRenderTexture_getTexture(state->texture);
        sfSprite_setTexture(sprite, texture, sfTrue);

        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfSprite_destroy(sprite);
    }
    return (0);
}

static sfText *generate_text_object(textbox_state *state)
{
    sfRenderTexture_clear(state->texture, sfTransparent);
    sfText *text = sfText_create();
    if (!text)
        return (NULL);

    sfVector2u textbox_size = sfRenderTexture_getSize(state->texture);
    sfText_setCharacterSize(text, textbox_size.y / 3.0 - 5 * sfText_getLineSpacing(text) - 4);
    sfText_setFillColor(text, sfWhite);
    sfText_setOutlineColor(text, sfBlue);
    sfText_setOutlineThickness(text, 4);
    sfText_setFont(text, state->font);

    sfText_move(text, (sfVector2f){0, -3 * sfText_getLineSpacing(text) - 1});
    if (state->offset > 2)
        sfText_move(text, (sfVector2f){0,
            -(state->offset - 2) * (sfText_getCharacterSize(text) + 4) -
            (state->offset - 2) * (sfText_getLineSpacing(text))
            - (state->offset - 2) * 3
        });

    return (text);
}

int update_textbox(textbox_state *state)
{
    if (!state->clock) {
        state->clock = sfClock_create();
        sfClock_restart(state->clock);
        return (0);
    }
    if (state->on) {
        if (GET_ELAPSED_MSECS(state->clock) > (state->string[state->charcount] == '\n' ? 700 : 40)) {
            if (state->charcount < strlen(state->string)) {
                state->charcount++;
                if (state->string[state->charcount - 1] == '\n')
                    state->offset++;
            }
            sfClock_restart(state->clock);
        }
        sfText *text = generate_text_object(state);
        char *s = substring(state->string, 0,
                                            state->charcount);
        sfText_setString(text, s);
        sfRenderTexture_drawText(state->texture, text, NULL);
        sfText_destroy(text);
        free(s);
    }
    return (0);
}