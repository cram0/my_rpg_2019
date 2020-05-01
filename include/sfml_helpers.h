#ifndef SFML_HELPERS_H
#define SFML_HELPERS_H

#include <SFML/System.h>

#define GET_ELAPSED_MSECS(clock) \
    sfTime_asMilliseconds(sfClock_getElapsedTime(clock))

#define vec_same(v) ((sfVector2f){ v, v })

#define vec_create(x, y) ((sfVector2f){ x, y })

#define vec_center(w, h) ((sfVector2f){ (w) / 2.0, (h) / 2.0 })

#define vec_sub(a, b) ((sfVector2f){(b).x - (a).x, (b).y - (a).y})

#define vec_add(a, b) ((sfVector2f){(b).x + (a).x, (b).y + (a).y})

#endif