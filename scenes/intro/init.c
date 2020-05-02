#include "decorator.h"

#include "state.h"
#include "init.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"
#include "../lib/sprite_paths.h"

int DECORATE(assets_init)(DECORATE(state) *state)
{
    if (DECORATE(nintendo_init)(state) < 0)
        return (-1);
    if (DECORATE(copyright_init)(state) < 0)
        return (-1);
    if (DECORATE(triforce_init)(state) < 0)
        return (-1);
    if (DECORATE(stars_init)(state) < 0)
        return (-1);
    if (DECORATE(zelda_init)(state) < 0)
        return (-1);
    if (DECORATE(zelda_z_init)(state) < 0)
        return (-1);
    if (DECORATE(subtitle_init)(state) < 0)
        return (-1);
    if (DECORATE(tlo_init)(state) < 0)
        return (-1);
    if (DECORATE(background_init)(state) < 0)
        return (-1);
    if (DECORATE(sword_init)(state) < 0)
        return (-1);
    return (0);
}

void *DECORATE(init)(global_state *game_state)
{
    static int run_once;
    static DECORATE(state) scene_state;

    DEBUG("starting scene %s", "intro");

    if (run_once == 0) {
        scene_state.zoom_level = game_state->zoom_level;
        init_textbox(&scene_state.textbox, game_state->width, game_state->height);

        if (DECORATE(assets_init)(&scene_state) < 0)
            return (NULL);
        
        run_once = 1;
        scene_state.tri_update = 0;
        scene_state.tri_once = 0;
        scene_state.my_intro.stars_change = 0;
        scene_state.my_intro.stars_update = 0;
        scene_state.my_intro.tri_first = 1;
    }

    scene_state.glo_clock = sfClock_create();
    scene_state.game_state = game_state;
    game_state->scene_state = (void *)&scene_state;

    return (game_state->scene_state);
}