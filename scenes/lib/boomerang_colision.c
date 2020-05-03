#include "boomerang_colision.h"

void boomerang_colision(boomerang *boomr, mob *mobs)
{
    sfFloatRect boomerang_hb = sfSprite_getGlobalBounds(boomr->sprite);
    sfFloatRect mob_hb;
    if (boomr->launch == -1)
        return;
    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        mob_hb = sfRectangleShape_getGlobalBounds(mobs[i].ani.hitbox);
        if (sfFloatRect_intersects(&boomerang_hb, &mob_hb, NULL)) {
            if (mobs[i].is_alive == 0) continue;
            if (mobs[i].clining == 1) continue;
            mobs[i].life -= 5;
            sfClock_restart(mobs[i].hit_clock);
            mobs[i].clining = 1;
            mobs[i].hit = 1;
            boomr->last_mob_id = mobs[i].id;
        }
    }
}