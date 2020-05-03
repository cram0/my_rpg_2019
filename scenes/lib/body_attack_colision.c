#include "body_attack.h"

void attack_colision(animation *ani, mob *mobs, body_att *attck)
{
    sfFloatRect link = sfSprite_getGlobalBounds(ani->sprite);
    sfFloatRect mob_hb;
    if (attck->attack == 0)
        return;
    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        mob_hb = sfRectangleShape_getGlobalBounds(mobs[i].ani.hitbox);
        if (sfFloatRect_intersects(&link, &mob_hb, NULL)) {
            if (mobs[i].is_alive == 0) continue;
            if (mobs[i].clining == 1) continue;
            mobs[i].life -= attck->power;
            DEBUG("HIT: %d-> %d", mobs[i].id, mobs[i].life);
            sfClock_restart(mobs[i].hit_clock);
            mobs[i].clining = 1;
            mobs[i].hit = 1;
            attck->last_mob_id = mobs[i].id;
        }
    }
    DEBUG("FINISH");
}