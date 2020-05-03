#include <SFML/Graphics.h>

#include "../../include/sfml_helpers.h"

#include "map.h"

void map_draw(map *map, sfRenderWindow *win, sfRenderStates *states)
{
    sfRenderWindow_drawSprite(win, map->sprite, states);
    sfRenderWindow_drawSprite(win, map->sprite_color, states);
}

void map_update(map *map)
{
    sfSprite_setPosition(map->sprite, map->pos);
    sfSprite_setPosition(map->sprite_color, map->pos);
}

int map_init(map *m, char *map_pth, char *color_pth, float zoom)
{
    m->pos = (sfVector2f){0.0, 0.0};

    m->sprite = sfSprite_create();
    m->texture = sfTexture_createFromFile(map_pth, NULL);

    m->sprite_color = sfSprite_create();
    m->texture_color = sfTexture_createFromFile(color_pth, NULL);

    if (!m->sprite || !m->texture || !m->sprite_color || !m->texture_color)
        return (-1);

    sfSprite_setTexture(m->sprite, m->texture, sfFalse);
    sfSprite_setTexture(m->sprite_color, m->texture_color, sfFalse);

    sfSprite_setPosition(m->sprite, m->pos);
    sfSprite_setPosition(m->sprite_color, m->pos);

    m->zoom = zoom;
    m->speed_factor = 0.350;

    sfSprite_setScale(m->sprite, vec_same(zoom));
    sfSprite_setScale(m->sprite_color, vec_same(zoom));

#ifndef NDEBUG
    sfSprite_setColor(m->sprite_color, (sfColor){255, 255, 255, 100});
#else
    sfSprite_setColor(m->sprite_color, (sfColor){255, 255, 255, 0});
#endif

    m->hitbox_dump = sfTexture_copyToImage(m->texture_color);
    if (!m->hitbox_dump)
        return (-1);

    return (0);
}

long map_get_elapsed_mil(map *map, int idx)
{
    sfClock **clock = &map->clocks[idx];
    if (!(*clock)) {
        *clock = sfClock_create();
        if (!(*clock))
            return (-1);
        return (0);
    }

    return (GET_ELAPSED_MSECS(*clock));
}

void map_set_position(map *m, sfVector2f pos)
{
    m->pos = pos;
    //sfSprite_setPosition(ani->sprite, pos);
}

sfVector2f map_get_position(map *m)
{
    return (m->pos);
}

void map_clock_restart(map *map, int idx)
{
    sfClock *clock = map->clocks[idx];
    if (clock) {
        sfClock_restart(clock);
    }
}

void map_move(map *m, int should_move, int directions)
{
    sfVector2f *map_pos = &m->pos;

    if (should_move) {
        float elapsed = map_get_elapsed_mil(m, 0);
        float factor = m->speed_factor;
        float offset = elapsed * factor;

        if      (directions & 1) map_pos->y += offset;
        else if (directions & 2) map_pos->y -= offset;
        if      (directions & 4) map_pos->x += offset;
        else if (directions & 8) map_pos->x -= offset;
    }

    map_clock_restart(m, 0);

    map_update(m);
}