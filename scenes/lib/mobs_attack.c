#include "mobs_attack.h"

sfVector2f calcul_vec(sfVector2f pt1, sfVector2f pt2, float mag)
{
    sfVector2f vec;
    vec.x = (pt2.x - pt1.x) / mag * 2;
    vec.y = (pt2.y - pt1.y) / mag * 2;

    return (vec);
}

void new_direction(mob *mobs, sfVector2f vec)
{
    if (vec.x > 0 && (vec.y < 0.5 && vec.y > -0.5)) {
        mobs->direction = 8;
        return;
    }
    if (vec.x < 0 && (vec.y < 0.5 && vec.y > -0.5)) {
        mobs->direction = 4;
        return;
    }
    if (vec.y > 0) {
        mobs->direction = 2 ;
    }
    if (vec.y < 0) {
        mobs->direction = 1;
    }
}

void move_to_target(mob *mobs, animation *lnk, equipment *stuff)
{
    int ms = GET_ELAPSED_MSECS(mobs->attack_clock);
    sfVector2f pt1 = sfSprite_getPosition(mobs->ani.sprite);
    sfVector2f pt2 = sfSprite_getPosition(lnk->sprite);
    sfVector2f new_vec;
    float distance = sqrt(pow(pt2.x - pt1.x, 2) + pow(pt2.y - pt1.y, 2));
    mobs->is_walking = 1;
    new_vec = calcul_vec(pt1, pt2, distance);
    new_direction(mobs, new_vec);
    if (distance <= 20 && ms > 1500) {
        stuff->health -= mobs->att_power;
        if (stuff->health < 0)
            stuff->health = 0;
        sfClock_restart(mobs->attack_clock);
    }
    mobs->ani.position.x += new_vec.x;
    mobs->ani.position.y += new_vec.y;
}

void find_target(mob *mobs, animation *lnk)
{
    sfVector2f pt1 = sfSprite_getPosition(mobs->ani.sprite);
    sfVector2f pt2 = sfSprite_getPosition(lnk->sprite);
    int distance = 0;

    distance = sqrt(pow(pt2.x - pt1.x, 2) + pow(pt2.y - pt1.y, 2));

    if (distance < 200) {
        mobs->is_aggro = 1;
    }
}