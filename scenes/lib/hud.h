#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.h>

#include "../../generated_code/rects.h"

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"

#include "../../lib/int_to_char.h"

typedef struct {
    sfFont *font;
    sfText *nbr_ruby;
    sfText *nbr_arrow;
    sfText *nbr_bomb;
    sfText *nbr_key;
} text;

typedef struct {
    sfSprite *heart_1;
    sfSprite *heart_2;
    sfSprite *heart_3;
    sfTexture *texture1;
    sfTexture *texture2;
    sfTexture *texture3;
} health;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rects;
    text value_display;
    health hearts;
    int health;
    int ruby;
    int arrow;
    int key;
    int bomb;
    int max_health
} equipment;

void init_hud(equipment *stuff, float zoom_level);
void init_heart(equipment *stuff, health *hearts, int zoom_level);
void display_hud(equipment *stuff, sfRenderWindow *win);
void display_health(sfRenderWindow *win, int life, int max, health *hearts);

#endif