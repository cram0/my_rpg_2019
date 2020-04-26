#include "hud.h"

void init_hud(equipment *stuff, float zoom_level)
{
    stuff->sprite = sfSprite_create();
    stuff->texture = sfTexture_createFromFile("./assets/hud.png", NULL);
    sfSprite_setTexture(stuff->sprite, stuff->texture, sfFalse);
    sfSprite_setTextureRect(stuff->sprite, hud_rects[0]);
    sfSprite_setScale(stuff->sprite, vec_same(zoom_level));
    stuff->arrow = 0;
    stuff->health = 0;
    stuff->ruby = 0;
    stuff->key = 0;
}

void display_hud(equipment *stuff, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, stuff->sprite, NULL);
}