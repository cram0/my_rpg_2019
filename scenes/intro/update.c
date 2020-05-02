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

const char MONOLOG[] = "Long ago, in the beautiful\n kingdom of Hyrule surrounded\n by mountains and forests...\n legends told of an omnipotent\n and omniscient Golden Power\n that resided in a hidden land.";
const char MONOLOG2[] = "Many people aggressively\n sought to enter the hidden\n Golden Land...\n But no one ever returned.\n One day evil power began to\n flow from the Golden Land...";

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

void DECORATE(monolog_start)(DECORATE(state) *state)
{
    if (state->my_intro.monolog == 1) {
        setstring_textbox(&state->textbox, MONOLOG);
        state->my_intro.monolog = 4;
    }
    if (state->my_intro.monolog2 == 1) {
        setstring_textbox(&state->textbox, MONOLOG2);
        state->my_intro.monolog2 = 4;
    }
}

void DECORATE(draw_update)(DECORATE(state) *state)
{
    DECORATE(first_update(state));
    DECORATE(second_update(state));
    DECORATE(third_update(state));
    DECORATE(fourth_update(state));
    DECORATE(fifth_update(state));
    if (state->time > 25000) {
        DECORATE(disable_draws(state));
        state->my_intro.images.is_drawable = 1;
        if (state->my_intro.monolog == 0)
            state->my_intro.monolog = 1;
        DECORATE(monolog_start(state));
    }
    if (state->time > 41000) {
        if (state->my_intro.monolog2 == 0)
            state->my_intro.monolog2 = 1;
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
