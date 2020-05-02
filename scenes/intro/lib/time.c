#include "../decorator.h"

#include "../state.h"

#include "../../../include/game_state.h"
#include "../../../include/debug.h"
#include "../../../include/sfml_helpers.h"
#include "../../../include/maths_helpers.h"

#include "../../lib/animation.h"
#include "../../lib/helpers.h"
#include "entity.h"
#include "time.h"

long global_get_elapsed_mil(sfClock *clock)
{
    sfClock *clo = clock;
    if (!(clo)) {
        clo = sfClock_create();
        if (!(clo))
            return (-1);
        return (0);
    }

    return GET_ELAPSED_MSECS(clo);
}

float update_time(sfClock *clock)
{
    float elapsed = global_get_elapsed_mil(clock);

    return (elapsed);
}