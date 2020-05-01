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

long global_get_elapsed_mil(sfClock *clock)
{
    sfClock *clo = clock;
    if (!(clo)) {
        clo = sfClock_create();
        if (!(clo))
            return (-1);
        return (0);
    }

    return GET_ELAPSED_MSECS(clo);
}

float update_time(sfClock *clock)
{
    float elapsed = global_get_elapsed_mil(clock);

    return (elapsed);
}

void DECORATE(sword_anim)(DECORATE(state) *state)
{
    if (state->time < 15900) {
        if (state->my_intro.sword.position.y <= 90) {
            state->my_intro.sword.position.y += 10;
            entity_set_position(&state->my_intro.sword, 
            (sfVector2f){state->my_intro.sword.position.x,
            state->my_intro.sword.position.y});
        }
    }
}

void DECORATE(stars_change)(DECORATE(state) *state)
{
    if (state->my_intro.stars_change > 0) {
        if (state->my_intro.stars.position.x == 460 && 
        state->my_intro.stars.position.y == 230) {
            state->my_intro.stars.position.x = 340;
            state->my_intro.stars.position.y = 370;
        } else if (state->my_intro.stars.position.x == 340 && 
                state->my_intro.stars.position.y == 370) {
            state->my_intro.stars.position.x = 130;
            state->my_intro.stars.position.y = 250;
        } else if (state->my_intro.stars.position.x == 130 && 
                state->my_intro.stars.position.y == 250) {
            state->my_intro.stars.position.x = 620;
            state->my_intro.stars.position.y = 370;
        } else {
            state->my_intro.stars.position.x = 460;
            state->my_intro.stars.position.y = 230;
        }
        animation_set_position(&state->my_intro.stars, (sfVector2f){
        state->my_intro.stars.position.x, state->my_intro.stars.position.y});
        state->my_intro.stars_change = 0;
    }
}

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
    if (state->time > 13000) {
        state->my_intro.tri_first = 0;
        state->my_intro.sword.is_drawable = 1;
        state->my_intro.zelda_z.is_drawable = 1;
        DECORATE(sword_anim(state));
    }
}

void DECORATE(fifth_update)(DECORATE(state) *state)
{
    if (state->time > 16000) {
        state->my_intro.backgrd.is_drawable = 1;
        state->my_intro.stars.is_drawable = 1;
        state->my_intro.stars_update = 1;
    }
}

void DECORATE(draw_update)(DECORATE(state) *state)
{
    DECORATE(first_update(state));
    DECORATE(second_update(state));
    DECORATE(third_update(state));
    DECORATE(fourth_update(state));
    DECORATE(fifth_update(state));
}

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    intro *intro = &state->my_intro;

    if (update_textbox(&scene_state(data)->textbox) < 0)
        return (-1);
    state->time = update_time(state->glo_clock);

    if (state->tri_update > 0) {
        if (animation_update(&state->my_intro.triforce, 70) == 2)
            state->tri_update = 0;
    }
    if (state->my_intro.stars_update > 0) {
        if (animation_update(&state->my_intro.stars, 130) == 3)
            state->my_intro.stars_change = 1;
    }
    DECORATE(stars_change(state));
    DECORATE(draw_update(state));
    
    return (0);
}
