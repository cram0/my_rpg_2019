#include "init_mob.h"

#include <SFML/Graphics.h>

#include "../state.h"
#include "../decorator.h"

#include "../../../generated_code/origins.h"
#include "../../../generated_code/rects.h"

#include "../../../mobs/mob.h"

#include "../../../include/sfml_helpers.h"
#include "../../../include/debug.h"

#include "../../../scenes/lib/animation.h"

const char MONSTER_PATH[] = "assets/monster.png";

sfVector2f mob_rel_position(sfVector2f map_pos, sfVector2f abs_pos, float zoom)
{
    return (vec_create(zoom * abs_pos.x - map_pos.x, zoom * abs_pos.y - map_pos.y));
}

void init_value_mobs(mob *mobs)
{
    mobs->is_alive = 1;
    mobs->hit_clock = sfClock_create();
    mobs->hit = -1;
    mobs->clining = 0;
    mobs->loop = 0;
    if (mobs->type == 0) {
        mobs->life = 10;
        mobs->xp = 25;
    }
    if (mobs->type == 1) {
        mobs->life = 15;
        mobs->xp = 50;
    }
}

int DECORATE(mobs_init)(DECORATE(state) *state)
{
    state->my_map.m.mobs = overworld_mobs;
    mob *mobs = state->my_map.m.mobs;

    for (int i = 0; mobs[i].type != NUL_MOB; i++) {
        init_value_mobs(&mobs[i]);
        sfVector2f rel = mob_rel_position(state->my_map.m.pos, mobs[i].abs_pos, state->zoom_level);
        m_animation_init(&mobs[i].ani, state->zoom_level, MONSTER_PATH, rel, monster_bk_down_idle, vec_create(10, 10), vec_create(10, -10));
        switch (mobs[i].type) {
            case GREEN_KNIGHT : m_animation_set_rects(&mobs[i].ani, monster_gk_down_idle);
                break;
            case BLUE_KNIGHT : m_animation_set_rects(&mobs[i].ani, monster_bk_down_idle);
                break;
            case YELLOW_KNIGHT : m_animation_set_rects(&mobs[i].ani, monster_yk_down_idle);
                break;
            case MOUSE : m_animation_set_rects(&mobs[i].ani, monster_mouse_down_idle);
                break;
            case SERPENT : m_animation_set_rects(&mobs[i].ani, monster_serpent_down_idle);
                break;
            case TROOPER : m_animation_set_rects(&mobs[i].ani, monster_trooper_down_idle);
                break;
            default : m_animation_set_rects(&mobs[i].ani, monster_crab_idle);
                break;
        }
    }

    return (0);
}