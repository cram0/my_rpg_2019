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

const char MONOLOG[] = "Long ago, in the beautiful\nkingdom of Hyrule surrounded\nby mountains and forests...\nlegends told of an omnipotent\nand omniscient Golden Power\nthat resided in a hidden land.";
const char MONOLOG2[] = "Many people aggressively\nsought to enter the hidden\nGolden Land...\nBut no one ever returned.\nOne day evil power began to\nflow from the Golden Land...";
const char MONOLOG3[] = "So the king commanded seven\nwise men to seal the gate to\nthe Land of the Golden Power.";
const char MONOLOG4[] = "That seal should have remained\nfor all time...";
const char MONOLOG5[] = "... ...But, when these events\nwere obscured by the mists of\ntime and became legend...";
const char MONOLOG6[] = "A mysterious wizard known as\nAgahnim came to Hyrule to\nrelease the seal. He eliminated\nthe good King of Hyrule...";
const char MONOLOG7[] = "Through evil magic, he began\nto make wise men vanish, one\nafter another.\nAnd the time of destiny for\nPrincess Zelda is drawing\nnear.";

void DECORATE(eight_update)(DECORATE(state) *state)
{
    if (state->time > 84000) {
        if (state->my_intro.monolog7 != 4)
            state->my_intro.monolog7 = 1;
    }
}

void DECORATE(monolog_next)(DECORATE(state) *state)
{
    if (state->my_intro.monolog6 == 1) {
        setstring_textbox(&state->textbox, MONOLOG6);
        state->my_intro.monolog6 = 4;
    }
    if (state->my_intro.monolog7 == 1) {
        setstring_textbox(&state->textbox, MONOLOG7);
        state->my_intro.monolog7 = 4;
    }
}

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
    DECORATE(monolog_next(state));
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