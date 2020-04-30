#include "inventory.h"

slot_inventory slot[] = {
    {.x = 32, .y = 32, .occuped = 0},
    {.x = 32 + 24 * 1, .y = 32, .occuped = 0},
    {.x = 32 + 24 * 2, .y = 32, .occuped = 0},
    {.x = 32 + 24 * 3, .y = 32, .occuped = 0},
    {.x = 32 + 24 * 4, .y = 32, .occuped = 0},

    {.x = 32, .y = 32 + 24 * 1, .occuped = 0},
    {.x = 32 + 24 * 1, .y = 32 + 24 * 1, .occuped = 0},
    {.x = 32 + 24 * 2, .y = 32 + 24 * 1, .occuped = 0},
    {.x = 32 + 24 * 3, .y = 32 + 24 * 1, .occuped = 0},
    {.x = 32 + 24 * 4, .y = 32 + 24 * 1, .occuped = 0},

    {.x = 32, .y = 32 + 24 * 2, .occuped = 0},
    {.x = 32 + 24 * 1, .y = 32 + 24 * 2, .occuped = 0},
    {.x = 32 + 24 * 2, .y = 32 + 24 * 2, .occuped = 0},
    {.x = 32 + 24 * 3, .y = 32 + 24 * 2, .occuped = 0},
    {.x = 32 + 24 * 4, .y = 32 + 24 * 2, .occuped = 0},

    {.x = 32, .y = 32 + 24 * 3, .occuped = 0},
    {.x = 32 + 24 * 1, .y = 32 + 24 * 3, .occuped = 0},
    {.x = 32 + 24 * 2, .y = 32 + 24 * 3, .occuped = 0},
    {.x = 32 + 24 * 3, .y = 32 + 24 * 3, .occuped = 0},
    {.x = 32 + 24 * 4, .y = 32 + 24 * 3, .occuped = 0},
};

int find_place(void)
{
    int place = 0;
    while (slot[place].occuped != 0) {
        if (place == 20) {
            return (-1);
        }
        place++;
    }
    return (place);
}

int add_item(items *item, int id)
{
    int place = find_place();
    if (place == -1)
        return (1);

    slot[place].occuped = id;

    return 0;   
}

void display_item(items *item, int index)
{
    int id = slot[index].occuped;
    if (id == 1) {
        sfSprite_setPosition(item->boomrang_sp,
                            (sfVector2f){slot[index].x, slot[index].y});
        sfRenderTexture_drawSprite(item->window_inv, item->boomrang_sp, NULL);
    }
    if (id == 2) {
        sfSprite_setPosition(item->lantern_sp,
                            (sfVector2f){slot[index].x, slot[index].y});
        sfRenderTexture_drawSprite(item->window_inv, item->lantern_sp, NULL);
    }
}

void draw_item(items *item)
{
    for (int i = 0; i < 20; i++) {
        if (slot[i].occuped != 0) {
            display_item(item, i);
        }
    }
}

void draw_content(items *item)
{
    int cursor = item->cursor_pos;
    sfTexture *texture = NULL;
    sfRenderTexture_clear(item->window_inv, sfTransparent);
  
    sfSprite_setPosition(item->select,
                        (sfVector2f){slot[cursor].x - 8, slot[cursor].y - 8});

    sfRenderTexture_drawSprite(item->window_inv, item->back_inventory, NULL);
    draw_item(item);
    draw_def(item);
    sfRenderTexture_drawSprite(item->window_inv, item->select, NULL);

    sfRenderTexture_display(item->window_inv);

    texture = (sfTexture *)sfRenderTexture_getTexture(item->window_inv);
    sfSprite_setTexture(item->inventory, texture, sfFalse);
}