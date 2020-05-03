#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "../lib/animation.h"
#include "../lib/helpers.h"
#include "lib/entity.h"
#include "lib/time.h"
#include "update.h"

void DECORATE(first_update)(DECORATE(state) *state)
{
    if (state->time > 1500) {
        state->my_intro.nintendo.is_drawable = 0;
        state->my_intro.copyright.is_drawable = 1;
    }
}

void DECORATE(second_update)(DECORATE(state) *state)
{
    if (state->time > 2200) {
        if (state->tri_once == 0) {
            state->tri_update = 1;
            state->tri_once = 1;
        }
        state->my_intro.triforce.is_drawable = 1;
    }
    if (state->time > 4000) {
        if (state->tri_once == 1) {
            state->tri_once = 5;
            sfMusic_play(state->music);
        }
    }
}

void DECORATE(third_update)(DECORATE(state) *state)
{
    if (state->time > 11000) {
        state->my_intro.tri_first = 1;
        state->my_intro.zelda.is_drawable = 1;
        state->my_intro.subtitle.is_drawable = 1;
        state->my_intro.tlo.is_drawable = 1;
    }
}

void DECORATE(fourth_update)(DECORATE(state) *state)
{
    if (state->time > 12300) {
        state->my_intro.tri_first = 0;
        state->my_intro.sword.is_drawable = 1;
        state->my_intro.zelda_z.is_drawable = 1;
        DECORATE(sword_anim(state));
    }
}

void DECORATE(fifth_update)(DECORATE(state) *state)
{
    if (state->time > 14000) {
        state->my_intro.backgrd.is_drawable = 1;
        state->my_intro.stars.is_drawable = 1;
        state->my_intro.stars_update = 1;
    }
}