#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../lib/animation.h"
#include "../lib/map.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"

const char LINK_PATH[] = "assets/link.gif";
const char MAP_PATH[] = "assets/maps/links_house.png";
const char MAP_COLOR_PATH[] = "maps_hitboxes/links_house.png";

int DECORATE(link_init)(DECORATE(state) *state, float width, float height)
{
    animation *ani = &state->my_link.ani;
    state->my_link.direction = DOWN;

    animation_set_zoom(ani, state->zoom_level);

    if (animation_load_spritesheet(ani, LINK_PATH) < 0)
        return (-1);

    animation_set_position(ani, vec_center(width, height));
    m_animation_set_rects(ani, link_down_idle);
    animation_set_hitbox(ani, vec_create(10, 10), vec_create(10, -10));
    animation_update_hitbox(ani);

    return (0);
}

int DECORATE(house_init)(DECORATE(state) *state)
{
    map *m = &state->my_map.m;
    map_init(m, MAP_PATH, MAP_COLOR_PATH, state->zoom_level);
}

void *DECORATE(init)(global_state *game_state)
{
    static int run_once;
    static DECORATE(state) scene_state = { 0 };

    float w = game_state->width;
    float h = game_state->height;
    float zoom = game_state->zoom_level;

    DEBUG("starting scene %s", "test");

    if (run_once == 0) {
        scene_state.zoom_level = zoom;
        scene_state.width = w;
        scene_state.height = h;

        if (DECORATE(link_init)(&scene_state, w, h) < 0 ||
            DECORATE(house_init)(&scene_state) < 0)
            return (NULL);

        run_once = 1;
    }

    scene_state.game_state = game_state;
    game_state->scene_state = (void *)&scene_state;

    return (game_state->scene_state);
}