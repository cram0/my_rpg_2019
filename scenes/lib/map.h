#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.h>

typedef struct {
    float zoom;
    float speed_factor;

    sfSprite *sprite;
    sfTexture *texture;

    sfSprite *sprite_color;
    sfTexture *texture_color;

    sfImage *hitbox_dump;

    sfVector2f pos;

    sfClock *clocks[5];
} map;

void map_draw(map *map, sfRenderWindow *win, sfRenderStates *states);
int map_init(map *m, char *map_pth, char *color_pth, float zoom);
void map_update(map *map);
void map_clock_restart(map *map, int idx);
long map_get_elapsed_mil(map *map, int idx);
void map_move(map *m, int should_move, int directions, sfVector2f *movement);

#endif