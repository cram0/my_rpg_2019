#include "decorator.h"
#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"

static void DECORATE(press_any_key)(void *data, sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        DEBUG("Key pressed! => %d", event.key.code);
        setstring_textbox(&scene_state(data)->textbox, "intro:\nThis is a walkthrough\n / playthrough I did of the\n Super Nintendo\n game The Legend of\n Zelda: A Link to the\n past. I go through this in one sitting, and get all the heart containers and items/.");
    }
}

int DECORATE(handle_events)(void *data, sfEvent event)
{
    DECORATE(press_any_key)(data, event);
    return (0);
}