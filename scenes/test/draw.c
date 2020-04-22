#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"

void map_draw(map *map, sfRenderWindow *win, sfRenderStates *states)
{
    sfRenderWindow_drawSprite(win, map->sprite, states);
    sfRenderWindow_drawSprite(win, map->sprite_color, states);
}

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    DECORATE(state) *state = data;

    map_draw(&state->my_map, win, NULL);
    animation_draw(&state->my_link.ani, win, NULL);

    return (0);
}