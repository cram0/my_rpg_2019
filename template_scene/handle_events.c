#include "decorator.h"
#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"

static void DECORATE(press_any_key)(void *data, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        DEBUG("Key pressed! => %d", event.key.code);
        setstring_textbox(&scene_state(data)->textbox, "xxxxx:\nHello, World!");
    }
}

int DECORATE(handle_events)(void *data, sfEvent event)
{
    DECORATE(press_any_key)(data, event);
    return (0);
}