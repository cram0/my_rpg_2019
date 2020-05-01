#include <SFML/Graphics.h>

#include "../../include/sfml_helpers.h"
#include "../../include/debug.h"

#include "animation.h"
#include "helpers.h"

void animation_set_hitbox(animation *ani, sfVector2f pos, sfVector2f offset)
{
    ani->hitbox_size = pos;
    ani->hitbox_offset = offset;
}

int animation_update_hitbox(animation *ani)
{
    if (!ani->hitbox) {
        ani->hitbox = sfRectangleShape_create();
        if (!ani->hitbox)
            return (-1);

        sfRectangleShape_setSize(ani->hitbox, ani->hitbox_size);
        sfRectangleShape_setOrigin(ani->hitbox,
            vec_center(ani->hitbox_size.x, ani->hitbox_size.y));
        sfRectangleShape_setScale(ani->hitbox, vec_same(ani->zoom));
        sfRectangleShape_setFillColor(ani->hitbox, sfTransparent);
        sfRectangleShape_setOutlineColor(ani->hitbox, sfBlue);
        sfRectangleShape_setOutlineThickness(ani->hitbox, 1);
    }

    sfVector2f position = vec_add(sfSprite_getPosition(ani->sprite), ani->hitbox_offset);
    sfRectangleShape_setPosition(ani->hitbox, position);

    return (0);
}

int animation_load_spritesheet(animation *ani, char *fp)
{
    ani->sprite = sfSprite_create();
    if (!ani->sprite)
        return (-1);

    ani->texture = sfTexture_createFromFile(fp, NULL);
    sfSprite_setTexture(ani->sprite, ani->texture, sfFalse);
    sfSprite_setScale(ani->sprite, vec_same(ani->zoom));

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

sfVector2f animation_get_position(animation *ani)
{
    return (ani->position);
}

void animation_set_zoom(animation *ani, float zoom)
{
    ani->zoom = zoom;
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
    sfRenderWindow_drawSprite(win, ani->sprite, states);

#ifndef NDEBUG
    sfRenderWindow_drawRectangleShape(win, ani->hitbox, NULL);
#endif
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
        if (*frame >= 3)
            return 3;
    }

    if (!ani->invert_y) {
        sfSprite_setPosition(ani->sprite, ani->position);
    } else {
        sfIntRect rect = ani->rects[*frame];
        sfSprite_setPosition(ani->sprite, (sfVector2f){
            ani->position.x,
            ani->position.y
        });
    }

    animation_update_hitbox(ani);
}