#include "update_mob.h"

#include <SFML/Graphics.h>

#include "../../../mobs/mob.h"

void mob_update(mob *mobs, float time)
{
    animation_update(&mobs->ani, time);
}