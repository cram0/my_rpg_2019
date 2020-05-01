#include "update_mob.h"

#include <SFML/Graphics.h>

#include <stdlib.h>
#include <time.h>

#include "../../../mobs/mob.h"

#include "../../lib/map.h"

#include "../../../include/debug.h"

#include "../../../generated_code/rects.h"
#include "../../../generated_code/origins.h"

static const int mob_avail_direction[4] = {1, 2, 4, 8};

void mob_movement(map *m, mob *mobs)
{
    if (!mobs->mov_clk)
        mobs->mov_clk = sfClock_create();

    if (!mobs->mov_clk_cd)
        mobs->mov_clk_cd = sfClock_create();

    if (!mobs->is_walking) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(mobs->mov_clk_cd)) > 1.0) {
            int rand_dir = rand() % 4;
            mobs->direction = mob_avail_direction[rand_dir];
            mobs->is_walking = 1;
            sfClock_restart(mobs->mov_clk);
        }
    }

    if (mobs->is_walking) {
        if (sfTime_asSeconds(sfClock_getElapsedTime(mobs->mov_clk)) > 1.0) {
            mobs->is_walking = 0;
            sfClock_restart(mobs->mov_clk_cd);
        }
        if (mobs->direction & 2) {
            mobs->ani.position.y += 1;
        } else if (mobs->direction & 1) {
            mobs->ani.position.y -= 1;
        }
        if (mobs->direction & 8) {
            mobs->ani.position.x += 1;
        } else if (mobs->direction & 4) {
            mobs->ani.position.x -= 1;
        }
    }
}

void mob_set_rects(mob *mobs)
{
    if (mobs->direction & 2) {
        if (mobs->is_walking)
            m_animation_set_rects(&mobs->ani, monster_gk_down_walk);
        else
            m_animation_set_rects(&mobs->ani, monster_gk_down_idle);
    } else if (mobs->direction & 1) {
        if (mobs->is_walking)
            m_animation_set_rects(&mobs->ani, monster_gk_up_walk);
        else
            m_animation_set_rects(&mobs->ani, monster_gk_up_idle);
    }
    if (mobs->direction & 8) {
        if (mobs->is_walking)
            m_animation_set_rects(&mobs->ani, monster_gk_right_walk);
        else
            m_animation_set_rects(&mobs->ani, monster_gk_right_idle);
    } else if (mobs->direction & 4) {
        if (mobs->is_walking) {
            m_animation_set_rects(&mobs->ani, monster_gk_left_walk);
        }
        else {
            m_animation_set_rects(&mobs->ani, monster_gk_left_idle);
        }
    }
}

void mob_move_by_offset(mob *mobs, sfVector2f offset)
{
    mobs->ani.position.x += offset.x;
    mobs->ani.position.y += offset.y;
}

void mob_update_ani(mob *mobs, float time)
{
    animation_update(&mobs->ani, time);
}