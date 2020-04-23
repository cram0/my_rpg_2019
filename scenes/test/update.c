#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "../lib/animation.h"
#include "../lib/map.h"
#include "../lib/helpers.h"

sfVector2f map_point_from_screen_position(map *m, sfVector2f pt)
{
    return (vec_sub(m->pos, pt));
}

int animation_collide_with_map(animation *ani, map *m, float zoom, int direction)
{
    sfRectangleShape *hitbox_sprite = ani->hitbox;
    sfFloatRect hitbox = sfRectangleShape_getGlobalBounds(hitbox_sprite);

    float start_x = 0, start_y = 0, end_x = 0, end_y = 0;
    if (direction & 1) {
        start_y = hitbox.top;
        end_y = start_y + 2;
        start_x = hitbox.left;
        end_x = hitbox.left + hitbox.width;
    }
    else if (direction & 2) {
        start_y = hitbox.top + hitbox.height;
        end_y = start_y + 2;
        start_x = hitbox.left;
        end_x = hitbox.left + hitbox.width;
    }
    if (direction & 4) {
        start_x = hitbox.left;
        end_x = start_x + 2;
        start_y = hitbox.top;
        end_y = hitbox.top + hitbox.height;
    }
    else if (direction & 8) {
        start_x = hitbox.left + hitbox.width;
        end_x = start_x + 2;
        start_y = hitbox.top;
        end_y = hitbox.top + hitbox.height;
    }

    for (int i = start_x; i < end_x; i++) {
        for (int j = start_y; j < end_y; j++) {
            sfVector2f point_map = map_point_from_screen_position(m, vec_create(i, j));
            sfColor color = sfImage_getPixel(m->hitbox_dump, point_map.x / zoom, point_map.y / zoom);

            if (color.r == 255)
                return (1);
        }
    }

    return (0);
}

int DECORATE(update)(void *data)
{
    DECORATE(state) *state = data;

    house *hous = &state->my_map;
    link *lnk = &state->my_link;

    animation_update(&lnk->ani, 30);

    sfVector2f save;
    map_move(&hous->m, lnk->is_running, lnk->diagonals, &save);
    if (animation_collide_with_map(&lnk->ani, &hous->m, state->zoom_level, lnk->diagonals)) {
        hous->m.pos = save;
        map_update(&hous->m);
    }


    return (0);
}
