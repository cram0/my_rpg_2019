#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

// TO COMPLETE //

const char NINTENDO_PATH[] = "assets/title_screen/nintendo_presents.png";
const char COPYRIGHT_PATH[] = "assets/title_screen/copyright.png";
const char TRIFORCE_PATH[] = "assets/title_screen/triforce.png";
const char SWORD_PATH[] = "assets/title_screen/logo_sword.png";
const char STARS_PATH[] = "assets/title_screen/small_shine.png";

int DECORATE(assets_init)(DECORATE(state) *state)
{
    animation *tri_ani = &state->my_intro.triforce;
    animation *stars = &state->my_intro.stars;
    animation *sword = &state->my_intro.sword;
    entity *nintendo = &state->my_intro.nintendo;
    entity *copyright = &state->my_intro.copyright;

    if (animation_load_spritesheet(tri_ani, TRIFORCE_PATH) < 0)
        return (-1);
    if (animation_load_spritesheet(sword, SWORD_PATH) < 0)
        return (-1);
    if (animation_load_spritesheet(stars, STARS_PATH) < 0)
        return (-1);
    if (entity_load_spritesheet(nintendo, NINTENDO_PATH) < 0)
        return (-1);
    if (entity_load_spritesheet(copyright, COPYRIGHT_PATH) < 0)
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
    }

    scene_state.game_state = game_state;
    game_state->scene_state = (void *)&scene_state;

    return (game_state->scene_state);
}