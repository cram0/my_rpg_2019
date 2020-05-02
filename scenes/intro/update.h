#ifndef MY_UPDATE_H
#define MY_UPDATE_H

#include <SFML/Graphics.h>

#include "decorator.h"

#include "state.h"

#include "../lib/animation.h"
#include "../lib/helpers.h"
#include "../../include/game_state.h"
#include "../../include/debug.h"
#include "../../include/sfml_helpers.h"
#include "../../include/maths_helpers.h"

#include "lib/entity.h"
#include "lib/time.h"

void DECORATE(draw_update)(DECORATE(state) *state);
void DECORATE(stars_change)(DECORATE(state) *state);
void DECORATE(first_update)(DECORATE(state) *state);
void DECORATE(second_update)(DECORATE(state) *state);
void DECORATE(third_update)(DECORATE(state) *state);
void DECORATE(fourth_update)(DECORATE(state) *state);
void DECORATE(fifth_update)(DECORATE(state) *state);
void DECORATE(six_update)(DECORATE(state) *state);
void DECORATE(seven_update)(DECORATE(state) *state);
void DECORATE(sword_anim)(DECORATE(state) *state);
void DECORATE(disable_draws)(DECORATE(state) *state);
void DECORATE(monolog_start)(DECORATE(state) *state);

#endif