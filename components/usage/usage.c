#include <stdio.h>

#include "../../include/game_state.h"

int display_help(global_state *state)
{
    if (state->display_help) {
        printf("USAGE\n");
        return (1);
    } else {
        return (0);
    }
}