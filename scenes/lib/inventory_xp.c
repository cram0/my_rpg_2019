#include "inventory.h"

void init_xp(items *item)
{
    item->xp_shape = sfRectangleShape_create();
    item->xp_prog = sfRectangleShape_create();
    item->level_text = sfText_create();
    item->font = sfFont_createFromFile("./fonts/textboxes.ttf");

    sfText_setFont(item->level_text, item->font);
    sfText_setCharacterSize(item->level_text, 20);
    sfText_setPosition(item->level_text, (sfVector2f){173, 74});

    sfRectangleShape_setSize(item->xp_shape, (sfVector2f){60, 20});
    sfRectangleShape_setSize(item->xp_prog, (sfVector2f){20, 20});
    sfRectangleShape_setOutlineThickness(item->xp_shape, -2);
    sfRectangleShape_setOutlineColor(item->xp_shape, sfBlue);
    sfRectangleShape_setFillColor(item->xp_shape, sfTransparent);
    sfRectangleShape_setFillColor(item->xp_prog, sfGreen);
    sfRectangleShape_setPosition(item->xp_shape, (sfVector2f){178, 105});
    sfRectangleShape_setPosition(item->xp_prog, (sfVector2f){178, 105});

    item->xp = 50;
    item->level = 1;
    item->step = 100;
    item->coef_prog = 60.0 / item->step;
}

void update_xp_prog(items *item)
{
    float new_width = 0;
    new_width = item->xp * item->coef_prog;
    sfRectangleShape_setSize(item->xp_prog, (sfVector2f){new_width, 20});
}

void new_level(items *item)
{
    if (item->xp >= item->step) {
        item->xp -= item->step;
        item->level += 1;
        item->step += item->step * 1.1;
        item->coef_prog = 60.0 / item->step;
    }
}

void display_level(items *item)
{
    char *str = malloc(sizeof(char) * 30);
    char text[] = "Level: ";
    char *ptr = text + 7;
    itoa(item->level, str);
	while (*str != '\0')
		*ptr++ = *str++;
	*ptr = '\0';
    sfText_setString(item->level_text, text);
    sfRenderTexture_drawText(item->window_inv, item->level_text, NULL);
}

void draw_xp(items *item)
{
    new_level(item);
    display_level(item);
    update_xp_prog(item);
    sfRenderTexture_drawRectangleShape(item->window_inv,
                                        item->xp_prog, NULL);
    sfRenderTexture_drawRectangleShape(item->window_inv,
                                        item->xp_shape, NULL);
}