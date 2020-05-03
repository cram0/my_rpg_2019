#include "decorator.h"

#include "state.h"

#include "../../include/game_state.h"
#include "../../include/debug.h"

int DECORATE(destroy)(void *data)
{
    DECORATE(state) *state = data;
    sfMusic_destroy(state->music);
    sfMusic_destroy(state->opening);
    DEBUG("Destroying scene %s", "intro");
    DEBUG("Destroy operation not implemented!");
}