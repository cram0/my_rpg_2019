#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.h>

typedef struct {
    sfVector2f position;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f *origins;
    sfIntRect *rects;
    sfClock *clocks[5];

    sfRectangleShape *hitbox;
    sfVector2f hitbox_size;
    sfVector2f hitbox_offset;

    float zoom;

    int invert_y;

    int frame;
    int is_drawable;
} animation;

int animation_load_spritesheet(animation *ani, char *fp);

/*
** Use m_animation_set_rects instead
*/
void animation_set_rects(animation *ani, sfVector2f *origs, sfIntRect *rects);

/*
** Used to change the position of the sprite.
*/
void animation_set_position(animation *ani, sfVector2f pos);

/*
** See equivalent functions documentation in map.h
*/
long animation_get_elapsed_mil(animation *ani, int idx);
void animation_clock_restart(animation *ani, int idx);

/*
** To be run every single time your scene's draw function is called.
*/
void animation_draw(animation *ani, sfRenderWindow *win, sfRenderStates *states);

/*
** To be run every single time your scene's update function is called.
*/
int animation_update(animation *ani, float time);

/*
** Use m_animation_init instead.
*/
void animation_set_zoom(animation *ani, float zoom);

/*
** Use animation update_instead;
*/
int animation_update_hitbox(animation *ani);

/*
** Use m_animation_init instead.
*/
void animation_set_hitbox(animation *ani, sfVector2f pos, sfVector2f offset);

/*
** Returns the current position of the animation sprite.
*/
sfVector2f animation_get_position(animation *ani);

/*
** A shortcut for initializing animations: see scenes/test/init.c for an
** example.
** Each hitbox a size and an offset (in case it is not perfectly centered)
*/
#define m_animation_init(ani, zoom, spritesheet, initial_position, \
                         initial_animation, hitbox_size, hitbox_offset) \
    animation_set_zoom(ani, zoom); \
    if (animation_load_spritesheet(ani, spritesheet) < 0) \
        return (-1); \
    animation_set_position(ani, initial_position); \
    m_animation_set_rects(ani, initial_animation); \
    animation_set_hitbox(ani, hitbox_size, hitbox_offset); \
    animation_update_hitbox(ani);


/*
** Example:
**
** if you want to use the animation defined by link_idle_down_rects and
** link_idle_down_origs, make a call to m_animation_set_rects with
** link_idle_down as second parameter.
*/
#define m_animation_set_rects(ani, name) \
    animation_set_rects(ani, name##_origs, name##_rects)

#endif