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

const char MONOLOG[] = "Long ago, in the beautiful\n kingdom of Hyrule surrounded\n by mountains and forests...\n legends told of an omnipotent\n and omniscient Golden Power\n that resided in a hidden land.";
const char MONOLOG2[] = "Many people aggressively\n sought to enter the hidden\n Golden Land...\n But no one ever returned.\n One day evil power began to\n flow from the Golden Land...";
const char MONOLOG3[] = "So the king commanded seven\n wise men to seal the gate to\n the Land of the Golden Power.";
const char MONOLOG4[] = "That seal should have remained\n for all time...";
const char MONOLOG5[] = "... ...But, when these events\n were obscured by the mists of\n time and became legend..."; 

void DECORATE(monolog_start)(DECORATE(state) *state)
{
    if (state->my_intro.monolog == 1) {
        setstring_textbox(&state->textbox, MONOLOG);
        state->my_intro.monolog = 4;
    }
    if (state->my_intro.monolog2 == 1) {
        setstring_textbox(&state->textbox, MONOLOG2);
        state->my_intro.monolog2 = 4;
    }
    if (state->my_intro.monolog3 == 1) {
        setstring_textbox(&state->textbox, MONOLOG3);
        state->my_intro.monolog3 = 4;
    }
    if (state->my_intro.monolog4 == 1) {
        setstring_textbox(&state->textbox, MONOLOG4);
        state->my_intro.monolog4 = 4;
    }
    if (state->my_intro.monolog5 == 1) {
        setstring_textbox(&state->textbox, MONOLOG5);
        state->my_intro.monolog5 = 4;
    }
}

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