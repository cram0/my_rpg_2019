#ifndef UPDATE_MOB_H_
#define UPDATE_MOB_H_

#include "../../../mobs/mob.h"
#include "../../lib/map.h"

void mob_update_ani(mob *mobs, float time);
void mob_movement(map *m, mob *mobs);
void mob_set_rects(mob *mobs);
void mob_move_by_offset(mob *mobs, sfVector2f offset);

#endif /* !UPDATE_MOB_H_ */