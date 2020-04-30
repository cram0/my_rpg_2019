#include "inventory.h"

void draw_def(items *item)
{
    int id = slot[item->cursor_pos].occuped;
    if (id == 0) id = item->cursor_item;
    if (id == 1) {
        sfSprite_setPosition(item->boomrang_sp,
                            (sfVector2f){202, 25});
        sfRenderTexture_drawSprite(item->window_inv, item->boomrang_sp, NULL);
        sfRenderTexture_drawSprite(item->window_inv, item->def_boom, NULL);
    }
    if (id == 2) {
        sfSprite_setPosition(item->lantern_sp,
                            (sfVector2f){202, 25});
        sfRenderTexture_drawSprite(item->window_inv, item->lantern_sp, NULL);
        sfRenderTexture_drawSprite(item->window_inv, item->def_lantern, NULL);
    }
}