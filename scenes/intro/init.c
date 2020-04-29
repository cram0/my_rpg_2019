#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"

const char NINTENDO_PATH[] = "assets/title_screen/nintendo_presents.png";
const char COPYRIGHT_PATH[] = "assets/title_screen/copyright.png";
const char TRIFORCE_PATH[] = "assets/title_screen/triforce.png";
const char SWORD_PATH[] = "assets/title_screen/logo_sword.png";
const char STARS_PATH[] = "assets/title_screen/small_shine.png";
const char SUBTITLE_PATH[] = "assets/title_screen/logo_subtitle.png";
const char BCKGRD_PATH[] = "assets/title_screen/background.png";
const char TLO_PATH[] = "assets/title_screen/logo_tlo.png";
const char ZELDA_PATH[] =  "assets/title_screen/logo_zelda.png";

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

int DECORATE(triforce_init)(DECORATE(state) *state, float width, float height)
{
    animation *tri = &state->my_intro.triforce;
    tri->is_drawable = 0;
    tri->invert_y = 0;

    if (animation_load_spritesheet(tri, TRIFORCE_PATH) < 0)
        return (-1);

    animation_set_zoom(tri, 3.2);
    animation_set_position(tri, (sfVector2f){130.0, 45.0});
    m_animation_set_rects(tri, triforce);

    return (0);
}

int DECORATE(background_init)(DECORATE(state) * state)
{
    entity *backgrd = &state->my_intro.backgrd;
    backgrd->is_drawable = 0;

    if (entity_load_spritesheet(backgrd, BCKGRD_PATH) < 0)
        return (-1);

    entity_set_zoom(backgrd, 3.0);
    entity_set_position(backgrd, (sfVector2f){0.0, 40.0});

    return (0);
}

int DECORATE(assets_init)(DECORATE(state) *state, float width, float height)
{

    if (DECORATE(nintendo_init)(state) < 0)
        return (-1);
    if (DECORATE(copyright_init)(state) < 0)
        return (-1);
    if (DECORATE(triforce_init)(state, width, height) < 0)
        return (-1);
    if (DECORATE(zelda_init)(state) < 0)
        return (-1);
    if (DECORATE(subtitle_init)(state) < 0)
        return (-1);
    if (DECORATE(tlo_init)(state) < 0)
        return (-1);
    if (DECORATE(background_init)(state) < 0)
        return (-1);
    return (0);
}

void *DECORATE(init)(global_state *game_state)
{
    static int run_once;
    static DECORATE(state) scene_state;

    float w = game_state->width;
    float h = game_state->height;

    DEBUG("starting scene %s", "intro");

    if (run_once == 0) {
        scene_state.zoom_level = game_state->zoom_level;
        init_textbox(&scene_state.textbox, game_state->width, game_state->height);

        if (DECORATE(assets_init)(&scene_state, w, h) < 0)
            return (NULL);
        
        run_once = 1;
        scene_state.tri_update = 0;
        scene_state.tri_once = 0;
        scene_state.my_intro.tri_first = 1;
    }

    scene_state.glo_clock = sfClock_create();
    scene_state.game_state = game_state;
    game_state->scene_state = (void *)&scene_state;

    return (game_state->scene_state);
}