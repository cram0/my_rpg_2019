#ifndef XXXXX_INTERFACE_H
#define XXXXX_INTERFACE_H

#include <SFML/Graphics.h>

#include "../../include/game_state.h"

#include "decorator.h"

void *DECORATE(init)(global_state *game_state);
int DECORATE(update)(void *data);
int DECORATE(handle_events)(void *data, sfEvent event);
int DECORATE(draw)(void *data, sfRenderWindow *win);
int DECORATE(destroy)(void *data);

#endif