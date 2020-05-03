#include "../../components/textboxes/textbox.h"

#include "decorator.h"
#include "state.h"
#include "lib/draw_mob.h"
#include "lib/draw_objects.h"
#include "../../components/textboxes/textbox.h"

#include "../../mobs/mob.h"
#include "../../objects/objects.h"

int DECORATE(draw)(void *data, sfRenderWindow *win)
{
    DECORATE(state) *state = data;
    mob *mobs = state->my_map.m.mobs;
    object *objects = state->my_map.m.objects;

    if (state->my_link.link_stuff.health <= 0) {
        display_game_over(win, &state->my_link.gmv, &state->text_gmv);
        return;
    }
    map_draw(&state->my_map.m, win, NULL);

    DEBUG("%f %f", state->my_map.m.pos.x, state->my_map.m.pos.y);

    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        if (mobs[i].is_alive == 0 || mobs[i].hit == 1) continue;
        mob_draw(&mobs[i], win, NULL);
    }

    for (int i = 0; objects[i].type != NUL_OBJECT; i++) {
        if (objects[i].not_draw == 0) {
            objects_draw(&objects[i], win, NULL);
        }
    }

    draw_textbox(&state->my_map.m.tuto_textbox, win);
    
    boomerang_draw(win, &state->my_link.boomr, state->my_map.m.pos);
    animation_draw(&state->my_link.ani, win, NULL);
    if (state->my_link.is_carrying == 1) {
        sfRenderWindow_drawSprite(win, state->my_link.object_carried, NULL);
    }

    display_hud(&state->my_link.link_stuff, win);
    display_inventory(win, &state->my_link.link_item);

    return (0);
}