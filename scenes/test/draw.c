#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"
#include "lib/draw_mob.h"
#include "lib/draw_objects.h"

#include "../../mobs/mob.h"
#include "../../objects/objects.h"

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    DECORATE(state) *state = data;
    mob *mobs = state->my_map.m.mobs;
    object *objects = state->my_map.m.objects;

    map_draw(&state->my_map.m, win, NULL);

    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        mob_draw(&mobs[i], win, NULL);
    }

    for (int i = 0; objects[i].type != NUL_OBJECT; i++) {
        if (objects[i].interacted == 0) {
            objects_draw(&objects[i], win, NULL);
        }
    }

    boomerang_draw(win, &state->my_link.boomr, state->my_map.m.pos);
    animation_draw(&state->my_link.ani, win, NULL);

    display_hud(&state->my_link.link_stuff, win);
    display_inventory(win, &state->my_link.link_item);

    return (0);
}