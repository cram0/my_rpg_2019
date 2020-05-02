#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "../lib/animation.h"
#include "../lib/helpers.h"
#include "lib/entity.h"
#include "lib/time.h"
#include "update.h"

void DECORATE(sword_anim)(DECORATE(state) *state)
{
    if (state->time < 15900) {
        if (state->my_intro.sword.position.y <= 90) {
            state->my_intro.sword.position.y += 10;
            entity_set_position(&state->my_intro.sword, 
            (sfVector2f){state->my_intro.sword.position.x,
            state->my_intro.sword.position.y});
        }
    }
}

void DECORATE(stars_change)(DECORATE(state) *state)
{
    if (state->my_intro.stars_change > 0) {
        if (state->my_intro.stars.position.x == 460 && 
        state->my_intro.stars.position.y == 230) {
            state->my_intro.stars.position.x = 340;
            state->my_intro.stars.position.y = 370;
        } else if (state->my_intro.stars.position.x == 340 && 
                state->my_intro.stars.position.y == 370) {
            state->my_intro.stars.position.x = 130;
            state->my_intro.stars.position.y = 250;
        } else if (state->my_intro.stars.position.x == 130 && 
                state->my_intro.stars.position.y == 250) {
            state->my_intro.stars.position.x = 620;
            state->my_intro.stars.position.y = 370;
        } else {
            state->my_intro.stars.position.x = 460;
            state->my_intro.stars.position.y = 230;
        }
        animation_set_position(&state->my_intro.stars, (sfVector2f){
        state->my_intro.stars.position.x, state->my_intro.stars.position.y});
        state->my_intro.stars_change = 0;
    }
}