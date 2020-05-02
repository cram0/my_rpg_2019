#include "decorator.h"

#include "state.h"
#include "update.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "../lib/animation.h"
#include "../lib/helpers.h"
#include "lib/entity.h"
#include "lib/time.h"

void DECORATE(disable_draws)(DECORATE(state) *state)
{
    state->my_intro.backgrd.is_drawable = 0;
    state->my_intro.copyright.is_drawable  = 0;
    state->my_intro.stars.is_drawable = 0;
    state->my_intro.subtitle.is_drawable = 0;
    state->my_intro.sword.is_drawable = 0;
    state->my_intro.tlo.is_drawable = 0;
    state->my_intro.triforce.is_drawable = 0;
    state->my_intro.zelda.is_drawable = 0;
    state->my_intro.zelda_z.is_drawable = 0;
    state->my_intro.nintendo.is_drawable = 0;
}

void DECORATE(draw_update)(DECORATE(state) *state)
{
    DECORATE(first_update(state));
    DECORATE(second_update(state));
    DECORATE(third_update(state));
    DECORATE(fourth_update(state));
    DECORATE(fifth_update(state));
    DECORATE(six_update(state));
    DECORATE(seven_update(state));
}

void DECORATE(six_update)(DECORATE(state) *state)
{
    if (state->time > 25000) {
        DECORATE(disable_draws(state));
        state->my_intro.images.is_drawable = 1;
        if (state->my_intro.monolog != 4)
            state->my_intro.monolog = 1;
        DECORATE(monolog_start(state));
    }
}

void DECORATE(seven_update)(DECORATE(state) *state)
{
    if (state->time > 41000) {
        if (state->my_intro.monolog2 != 4)
            state->my_intro.monolog2 = 1;
    }
    if (state->time > 55000) {
        if (state->my_intro.monolog3 != 4)
            state->my_intro.monolog3 = 1;
    }
    if (state->time > 63000) {
        if (state->my_intro.monolog4 != 4)
            state->my_intro.monolog4 = 1;
    }
    if (state->time > 68000) {
        if (state->my_intro.monolog5 != 4)
            state->my_intro.monolog5 = 1;
    }
}

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    intro *intro = &state->my_intro;

    if (update_textbox(&scene_state(data)->textbox) < 0)
        return (-1);
    state->time = update_time(state->glo_clock);

    if (state->tri_update > 0) {
        animation_update(&state->my_intro.triforce, 70);
        if (state->my_intro.triforce.frame > 86)
            state->tri_update = 0;
    }
    int old_frame = state->my_intro.stars.frame;
    if (state->my_intro.stars_update > 0) {
        animation_update(&state->my_intro.stars, 130);
    }
    if (state->my_intro.stars.frame >= 3 && state->my_intro.stars.frame != old_frame) {
        state->my_intro.stars_change = 1;
        DECORATE(stars_change(state));
    }
    DECORATE(draw_update(state));
    DEBUG("TIME %f\n", state->time);
    return (0);
}
