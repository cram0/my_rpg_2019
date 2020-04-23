#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "decorator.h"

#include "../../components/textboxes/textbox.h"

typedef struct {
    float zoom_level;

    textbox_state textbox;

    /* in case you really need to access the global_state object */
    void *game_state;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif