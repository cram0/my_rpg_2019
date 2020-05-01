#include "draw_mob.h"

#include "../../../mobs/mob.h"

void mob_draw(mob *mob, sfRenderWindow *win, sfRenderStates *states)
{
    sfRenderWindow_drawSprite(win, mob->ani.sprite, states);

#ifndef NDEBUG
    sfRenderWindow_drawRectangleShape(win, mob->ani.hitbox, NULL);
#endif
}