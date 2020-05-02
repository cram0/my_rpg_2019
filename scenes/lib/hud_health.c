#include "hud.h"

void lose_health_animation(equipment *stuff)
{
    if (stuff->lose_health == 0) {
        if (stuff->old_health != stuff->health) {
            stuff->lose_health = 1;
            sfClock_restart(stuff->health_clock);
        }
        stuff->old_health = stuff->health;
    }
}

void health_regeneration(equipment *stuff)
{
    int ms = GET_ELAPSED_MSECS(stuff->regeneration);
    if (ms > 20000) {
        if (stuff->health >= stuff->max_health) {
            sfClock_restart(stuff->regeneration);
        } else {
            stuff->health += 1;
        }
    }
}

void init_heart(equipment *stuff, health *hearts, int zoom_level)
{
    hearts->heart_1 = sfSprite_create();
    hearts->heart_2 = sfSprite_create();
    hearts->heart_3 = sfSprite_create();
    sfSprite_setTexture(hearts->heart_1, stuff->texture, sfFalse);
    sfSprite_setTexture(hearts->heart_2, stuff->texture, sfFalse);
    sfSprite_setTexture(hearts->heart_3, stuff->texture, sfFalse);
    sfSprite_setTextureRect(hearts->heart_1, hud_heart_full_rects[0]);
    sfSprite_setScale(hearts->heart_1, vec_same(zoom_level));
    sfSprite_setTextureRect(hearts->heart_2, hud_heart_half_rects[0]);
    sfSprite_setScale(hearts->heart_2, vec_same(zoom_level));
    sfSprite_setTextureRect(hearts->heart_3, hud_heart_empty_rects[0]);
    sfSprite_setScale(hearts->heart_3, vec_same(zoom_level));
}

void sprite_copy(sfRenderWindow *win, sfSprite *sprite, int actual)
{
        sfSprite_setPosition(sprite, (sfVector2f){actual, 72});
        sfRenderWindow_drawSprite(win, sprite, NULL);
}

void display_health(sfRenderWindow *win, int life, int max, health *hearts)
{
    sfSprite *tmp = sfSprite_create();
    int actual = 483, step = 24;
    int heart_fill = 0, heart_semi = 0, heart_empty = 0;
    heart_fill = life - (life % 2), heart_semi = life % 2;
    heart_empty = max - heart_fill - heart_semi;

    tmp = sfSprite_copy(hearts->heart_3);
    for (int i = 0; i < heart_fill / 2; i++, actual += step)
        sprite_copy(win, tmp, actual);

    tmp = sfSprite_copy(hearts->heart_2);
    if (heart_semi != 0) {
        sprite_copy(win, tmp, actual);
        actual += step; 
    }

    tmp = sfSprite_copy(hearts->heart_1);
    for (int i = 0; i < heart_empty / 2; i++, actual += step) 
        sprite_copy(win, tmp, actual);
}