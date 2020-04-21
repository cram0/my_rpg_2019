#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    if (draw_textbox(&scene_state(data)->textbox, win) < 0)
        return (-1);
    return (0);
}