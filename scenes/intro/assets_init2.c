#include "decorator.h"

#include "state.h"
#include "init.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"
#include "../lib/sprite_paths.h"

int DECORATE(nintendo_init)(DECORATE(state) *state)
{
    entity *nintendo = &state->my_intro.nintendo;
    nintendo->is_drawable = 1;

    if (entity_load_spritesheet(nintendo, NINTENDO_PATH) < 0)
        return (-1);
    
    entity_set_zoom(nintendo, (float){3.0});
    entity_set_position(nintendo, (sfVector2f){300.0, 300.0});

    return (0);
}

int DECORATE(copyright_init)(DECORATE(state) *state)
{
    entity *copyright = &state->my_intro.copyright;
    copyright->is_drawable = 0;

    if (entity_load_spritesheet(copyright, COPYRIGHT_PATH) < 0)
        return (-1);

    entity_set_zoom(copyright, (float){3.5});
    entity_set_position(copyright, (sfVector2f){270.0, 550.0});

    return (0);
}

int DECORATE(zelda_init)(DECORATE(state) *state)
{
    entity *zelda = &state->my_intro.zelda;
    zelda->is_drawable = 0;

    if (entity_load_spritesheet(zelda, ZELDA_PATH) < 0)
        return (-1);

    entity_set_zoom(zelda, 3.5);
    entity_set_position(zelda, (sfVector2f){140, 220.0});

    return (0);
}

int DECORATE(subtitle_init)(DECORATE(state) *state)
{
    entity *subtitle = &state->my_intro.subtitle;
    subtitle->is_drawable = 0;

    if (entity_load_spritesheet(subtitle, SUBTITLE_PATH) < 0)
        return (-1);

    entity_set_zoom(subtitle, 3.0);
    entity_set_position(subtitle, (sfVector2f){300.0, 410.0});

    return (0);
}

int DECORATE(tlo_init)(DECORATE(state) *state)
{
    entity *tlo = &state->my_intro.tlo;
    tlo->is_drawable = 0;

    if (entity_load_spritesheet(tlo, TLO_PATH) < 0)
        return (-1);

    entity_set_zoom(tlo, 3.0);
    entity_set_position(tlo, (sfVector2f){290.0, 190.0});

    return (0);
}