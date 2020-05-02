#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML/Graphics.h>

#include "../../generated_code/rects.h"

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"
#include "../../lib/int_to_char.h"

#include "../lib/animation.h"
#include "../lib/map.h"

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

    sfText *level_text;
    sfFont *font;
    sfRectangleShape *xp_shape;
    sfRectangleShape *xp_prog;
    int xp;
    int step;
    int level;
    float coef_prog;

    sfClock *clock;
    sfSprite *select;
    int cursor_pos;
    int cursor_old;
    int cursor_item;
    int clining;

    sfSprite *boomrang_sp;
    sfSprite *lantern_sp;

    int equiped;
    int boomrang;
    int lock;
} items;

slot_inventory slot[20];

void draw_xp(items *item);
int add_item(items *item, int id);
void mouse_cursor(items *item, sfEvent event);
void draw_def(items *item);
void draw_item(items *item);
void init_inventory(items *item, int zoom_level, float width, float height);
void display_inventory(sfRenderWindow *win, items *lnk_item);
void inventory_interaction(items *item, sfEvent event);
void draw_content(items *item);

#endif