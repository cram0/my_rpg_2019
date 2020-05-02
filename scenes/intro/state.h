#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "decorator.h"

#include "../../components/textboxes/textbox.h"
#include "../lib/animation.h"
#include "lib/entity.h"

typedef struct {
    entity nintendo;
    entity copyright;
    entity tlo;
    entity zelda;
    entity backgrd;
    entity subtitle;
    entity sword;
    entity zelda_z;
    animation triforce;
    animation stars;
    entity images;
    int tri_first;
    int stars_update;
    int stars_change;
    int monolog;
    int monolog2;
} intro;

typedef struct {
    float zoom_level;

    sfClock *glo_clock;
    float time;
    textbox_state textbox;

    intro my_intro;

    int tri_update;
    int tri_once;
    /* in case you really need to access the global_state object */
    void *game_state;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif