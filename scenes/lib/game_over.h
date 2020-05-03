#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "../../generated_code/rects.h"

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"
#include "../../lib/int_to_char.h"

#include "../lib/animation.h"
#include "../lib/map.h"
#include "../lib/helpers.h"

typedef struct {
    sfClock *clock;

    sfSprite *sprite;
    sfTexture *texture;

    sfIntRect *rects;

    int index;
} game_over;

void init_game_over(game_over *gmv, float zoom_level, sfVector2f pos);
void display_game_over(sfRenderWindow *win ,game_over *gmv,
                        textbox_state *text);

#endif