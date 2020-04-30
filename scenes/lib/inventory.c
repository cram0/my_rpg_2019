#include "inventory.h"

void init_item(items *item)
{
    item->boomrang_sp = sfSprite_create();
    item->lantern_sp = sfSprite_create();

    sfSprite_setTexture(item->boomrang_sp, item->object_texture, sfFalse);
    sfSprite_setTexture(item->lantern_sp, item->object_texture, sfFalse);

    sfSprite_setTextureRect(item->boomrang_sp, hud_boomerang_rects[0]);
    sfSprite_setTextureRect(item->lantern_sp, hud_lantern_rects[0]);
}

void init_def(items *item)
{
    item->def_boom = sfSprite_create();
    item->def_lantern = sfSprite_create();

    sfSprite_setTexture(item->def_boom, item->hud_texture, sfFalse);
    sfSprite_setTexture(item->def_lantern, item->hud_texture, sfFalse);

    sfSprite_setTextureRect(item->def_boom, hud_def_boomrang_rects[0]);
    sfSprite_setTextureRect(item->def_lantern, hud_def_lantern_rects[0]);

    sfSprite_setPosition(item->def_boom, (sfVector2f){175, 40});
    sfSprite_setPosition(item->def_lantern, (sfVector2f){175, 40});
}

void init_inventory(items *item, int zoom_level, float width, float height)
{
    item->hud_texture = sfTexture_createFromFile("./assets/hud_pause.png",
                                                NULL);
    item->object_texture = sfTexture_createFromFile("./assets/hud.png",
                                                NULL);
    item->inventory = sfSprite_create();
    item->window_inv = sfRenderTexture_create(width, height, sfFalse);
    item->back_inventory = sfSprite_create();
    sfSprite_setTexture(item->back_inventory, item->hud_texture, sfFalse);
    sfSprite_setTextureRect(item->back_inventory, hud_pause_rects[0]);
    item->select = sfSprite_create();
    sfSprite_setTexture(item->select, item->hud_texture, sfFalse);
    sfSprite_setTextureRect(item->select, hud_select_rects[0]);
    sfSprite_setPosition(item->select,
                        (sfVector2f){slot[0].x - 8, slot[0].y - 8});
    init_item(item);
    init_def(item);
    item->clock = sfClock_create();
    add_item(item, 1);
    add_item(item, 2);
    add_item(item, 1);
    sfSprite_setScale(item->inventory, vec_same(zoom_level));
    sfSprite_setPosition(item->inventory,
                            (sfVector2f){0.0, -244 * zoom_level});
    item->clining = 1;
    item->lock = 0;
    item->cursor_pos = 0;
    item->cursor_item = 0;
    item->equiped = 0;
}

void draw_equiped_item(sfRenderWindow *win, items *item)
{
    int id = item->equiped;
    if (id == 1) {
        sfSprite_setScale(item->boomrang_sp, (sfVector2f){3, 3});
        sfSprite_setPosition(item->boomrang_sp,
                            (sfVector2f){40 * 3, 23 * 3});
        sfRenderWindow_drawSprite(win, item->boomrang_sp, NULL);
        sfSprite_setScale(item->boomrang_sp, (sfVector2f){1, 1});
    }
    if (id == 2) {
        sfSprite_setScale(item->lantern_sp, (sfVector2f){3, 3});
        sfSprite_setPosition(item->lantern_sp,
                            (sfVector2f){40 * 3, 23 * 3});
        sfRenderWindow_drawSprite(win, item->lantern_sp, NULL);
        sfSprite_setScale(item->lantern_sp, (sfVector2f){1, 1});
    }
}

void display_inventory(sfRenderWindow *win, items *lnk_item)
{
    sfVector2f loca = sfSprite_getPosition(lnk_item->inventory);
    draw_equiped_item(win, lnk_item);
    draw_content(lnk_item);
    if (lnk_item->lock == 1) {
        if (loca.y < 0.0) {
            sfSprite_move(lnk_item->inventory, (sfVector2f){0.0, 15.0});
        }
        sfRenderWindow_drawSprite(win, lnk_item->inventory, NULL);
    }
    if (lnk_item->lock == 2) {
        if (loca.y > (-224 * 3)) {
            sfSprite_move(lnk_item->inventory, (sfVector2f){0.0, -15.0});
        } else {
            lnk_item->lock = 0;
        }
        sfRenderWindow_drawSprite(win, lnk_item->inventory, NULL);
    }
}