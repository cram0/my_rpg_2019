#include <string.h>

#include "include/debug.h"

#include "lib/my_basic_getopt.h"
#include "lib/substring.h"

#include "components/initialization/initialization.h"
#include "components/game_loop/game_loop.h"
#include "components/usage/usage.h"

#include "scenes/sample_scene/interface.h"
#include "scenes/my_scene/interface.h"

int parse_arguments(global_state *state)
{
    char c;
    while ((c = my_basic_getopt(state->argc, state->argv)) != -1) {
        DEBUG("my_basic_getopt: c=%c", c);
        if (c == 'h')
            state->display_help = 1;
        else {
            state->display_help = 1;
            state->exit_code = 84;
        }
    }
}

int main(int argc, char *argv[])
{
    DEBUG("main: entered");
    DEBUG("argc: %d", argc);
    for (int i = 0; i < argc; i++)
        DEBUG("argv[%d]: %s", i, argv[i]);

    global_state state = {
        .width = 256 * 3,
        .height = 224 * 3,
        .scene_id = -1,
        .scenes_db = {
            SCENE_DB_ENTRY(sample_scene),
            SCENE_DB_ENTRY(my_scene)
        }
    };
    state.argc = argc;
    state.argv = &argv[0];

    parse_arguments(&state);
    if (!display_help(&state)) {
        init_window(&state) < 0 || start_game(&state) < 0;
    }

    DEBUG("main: exited");
    return (state.exit_code);
}