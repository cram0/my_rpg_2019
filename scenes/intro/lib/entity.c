#include <SFML/Graphics.h>

#include "../../../include/sfml_helpers.h"
#include "../../../include/debug.h"

#include "entity.h"

int entity_load_spritesheet(entity *ent, char *fp)
{
    ent->sprite = sfSprite_create();
    if (!ent->sprite)
        return (-1);
    
    ent->texture = sfTexture_createFromFile(fp, NULL);
    sfSprite_setTexture(ent->sprite, ent->texture, sfFalse);

    return (0);
}

void entity_set_position(entity *ent, sfVector2f pos)
{
    sfSprite_setPosition(ent->sprite, pos);
}

void entity_set_zoom(entity *ent, float zoom)
{
    sfSprite_setScale(ent->sprite, (sfVector2f){zoom, zoom});
}

long entity_get_elapsed_mil(entity *ent, int idx)
{
    sfClock **clock = &ent->clocks[idx];
    if (!(*clock)) {
        *clock = sfClock_create();
        if (!(*clock))
            return (-1);
        return (0);
    }

    return (GET_ELAPSED_MSECS(*clock));
}

void entity_clock_restart(entity *ent, int idx)
{
    sfClock *clock = ent->clocks[idx];
    if (clock) {
        sfClock_restart(clock);
    }
}

void entity_draw(entity *ent, sfRenderWindow *win, sfRenderStates *states)
{
    if (ent->is_drawable > 0)
        sfRenderWindow_drawSprite(win, ent->sprite, states);
}
