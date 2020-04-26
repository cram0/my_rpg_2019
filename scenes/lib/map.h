#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.h>

#include "../../mobs/mob.h"

/*
** You may only *touch* the following members:
**     - speed_factor (default value is 0.360) you can increase it to make the
** map move faster when using map_move.
**     - pos is accessed using map_get_position and map_set_position
**     - clocks are accessed through map_clock_restart and map_get_elapsed_mil
*/
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

    mob *mobs;

} map;

/*
** map_draw is to be called on each frame, in your scene's `draw` function.
*/
void map_draw(map *map, sfRenderWindow *win, sfRenderStates *states);

/*
** To be run only once, map_pth is the map's spritesheet, color_pth is the map's
** hitbox spritesheet and zoom is the global zoom level in
** game_state->zoom_level.
*/
int map_init(map *m, char *map_pth, char *color_pth, float zoom);

/*
** The function map_update must be run on each frame, in your scene's `update`
** function.
*/
void map_update(map *map);

/*
** Each map holds 5 clocks located in map->clocks. You don't need to initialize
** them. It's all done when map_get_elapsed_mil is called for the first time.
**
** map_get_elapsed_mil returns a time in milliseconds
**
** example of code:
**
**     int id = 0; // id = 0 to 4 (5 clocks)
**     long elapsed_time = map_get_elapsed_time(map, id);
**     if (elapsed_time > 60) {
**         // code ...
**
**         map_clock_restart(map, id);
**     }
**
*/
void map_clock_restart(map *map, int idx);
long map_get_elapsed_mil(map *map, int idx);

/*
** This function is a helper to implement an organic, clocked movement,
** perfect for keyboard controls.
**
** Let's say that you have a character in the middle of the screen, and you
** want the map to move according to the keyboard arrows.
**
** m is the map you want to move,
**
** should_move is set to 1 when the map should, indeed, move
**
** directions is an integer describing what keys are currently pressed,
** only the first 4 bits matter:
**      - 1st bit: up    (ie. 0b0001 or 1)
**      - 2nd bit: down  (ie. 0b0010 or 2)
**      - 3rd bit: left  (ie. 0b0100 or 4)
**      - 4th bit: right (ie. 0b1000 or 8)
** and combinations:
**      - up + left    = 0b0001 + 0b0100 = 0b0101 = 5
**      - up + right   = 0b0001 + 0b1000 = 0b1001 = 9
**      - down + left  = 0b0010 + 0b0100 = 0b0110 = 6
**      - down + right = 0b0010 + 0b1000 = 0b1010 = 10
*/
void map_move(map *m, int should_move, int directions, sfVector2f *movement);

/*
** This function sets the position of the top-left corner of a map.
** On the next call to map_update, the map will have moved there.
*/
void map_set_position(map *m, sfVector2f pos);

/*
** This function returns the position of the top-left corner of a map
*/
sfVector2f map_get_position(map *m);

#endif