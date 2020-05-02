#ifndef MY_UPDATE_H
#define MY_UPDATE_H

#include <SFML/Graphics.h>

#include "../state.h"

#include "../../lib/animation.h"
#include "../../lib/helpers.h"
#include "entity.h"
#include "time.h"

void DECORATE(sword_anim)(DECORATE(state) *state);
void DECORATE(stars_change)(DECORATE(state) *state);
void DECORATE(first_update)(DECORATE(state) *state);
void DECORATE(second_update)(DECORATE(state) *state);
void DECORATE(third_update)(DECORATE(state) *state);
void DECORATE(fourth_update)(DECORATE(state) *state);
void DECORATE(fifth_update)(DECORATE(state) *state);
void DECORATE(draw_update)(DECORATE(state) *state);

#endif