#ifndef GLOBAL_STATE_H
#define GLOBAL_STATE_H

#include <SFML/Graphics.h>

#include "../components/textboxes/textbox.h"

typedef struct global_state global_state;

struct scene {
    void *(*init)(global_state *game_state);
    int (*update)(void *data);
    int (*handle_events)(void *data, sfEvent event);
    int (*destroy)(void *data);
    int (*draw)(void *data, sfRenderWindow *win);
};

#define SCENE_DB_ENTRY(name) \
    (struct scene){ \
        name##_##init, \
        name##_##update, \
        name##_##handle_events, \
        name##_##destroy, \
        name##_##draw, \
    }

typedef struct global_state {
    int argc;
    char **argv;

    float zoom_level;

    int display_help;

    int exit_code;

    float width, height;

    sfVideoMode mode;
    sfRenderWindow *win;
    sfEvent event;

    int continue_loop;

    int scene_id;
    void *scene_state;

    struct scene scenes_db[20];
} global_state;

#endif