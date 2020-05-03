#include "mobs_verif.h"

void mobs_is_alive(mob *mobs, items *item)
{
    int ms = 0;
    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        ms = GET_ELAPSED_MSECS(mobs[i].hit_clock);
        if (ms > 50 && mobs[i].clining == 1) {
            mobs[i].hit *= -1;
            mobs[i].loop += 1;
            sfClock_restart(mobs[i].hit_clock);
        }
        if (mobs[i].loop > 4) {
            mobs->hit = -1;
            mobs[i].clining = 0;
        }
        if (mobs[i].life <= 0 && mobs[i].is_alive != 0) {
            mobs[i].is_alive = 0;
            item->xp += mobs[i].xp;
        }
    }
}