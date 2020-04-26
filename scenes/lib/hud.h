#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.h>

#include "../../generated_code/rects.h"

#include "../../include/sfml_helpers.h"

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect *rects;
    int health;
    int ruby;
    int arrow;
    int key;
} equipment;

void init_hud(equipment *stuff, float zoom_level);
void display_hud(equipment *stuff, sfRenderWindow *win);

#endif