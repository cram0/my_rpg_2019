#include <SFML/Graphics.h>

#include "animation.h"
#include "map.h"

#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"

static sfVector2f map_point_from_screen_position(map *m, sfVector2f pt)
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
        start_y = hitbox.top;
        end_y = hitbox.top + hitbox.height;
        start_x = hitbox.left;
        end_x = start_x + 2;
    }
    else if (direction & 8) {
        start_y = hitbox.top;
        end_y = hitbox.top + hitbox.height;
        start_x = hitbox.left + hitbox.width;
        end_x = start_x + 2;
    }

    sfVector2u bg_dimensions = sfImage_getSize(m->hitbox_dump);

    for (int i = start_x; i < end_x; i++) {
        for (int j = start_y; j < end_y; j++) {
            sfVector2f point_map = map_point_from_screen_position(m, vec_create(i, j));
            point_map.x /= zoom;
            point_map.y /= zoom;
            if (point_map.x < 0 || point_map.y < 0 ||
                point_map.x >= bg_dimensions.x || point_map.y >= bg_dimensions.y)
                return (1);
            sfColor color = sfImage_getPixel(m->hitbox_dump, point_map.x, point_map.y);

            if (color.r == 255)
                return (1);
        }
    }

    return (0);
}