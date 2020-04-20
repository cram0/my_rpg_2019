#include <string.h>

#include "../../include/debug.h"

#include "textbox.h"

void setstring_textbox(textbox_state *state, char *string)
{
    DEBUG("setstring_textbox called with string '%s'", string);
    reset_textbox(state);
    state->on = 1;
    strcpy(state->string, string);
}