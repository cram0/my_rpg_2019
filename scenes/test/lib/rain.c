#include "rain.h"

#include "../state.h"

#include "../../../include/debug.h"
#include "../../../include/game_state.h"
#include "../../../include/sfml_helpers.h"

#include "../../lib/animation.h"
#include "../../lib/map.h"
#include "../../lib/sprite_paths.h"

#include "../../../generated_code/origins.h"
#include "../../../generated_code/rects.h"

const char RAIN_PATH[] = "assets/rain.png";

void init_rain(map *m, float zoom)
{
    m_animation_init(&m->rain_animation, zoom, RAIN_PATH, vec_create(0, 0), rain_noflash, vec_create(0, 0), vec_center(0, 0));
    sfColor save = sfSprite_getColor(m->rain_animation.sprite);
    sfSprite_setColor(m->rain_animation.sprite, (sfColor){save.r, save.g, save.b, 100});
}

void update_rain(map *m)
{
    animation_update(&m->rain_animation, 50);
}