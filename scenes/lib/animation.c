#include <SFML/Graphics.h>

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"

#include "animation.h"
#include "helpers.h"

int animation_load_spritesheet(animation *ani, char *fp)
{
    ani->sprite = sfSprite_create();
    if (!ani->sprite)
        return (-1);

    ani->texture = sfTexture_createFromFile(fp, NULL);
    sfSprite_setTexture(ani->sprite, ani->texture, sfFalse);

    return (0);
}

void animation_set_rects(animation *ani, sfVector2f *origs, sfIntRect *rects)
{
    if (ani->origins != origs && ani->rects != rects)
        ani->frame = -1;

    ani->origins = origs;
    ani->rects = rects;

    int i = ani->frame == -1 ? 0 : ani->frame;
}

void animation_set_position(animation *ani, sfVector2f pos)
{
    ani->position = pos;
    //sfSprite_setPosition(ani->sprite, pos);
}

void animation_set_zoom(animation *ani, float zoom)
{
    sfSprite_setScale(ani->sprite, (sfVector2f){zoom, zoom});
}

long animation_get_elapsed_mil(animation *ani, int idx)
{
    sfClock **clock = &ani->clocks[idx];
    if (!(*clock)) {
        *clock = sfClock_create();
        if (!(*clock))
            return (-1);
        return (0);
    }

    return (GET_ELAPSED_MSECS(*clock));
}

void animation_clock_restart(animation *ani, int idx)
{
    sfClock *clock = ani->clocks[idx];
    if (clock) {
        sfClock_restart(clock);
    }
}

void animation_draw(animation *ani, sfRenderWindow *win, sfRenderStates *states)
{
    if (ani->is_drawable > 0)
        sfRenderWindow_drawSprite(win, ani->sprite, states);
}

static inline my_abs(float a)
{
    return (a > 0 ? a : -a);
}

int animation_update(animation *ani, float time)
{
    int *frame = &(ani->frame);
    float elapsed = animation_get_elapsed_mil(ani, 0);

    if (elapsed > time) {
        sfIntRect current = ani->rects[*frame + 1];
        if (*frame > -1 && rect_iszero(ani->rects[*frame + 1])) {
            *frame = 0;
        } else {
            (*frame)++;
        }
        sfIntRect rect = ani->rects[*frame];

        sfVector2f origin = ani->origins[*frame];
        sfVector2f relative = get_relative_origin(rect, origin);

        sfIntRect final_rect = (ani->invert_y ? invert_y_rect(rect) : rect);
        sfVector2f final_orig = (ani->invert_y ? invert_y_origin(relative, rect) : relative);

        sfSprite_setTextureRect(ani->sprite, final_rect);
        sfSprite_setOrigin(ani->sprite, final_orig);
        animation_clock_restart(ani, 0);

        if (*frame > 86)
            return 2;
    }

    if (!ani->invert_y) {
        sfSprite_setPosition(ani->sprite, ani->position);
    } else {
        sfIntRect rect = ani->rects[*frame];
        sfVector2f origin = ani->origins[*frame];
        sfVector2f relative = get_relative_origin(rect, origin);
        sfSprite_setPosition(ani->sprite, (sfVector2f){
            ani->position.x + rect.width,
            ani->position.y
        });
    }
}