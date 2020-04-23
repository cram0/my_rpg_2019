#ifndef SFML_HELPERS_H
#define SFML_HELPERS_H

#include <SFML/System.h>

#define GET_ELAPSED_MSECS(clock) \
    sfTime_asMilliseconds(sfClock_getElapsedTime(clock))

#endif