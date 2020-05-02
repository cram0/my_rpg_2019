#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"
#include "../lib/sprite_paths.h"

int DECORATE(nintendo_init)(DECORATE(state) *state)
{
    entity *nintendo = &state->my_intro.nintendo;
    nintendo->is_drawable = 1;

    if (entity_load_spritesheet(nintendo, NINTENDO_PATH) < 0)
        return (-1);
    
    entity_set_zoom(nintendo, (float){3.0});
    entity_set_position(nintendo, (sfVector2f){300.0, 300.0});

    return (0);
}

int DECORATE(copyright_init)(DECORATE(state) *state)
{
    entity *copyright = &state->my_intro.copyright;
    copyright->is_drawable = 0;

    if (entity_load_spritesheet(copyright, COPYRIGHT_PATH) < 0)
        return (-1);

    entity_set_zoom(copyright, (float){3.5});
    entity_set_position(copyright, (sfVector2f){270.0, 550.0});

    return (0);
}

int DECORATE(zelda_init)(DECORATE(state) *state)
{
    entity *zelda = &state->my_intro.zelda;
    zelda->is_drawable = 0;

    if (entity_load_spritesheet(zelda, ZELDA_PATH) < 0)
        return (-1);

    entity_set_zoom(zelda, 3.5);
    entity_set_position(zelda, (sfVector2f){140, 220.0});

    return (0);
}

int DECORATE(subtitle_init)(DECORATE(state) *state)
{
    entity *subtitle = &state->my_intro.subtitle;
    subtitle->is_drawable = 0;

    if (entity_load_spritesheet(subtitle, SUBTITLE_PATH) < 0)
        return (-1);

    entity_set_zoom(subtitle, 3.0);
    entity_set_position(subtitle, (sfVector2f){300.0, 410.0});

    return (0);
}

int DECORATE(tlo_init)(DECORATE(state) *state)
{
    entity *tlo = &state->my_intro.tlo;
    tlo->is_drawable = 0;

    if (entity_load_spritesheet(tlo, TLO_PATH) < 0)
        return (-1);

    entity_set_zoom(tlo, 3.0);
    entity_set_position(tlo, (sfVector2f){290.0, 190.0});

    return (0);
}

int DECORATE(triforce_init)(DECORATE(state) *state)
{
    animation *tri = &state->my_intro.triforce;
    tri->invert_y = 0;

    animation_set_zoom(tri, 3.2);
    if (animation_load_spritesheet(tri, TRIFORCE_PATH) < 0)
        return (-1);

    animation_set_position(tri, (sfVector2f){130.0, 45.0});
    m_animation_set_rects(tri, triforce);

    return (0);
}

int DECORATE(stars_init)(DECORATE(state) *state)
{
    animation *stars = &state->my_intro.stars;
    stars->invert_y = 0;

    animation_set_zoom(stars, 3.2);
    if (animation_load_spritesheet(stars, STARS_PATH) < 0)
        return (-1);

    stars->is_drawable = 0;
    animation_set_position(stars, (sfVector2f){460.0, 230.0});
    m_animation_set_rects(stars, small_shine);

    return (0);
}

int DECORATE(background_init)(DECORATE(state) * state)
{
    entity *backgrd = &state->my_intro.backgrd;
    backgrd->is_drawable = 0;

    if (entity_load_spritesheet(backgrd, BCKGRD_PATH) < 0)
        return (-1);

    entity_set_zoom(backgrd, 3.0);
    entity_set_position(backgrd, (sfVector2f){0.0, 40.0});

    return (0);
}

int DECORATE(sword_init)(DECORATE(state) *state)
{
    entity *sword = &state->my_intro.sword;
    sword->is_drawable = 0;
    sword->position.x = 170;
    sword->position.y = -500;

    if (entity_load_spritesheet(sword, SWORD_PATH) < 0)
        return (-1);

    entity_set_zoom(sword, 3.0);
    entity_set_position(sword, (sfVector2f){170.0, -500.0});

    return (0);
}

int DECORATE(zelda_z_init)(DECORATE(state) *state)
{
    entity *zelda_z = &state->my_intro.zelda_z;
    zelda_z->is_drawable = 0;

    if (entity_load_spritesheet(zelda_z, ZELDA_Z_PATH) < 0)
        return (-1);

    entity_set_zoom(zelda_z, 3.5);
    entity_set_position(zelda_z, (sfVector2f){140, 220.0});

    return (0);
}

int DECORATE(assets_init)(DECORATE(state) *state, float width, float height)
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

    float w = game_state->width;
    float h = game_state->height;

    DEBUG("starting scene %s", "intro");

    if (run_once == 0) {
        scene_state.zoom_level = game_state->zoom_level;
        init_textbox(&scene_state.textbox, game_state->width, game_state->height);

        if (DECORATE(assets_init)(&scene_state, w, h) < 0)
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