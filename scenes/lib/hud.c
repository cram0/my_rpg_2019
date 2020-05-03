#include "hud.h"

void init_text(text *value)
{
    value->font = sfFont_createFromFile("./fonts/textboxes.ttf");
    value->nbr_arrow = sfText_create(), value->nbr_ruby = sfText_create();
    value->nbr_bomb = sfText_create();
    value->nbr_key = sfText_create();
    sfText_setFont(value->nbr_ruby, value->font);
    sfText_setFont(value->nbr_arrow, value->font);
    sfText_setFont(value->nbr_key, value->font);
    sfText_setFont(value->nbr_bomb, value->font);
    sfText_setStyle(value->nbr_arrow, sfTextBold);
    sfText_setStyle(value->nbr_ruby, sfTextBold);
    sfText_setStyle(value->nbr_key, sfTextBold);
    sfText_setStyle(value->nbr_bomb, sfTextBold);
    sfText_setCharacterSize(value->nbr_arrow, 30);
    sfText_setCharacterSize(value->nbr_ruby, 30);
    sfText_setCharacterSize(value->nbr_key, 30);
    sfText_setCharacterSize(value->nbr_bomb, 30);
    sfText_setPosition(value->nbr_arrow, (sfVector2f){371, 70});
    sfText_setPosition(value->nbr_ruby, (sfVector2f){208, 70});
    sfText_setPosition(value->nbr_key, (sfVector2f){439, 70});
    sfText_setPosition(value->nbr_bomb, (sfVector2f){299, 70});
}

void init_hud(equipment *stuff, float zoom_level)
{
    init_text(&stuff->value_display);
    stuff->health_clock = sfClock_create();
    stuff->regeneration = sfClock_create();
    stuff->sprite = sfSprite_create();
    stuff->texture = sfTexture_createFromFile("./assets/hud.png", NULL);
    sfSprite_setTexture(stuff->sprite, stuff->texture, sfFalse);
    sfSprite_setTextureRect(stuff->sprite, hud_rects[0]);
    sfSprite_setScale(stuff->sprite, vec_same(zoom_level));
    init_heart(stuff, &stuff->hearts, zoom_level);
    stuff->arrow = 0;
    stuff->health = 5;
    stuff->old_health = 5;
    stuff->lose_health = 0;
    stuff->clining = -1;
    stuff->loop = 0;
    stuff->ruby = 0;
    stuff->key = 0;
    stuff->bomb = 0;
    stuff->max_health = 10;
}

void display_value(sfRenderWindow *win, equipment *stuff, text *value)
{
    char *arr[30];
    char *ruby[30];
    char *key[30];
    char *bomb[30];
    itoa(stuff->arrow, arr);
    itoa(stuff->ruby, ruby);
    itoa(stuff->key, key);
    itoa(stuff->bomb, bomb);
    sfText_setString(value->nbr_arrow, arr);
    sfText_setString(value->nbr_ruby, ruby);
    sfText_setString(value->nbr_key, key);
    sfText_setString(value->nbr_bomb, bomb);
    sfRenderWindow_drawText(win, value->nbr_arrow, NULL);
    sfRenderWindow_drawText(win, value->nbr_ruby, NULL);
    sfRenderWindow_drawText(win, value->nbr_key, NULL);
    sfRenderWindow_drawText(win, value->nbr_bomb, NULL);
}

void display_hud(equipment *stuff, sfRenderWindow *win)
{
    int ms = GET_ELAPSED_MSECS(stuff->health_clock);
    sfRenderWindow_drawSprite(win, stuff->sprite, NULL);
    display_value(win, stuff, &stuff->value_display);
    if (ms > 200) {
        stuff->clining *= -1;
        sfClock_restart(stuff->health_clock);
        if (stuff->loop > 5 && stuff->health > 2) {
            stuff->clining = -1;
            stuff->lose_health = 0;
            stuff->loop = 0;
        }
        stuff->loop += 1;
    }
    if (stuff->clining == -1 || stuff->lose_health == 0) {
        display_health(win, stuff->health, stuff->max_health, &stuff->hearts);
    }
}