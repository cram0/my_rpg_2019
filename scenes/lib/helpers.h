#ifndef HHELPERS_H
#define HHELPERS_H

#include <SFML/Graphics.h>

/*
** You probably don't need those functions.
*/

sfVector2f get_relative_origin(sfIntRect rect, sfVector2f pos);
int rect_iszero(sfIntRect rect);
sfIntRect invert_y_rect(sfIntRect rect);
sfVector2f invert_y_origin(sfVector2f origin, sfIntRect rect);

#endif