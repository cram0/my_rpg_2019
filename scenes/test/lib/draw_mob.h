#ifndef DRAW_MOB_H_
#define DRAW_MOB_H_

#include <SFML/Graphics.h>
#include "../../../mobs/mob.h"

void mob_draw(mob *mob, sfRenderWindow *win, sfRenderStates *states);

#endif /* !DRAW_MOB_H_ */