#include "update_mob.h"

#include <SFML/Graphics.h>

#include "../../../mobs/mob.h"

void mob_update(mob *mobs)
{
    animation_update(&mobs->ani, 30);
}