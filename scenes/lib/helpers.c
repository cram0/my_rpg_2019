#include <SFML/Graphics.h>

#include "helpers.h"

sfVector2f get_relative_origin(sfIntRect rect, sfVector2f pos)
{
    return (
        (sfVector2f){ pos.x - rect.left, pos.y - rect.top }
    );
}

int rect_iszero(sfIntRect rect)
{
    return (
        !rect.left && !rect.top && !rect.width && !rect.height
    );
}

sfIntRect invert_y_rect(sfIntRect rect)
{
    return (
        (sfIntRect){
            .left = rect.left + rect.width,
            .top = rect.top,
            .width = -rect.width,
            .height = rect.height
        }
    );
}

sfVector2f invert_y_origin(sfVector2f origin, sfIntRect rect)
{
    return (
        (sfVector2f){
            .x = rect.width - origin.x,
            .y = origin.y
        }
    );
}