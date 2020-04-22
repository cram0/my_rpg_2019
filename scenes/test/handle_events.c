#include "decorator.h"
#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"

static int is_valid_direction()
{
    int up = sfKeyboard_isKeyPressed(sfKeyUp);
    int down = sfKeyboard_isKeyPressed(sfKeyDown);
    int left = sfKeyboard_isKeyPressed(sfKeyLeft);
    int right = sfKeyboard_isKeyPressed(sfKeyRight);
    int sum = up + down + left + right;
    if (sum > 2)
        return (0);
    if (sum == 1 || sum == 0)
        return (1);
    if ((up && left) || (up && right) || (down && left) || (down && right))
        return (1);
    return (0);
}

static void DECORATE(link_direction)(DECORATE(state) *state, sfEvent event)
{
    if (!is_valid_direction())
        return;

    int is_idle = 1;
    state->my_link.ani.invert_y = 0;

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        is_idle = 0;
        state->my_link.direction = UP;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        is_idle = 0;
        state->my_link.direction = RIGHT;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        is_idle = 0;
        state->my_link.direction = DOWN;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        is_idle = 0;
        state->my_link.direction = LEFT;
    }

    if (event.type == sfEvtKeyReleased && is_idle) {
        if (state->my_link.direction == LEFT) {
            animation_set_rects(&state->my_link.ani,
                link_left_idle_origs,
                link_left_idle_rects);
            state->my_link.ani.invert_y = 1;
        }
        if (state->my_link.direction == RIGHT) {
            animation_set_rects(&state->my_link.ani,
                link_right_idle_origs,
                link_right_idle_rects);
        }
        if (state->my_link.direction == UP) {
            animation_set_rects(&state->my_link.ani,
                link_up_idle_origs,
                link_up_idle_rects);
        }
        if (state->my_link.direction == DOWN) {
            animation_set_rects(&state->my_link.ani,
                link_down_idle_origs,
                link_down_idle_rects);
        }

    } else if (event.type == sfEvtKeyPressed) {
        if (state->my_link.direction == LEFT) {
            animation_set_rects(&state->my_link.ani,
                link_left_walk_origs,
                link_left_walk_rects);
            state->my_link.ani.invert_y = 1;
        }
        if (state->my_link.direction == RIGHT) {
            animation_set_rects(&state->my_link.ani,
                link_right_walk_origs,
                link_right_walk_rects);
        }
        if (state->my_link.direction == UP) {
            animation_set_rects(&state->my_link.ani,
                link_up_walk_origs,
                link_up_walk_rects);
        }
        if (state->my_link.direction == DOWN) {
            animation_set_rects(&state->my_link.ani,
                link_down_walk_origs,
                link_down_walk_rects);
        }
    }
}

int DECORATE(handle_events)(void *data, sfEvent event)
{
    DECORATE(state) *state = data;

    DECORATE(link_direction)(state, event);
    return (0);
}