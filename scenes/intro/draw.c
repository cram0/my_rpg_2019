#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    DECORATE(state) *state = data;

    if (draw_textbox(&scene_state(data)->textbox, win) < 0)
        return (-1);

    entity_draw(&state->my_intro.nintendo, win, NULL);
    entity_draw(&state->my_intro.copyright, win, NULL);
    animation_draw(&state->my_intro.triforce, win, NULL);
    entity_draw(&state->my_intro.zelda, win, NULL);
    entity_draw(&state->my_intro.subtitle, win, NULL);
    entity_draw(&state->my_intro.tlo, win, NULL);
    return (0);
}