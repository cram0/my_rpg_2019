#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    DECORATE(state) *state = data;

    if (draw_textbox(&scene_state(data)->textbox, win) < 0)
        return (-1);

    entity_draw(&state->my_intro.nintendo, win, NULL);
    entity_draw(&state->my_intro.backgrd, win, NULL);
    entity_draw(&state->my_intro.copyright, win, NULL);
    if (state->my_intro.tri_first == 0)
        animation_draw(&state->my_intro.triforce, win, NULL);
    entity_draw(&state->my_intro.zelda, win, NULL);
    entity_draw(&state->my_intro.subtitle, win, NULL);
    entity_draw(&state->my_intro.tlo, win, NULL);
    entity_draw(&state->my_intro.sword, win, NULL);
    entity_draw(&state->my_intro.zelda_z, win, NULL);
    if (state->my_intro.tri_first == 1)
        animation_draw(&state->my_intro.triforce, win, NULL);
    return (0);
}