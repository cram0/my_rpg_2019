#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "decorator.h"

#include "../../components/textboxes/textbox.h"
#include "../lib/animation.h"
#include "lib/entity.h"

typedef struct {
    entity nintendo;
    entity copyright;
    animation triforce;
    animation stars;
    animation sword;

} intro;

typedef struct {
    float zoom_level;

    textbox_state textbox;

    intro my_intro;

    /* in case you really need to access the global_state object */
    void *game_state;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif