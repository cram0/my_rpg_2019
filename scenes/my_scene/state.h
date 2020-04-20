#ifndef MY_SCENE_STATE_H
#define MY_SCENE_STATE_H

#include "decorator.h"

#include "../../components/textboxes/textbox.h"

typedef struct {
    textbox_state textbox;
} DECORATE(state);

#define scene_state(data) ((DECORATE(state) *)data)

#endif