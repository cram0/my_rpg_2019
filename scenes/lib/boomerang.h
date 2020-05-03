#ifndef BOOMERANG_H
#define BOOMERANG_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>

#include "../../generated_code/rects.h"
#include "../../generated_code/origins.h"

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"

#include "../lib/animation.h"
#include "../lib/map.h"

typedef struct {
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    sfClock *sound_clock;

    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *shape;

    sfVector2f old_origine;
    sfVector2f origine;
    sfVector2f ori_launch;
    
    sfVector2f old_pos;
    sfVector2f old_pos_sprite;

    int direction;
    int equiped;
    int launch;
    int back;
    int last_mob_id;
} boomerang;

int distance(sfVector2f pt1, sfVector2f pt2, int max);
void move_boomrang(boomerang *boomr);
void boomerang_launch(boomerang *boomr, int dir, sfEvent event);
void init_boomerang(boomerang *boomr, float zoom_level,
                    float width, float height, sfVector2f map_pos);
void boomerang_draw(sfRenderWindow *win, boomerang *boomr, sfVector2f map_pos);

#endif