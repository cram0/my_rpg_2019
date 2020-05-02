#include "decorator.h"
#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"

#include "lib/link_direction.h"

void test(equipment *stuff, sfEvent event)
{
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyA) {
            stuff->health -= 1;
    }
    if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyZ) {
            stuff->health += 1;
    }
}

int DECORATE(handle_events)(void *data, sfEvent event)
{
    DECORATE(state) *state = data;

    test(&state->my_link.link_stuff, event);
    inventory_interaction(&state->my_link.link_item, event);
    if (state->my_link.link_item.lock == 0) {
        boomerang_launch(&state->my_link.boomr,
                        state->my_link.direction, event);
        DECORATE(link_direction)(&state->my_link, event);
    }

    return (0);
}