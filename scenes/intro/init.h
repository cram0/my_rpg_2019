#ifndef INIT_H
#define INIT_H

#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"
#include "../lib/sprite_paths.h"

int DECORATE(assets_init)(DECORATE(state) *state);
int DECORATE(nintendo_init)(DECORATE(state) *state);
int DECORATE(copyright_init)(DECORATE(state) *state);
int DECORATE(zelda_init)(DECORATE(state) *state);
int DECORATE(subtitle_init)(DECORATE(state) *state);
int DECORATE(tlo_init)(DECORATE(state) *state);
int DECORATE(triforce_init)(DECORATE(state) *state);
int DECORATE(stars_init)(DECORATE(state) *state);
int DECORATE(background_init)(DECORATE(state) * state);
int DECORATE(sword_init)(DECORATE(state) *state);
int DECORATE(zelda_z_init)(DECORATE(state) *state);

#endif