#include "decorator.h"

#include "state.h"

#include "../../include/debug.h"
#include "../../include/game_state.h"
#include "../../include/sfml_helpers.h"

#include "../../generated_code/origins.h"
#include "../../generated_code/rects.h"

const char LINK_PATH[] = "assets/link.gif";
const char MAP_PATH[] = "assets/maps/links_house.png";
const char MAP_COLOR_PATH[] = "maps_hitboxes/links_house.png";

int link_init(DECORATE(state) *state, float width, float height)
{
    animation *ani = &state->my_link.ani;
    state->my_link.direction = RIGHT;

    if (animation_load_spritesheet(ani, LINK_PATH) < 0)
        return (-1);

    animation_set_zoom(ani, state->zoom_level);
    animation_set_position(ani, vec_center(width, height));
    animation_set_rects(ani, link_right_walk_origs, link_right_walk_rects);

    return (0);
}

int map_init(DECORATE(state) *state)
{
    state->my_map.pos = (sfVector2f){0.0, 0.0};

    state->my_map.sprite = sfSprite_create();
    state->my_map.texture = sfTexture_createFromFile(MAP_PATH, NULL);

    state->my_map.sprite_color = sfSprite_create();
    state->my_map.texture_color = sfTexture_createFromFile(MAP_COLOR_PATH, NULL);

    sfSprite_setTexture(state->my_map.sprite, state->my_map.texture, sfFalse);
    sfSprite_setTexture(state->my_map.sprite_color, state->my_map.texture_color, sfFalse);

    sfSprite_setPosition(state->my_map.sprite, state->my_map.pos);
    sfSprite_setPosition(state->my_map.sprite_color, state->my_map.pos);

    sfSprite_setScale(state->my_map.sprite, vec_same(state->zoom_level));
    sfSprite_setScale(state->my_map.sprite_color, vec_same(state->zoom_level));

    sfSprite_setColor(state->my_map.sprite_color, (sfColor){255, 255, 255, 100});

    state->my_map.hitbox_dump = sfTexture_copyToImage(state->my_map.texture_color);
}

void *DECORATE(init)(global_state *game_state)
{
    static int run_once;
    static DECORATE(state) scene_state = { 0 };

    DEBUG("starting scene %s", "test");

    if (run_once == 0) {
        scene_state.zoom_level = game_state->zoom_level;
        if (link_init(&scene_state, game_state->width, game_state->height) < 0)
            return (NULL);
        map_init(&scene_state);
        run_once = 1;
    }

    scene_state.game_state = game_state;
    game_state->scene_state = (void *)&scene_state;

    return (game_state->scene_state);
}