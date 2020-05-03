#include "game_over.h"

void init_game_over(game_over *gmv, float zoom_level, sfVector2f pos)
{
    gmv->clock = NULL;
    gmv->sprite = sfSprite_create();
    gmv->texture = sfTexture_createFromFile("./assets/link.gif", NULL);
    gmv->rects = link_falling_rects;
    sfSprite_setTexture(gmv->sprite, gmv->texture, sfFalse);
    sfSprite_setTextureRect(gmv->sprite, gmv->rects[0]);
    sfSprite_setScale(gmv->sprite, vec_same(zoom_level));
    sfSprite_setPosition(gmv->sprite, pos);
    gmv->index = 0;
}

void display_game_over(sfRenderWindow *win, game_over *gmv, textbox_state *txt)
{
    if (gmv->clock == NULL) {
        gmv->clock = sfClock_create();
        setstring_textbox(txt, "GAME OVER LINK\npress: Q to quit");
    }
    int ms = GET_ELAPSED_MSECS(gmv->clock);

    sfRenderWindow_drawSprite(win, gmv->sprite, NULL);

    if (ms > 700 && !rect_iszero(gmv->rects[gmv->index])) {
        gmv->index += 1;
        sfSprite_setTextureRect(gmv->sprite, gmv->rects[gmv->index]);
        sfClock_restart(gmv->clock);
    }
    draw_textbox(txt, win);
}