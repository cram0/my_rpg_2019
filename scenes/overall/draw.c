#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    DECORATE(state) *state = data;

    map_draw(&state->my_map.m, win, NULL);
    animation_draw(&state->my_link.ani, win, NULL);
    display_hud(&state->my_link.link_stuff, win);
    display_inventory(win, &state->my_link.link_item);
    return (0);
}