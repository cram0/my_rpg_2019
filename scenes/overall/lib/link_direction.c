#include <SFML/Graphics.h>

#include "../../../generated_code/origins.h"
#include "../../../generated_code/rects.h"

#include "../../lib/animation.h"

#include "../state.h"
#include "../decorator.h"

static int is_valid_direction(sfEvent event, int *combination)
{
    int up = sfKeyboard_isKeyPressed(sfKeyUp);
    int down = sfKeyboard_isKeyPressed(sfKeyDown);
    int left = sfKeyboard_isKeyPressed(sfKeyLeft);
    int right = sfKeyboard_isKeyPressed(sfKeyRight);
    int sum = up + down + left + right;

    *combination = (up ? 1 : 0) +
        (down ? 2 : 0) +
        (left ? 4 : 0) +
        (right ? 8 : 0);

    if (!sum && (event.type == sfEvtKeyPressed))
        return (0);

    if (sum > 2)
        return (0);

    if (sum == 1 || sum == 0)
        return (1);

    if ((up && left) || (up && right) || (down && left) || (down && right))
        return (1);

    return (0);
}

static int key_is_arrow(sfEvent event)
{
    if (event.key.code != sfKeyLeft &&
        event.key.code != sfKeyRight &&
        event.key.code != sfKeyUp &&
        event.key.code != sfKeyDown)
        return (0);
    return (1);
}

void DECORATE(link_direction)(link *lnk, sfEvent event)
{
    animation *lnk_ani = &lnk->ani;

    int combination = 0;
    lnk->diagonals = 0;

    if (!is_valid_direction(event, &combination))
        return;

    lnk->diagonals = combination;

    if (!key_is_arrow(event))
        return;

    lnk_ani->invert_y = 0;
    lnk->is_running = 0;

    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyUp)      lnk->direction = UP;
        if (event.key.code == sfKeyRight)   lnk->direction = RIGHT;
        if (event.key.code == sfKeyDown)    lnk->direction = DOWN;
        if (event.key.code == sfKeyLeft)    lnk->direction = LEFT;
        lnk->is_running = 1;
    }

    if (event.type == sfEvtKeyReleased) {
        if (lnk->direction == LEFT) {
            m_animation_set_rects(lnk_ani, link_left_idle);
            lnk_ani->invert_y = 1;
        }
        if (lnk->direction == RIGHT)
            m_animation_set_rects(lnk_ani, link_right_idle);
        if (lnk->direction == UP)
            m_animation_set_rects(lnk_ani, link_up_idle);
        if (lnk->direction == DOWN)
            m_animation_set_rects(lnk_ani, link_down_idle);
    }
    
    if (event.type == sfEvtKeyPressed) {
        if (lnk->direction == LEFT) {
            m_animation_set_rects(lnk_ani, link_left_walk);
            lnk->ani.invert_y = 1;
        }
        if (lnk->direction == RIGHT)
            m_animation_set_rects(lnk_ani, link_right_walk);
        if (lnk->direction == UP)
            m_animation_set_rects(lnk_ani, link_up_walk);
        if (lnk->direction == DOWN)
            m_animation_set_rects(lnk_ani, link_down_walk);
    }
}