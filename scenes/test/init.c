#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"

const char LINK_PATH[] = "assets/link.gif";

int link_init(DECORATE(state) *state, float width, float height)
{
    animation *ani = &state->my_link.ani;

    if (animation_load_spritesheet(ani, LINK_PATH) < 0)
        return (-1);

    animation_set_zoom(ani, state->zoom_level);
    animation_set_position(ani, vec_center(width, height));
    animation_set_rects(ani, link_right_walk_origs, link_right_walk_rects);

    return (0);
}

void *DECORATE(init)(global_state *game_state)
{
    static int run_once;
    static DECORATE(state) scene_state = { 0 };

    DEBUG("starting scene %s", "test");

    if (run_once == 0) {
        scene_state.zoom_level = game_state->zoom_level;
        if (link_init(&scene_state, game_state->width, game_state->height) < 0)
            return (NULL);
        run_once = 1;
    }

    scene_state.game_state = game_state;
    game_state->scene_state = (void *)&scene_state;

    return (game_state->scene_state);
}