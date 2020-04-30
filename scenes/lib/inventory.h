#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML/Graphics.h>

#include "../../generated_code/rects.h"

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"

typedef struct {
    int x;
    int y;
    int occuped;
} slot_inventory;

typedef struct {
    sfSprite *inventory;
    sfRenderTexture *window_inv;
    sfTexture *hud_texture;
    sfTexture *object_texture;

    sfSprite *back_inventory;

    sfSprite *def_boom;
    sfSprite *def_lantern;

    sfSprite *select;
    int cursor_pos;
    int cursor_old;
    int cursor_item;

    sfSprite *boomrang_sp;
    sfSprite *lantern_sp;

    int equiped;
    int boomrang;
    int lock;
} items;

slot_inventory slot[20];

int add_item(items *item, int id);
void draw_def(items *item);
void draw_item(items *item);
void init_inventory(items *item, int zoom_level, float width, float height);
void display_inventory(sfRenderWindow *win, items *lnk_item);
void inventory_interaction(items *item, sfEvent event);
void draw_content(items *item);

#endif