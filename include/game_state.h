#ifndef GLOBAL_STATE_H
#define GLOBAL_STATE_H

#include <SFML/Graphics.h>

#include "../components/textboxes/textboxes.h"

typedef struct {
    int argc;
    char **argv;

    int display_help;

    int exit_code;

    float width, height;

    sfVideoMode mode;
    sfRenderWindow *win;
    sfEvent event;

    textbox_state textbox;

} global_state;

#endif