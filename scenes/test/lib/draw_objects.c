#include "draw_objects.h"

#include "../../../objects/objects.h"

void objects_draw(object *objects, sfRenderWindow *win, sfRenderStates *states)
{
    sfRenderWindow_drawSprite(win, objects->ani.sprite, states);

#ifndef NDEBUG
    sfRenderWindow_drawRectangleShape(win, objects->ani.hitbox, NULL);
#endif
}