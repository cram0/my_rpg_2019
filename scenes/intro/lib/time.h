#ifndef TIME_H
#define TIME_H

#include <SFML/Graphics.h>

#include "../state.h"

long global_get_elpased_mil(sfClock *clock);
float update_time(sfClock *clock);

#endif