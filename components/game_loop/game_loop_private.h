#ifndef GAME_LOOP_PRIVATE_H
#define GAME_LOOP_PRIVATE_H

#include "../../include/game_state.h"

void close_window(global_state *state);
void press_any_key(global_state *state);

int manage_events(global_state *state);

int update_state(global_state *state);

int draw_sprites(global_state *state);

#endif