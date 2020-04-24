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
} animation;

int animation_load_spritesheet(animation *ani, char *fp);
void animation_set_rects(animation *ani, sfVector2f *origs, sfIntRect *rects);
void animation_set_position(animation *ani, sfVector2f pos);
long animation_get_elapsed_mil(animation *ani, int idx);
void animation_clock_restart(animation *ani, int idx);
void animation_draw(animation *ani, sfRenderWindow *win, sfRenderStates *states);
int animation_update(animation *ani, float time);
void animation_set_zoom(animation *ani, float zoom);
int animation_update_hitbox(animation *ani);
void animation_set_hitbox(animation *ani, sfVector2f pos, sfVector2f offset);

#define m_animation_set_rects(ani, name) \
    animation_set_rects(ani, name##_origs, name##_rects)

#define init_animation(ani, fp, origs, rects, pos) \
    animation_load_spritesheet(ani, fp); \
    animation_set_rects(ani, origs, rects); \
    animation_set_position(ani, pos);

#endif