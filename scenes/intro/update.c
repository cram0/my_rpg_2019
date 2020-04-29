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

void DECORATE(draw_update)(DECORATE(state) *state)
{
    if (state->time > 1500) {
        state->my_intro.nintendo.is_drawable = 0;
        state->my_intro.copyright.is_drawable = 1;
        state->tri_draw = 1;
    }
}

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    intro *intro = &state->my_intro;

    if (update_textbox(&scene_state(data)->textbox) < 0)
        return (-1);
    state->time = update_time(state->glo_clock);
    if (state->tri_draw > 0) {
        animation_update(&state->my_intro.triforce, 50);
        animation_set_position(&state->my_intro.triforce, (sfVector2f){0.0, 0.0});
    }

    DECORATE(draw_update(state));
    printf("TIME %f\n", state->time);
    return (0);
}
