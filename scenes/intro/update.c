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

void DECORATE(draw_update)(DECORATE(state) *state)
{
    if (state->time > 1500) {
        state->my_intro.nintendo.is_drawable = 0;
        state->my_intro.copyright.is_drawable = 1;
    }
    if (state->time > 2200) {
        if (state->tri_once == 0) {
            state->tri_update = 1;
            state->tri_once = 1;
        }
        state->my_intro.triforce.is_drawable = 1;
    }
    if (state->time > 11000) {
        state->my_intro.tri_first = 1;
        state->my_intro.zelda.is_drawable = 1;
        state->my_intro.subtitle.is_drawable = 1;
        state->my_intro.tlo.is_drawable = 1;
    }
    if (state->time > 13000) {
        state->my_intro.tri_first = 0;
        state->my_intro.sword.is_drawable = 1;
        state->my_intro.zelda_z.is_drawable = 1;
        DECORATE(sword_anim(state));
    }
    if (state->time > 16000)
        state->my_intro.backgrd.is_drawable = 1;
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

    DECORATE(draw_update(state));
    printf("TIME %f\n", state->time);
    return (0);
}
