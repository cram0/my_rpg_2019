#include <SFML/Graphics.h>

#include "textbox.h"

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