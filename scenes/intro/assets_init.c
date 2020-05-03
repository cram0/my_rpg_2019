#include "decorator.h"

#include "state.h"
#include "init.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"
#include "../lib/sprite_paths.h"

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