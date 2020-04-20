#include <string.h>

#include <SFML/Graphics.h>

#include "../../include/debug.h"
#include "../../include/game_state.h"

void press_any_key(global_state *state)
{
    if (state->event.type == sfEvtKeyPressed) {
        DEBUG("Key pressed! => %d", state->event.key.code);
        setstring_textbox(&state->textbox, "Hello, World!\nMy name is Zelda\nWelcome here!\nYolo\nHiiiyaa!\nLorem Ipsum\nDolor sit amet\nNous sommes en guerre\nJet fuel can't melt steel\nbeams.");
    }
}