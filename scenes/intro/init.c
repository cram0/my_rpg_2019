#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"

void *DECORATE(init)(global_state *game_state)
{
    static int run_once;
    static DECORATE(state) scene_state;

    DEBUG("starting scene %s", "intro");

    if (run_once == 0) {
        scene_state.zoom_level = game_state->zoom_level;
        init_textbox(&scene_state.textbox, game_state->width, game_state->height);
        run_once = 1;
    }

    scene_state.game_state = game_state;
    game_state->scene_state = (void *)&scene_state;

    return (game_state->scene_state);
}