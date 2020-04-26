#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"
#include "lib/draw_mob.h"

#include "../../mobs/mob.h"

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    DECORATE(state) *state = data;
    mob *mobs = state->my_map.m.mobs;

    map_draw(&state->my_map.m, win, NULL);
    animation_draw(&state->my_link.ani, win, NULL);

    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        mob_draw(&state->my_map.m.mobs[i], win, NULL);
    }

    return (0);
}