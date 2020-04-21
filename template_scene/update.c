#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"

int DECORATE(update)(void *data)
{
    if (update_textbox(&scene_state(data)->textbox) < 0)
        return (-1);
    return (0);
}
