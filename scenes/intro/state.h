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
    animation triforce;
    animation stars;
    animation sword;
    int tri_first;

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