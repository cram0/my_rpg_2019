#include "body_attack.h"

void init_body_attack(body_att *attack)
{
    attack->sound = sfSound_create();
    attack->sound_buffer = sfSoundBuffer_createFromFile(
                            "./audio/sounds/Sword1.wav");
    sfSound_setBuffer(attack->sound, attack->sound_buffer);
    attack->att_clock = sfClock_create();
    attack->rects = link_down_attack_rects;
    attack->origins = link_down_attack_origs;
    attack->dir = -1;
    attack->index = 0;
    attack->attack = 0;
    attack->power = 4;
}

void body_attack(body_att *attack, int direction, equipment *stuff
                ,sfEvent event) 
{
    if (event.key.code != sfKeyG)
        return;
    if (event.key.type == sfEvtKeyReleased && attack->attack != 1) {
        sfSound_play(attack->sound);
        sfClock_restart(attack->att_clock);
        sfClock_restart(stuff->regeneration);
        attack->dir = direction;
        attack->attack = 1;
        attack->last_mob_id = 0;
    }
}

int end_of_tab(sfIntRect rect)
{
    if (rect.height == 0 && rect.left == 0 &&
        rect.top == 0 && rect.width == 0) {
            return (1);
    }
    return (0);
}

void chose_orientation(body_att *attck, animation *ani)
{
    DEBUG("INVERT= %d", ani->invert_y);
    if (attck->dir == 0) {
        attck->rects = link_up_attack_rects;
        attck->origins = link_up_attack_origs;
    }
    if (attck->dir == 1) {
        attck->rects = link_down_attack_rects;
        attck->origins = link_down_attack_origs;
    }
    if (attck->dir == 2) {
        attck->rects = link_right_attack_rects;
        attck->origins = link_right_attack_origs;
    }
    if (attck->dir == 3) {
        attck->rects = link_left_attack_rects;
        attck->origins = link_left_attack_origs;
    }

}

void attack_animation(body_att *attck, animation *ani)
{
    int ms = GET_ELAPSED_MSECS(attck->att_clock);
    chose_orientation(attck, ani);
    if (attck->index == 0) {
        attck->oldorigins = ani->origins;
        attck->oldrect = ani->rects;
    }
    ani->invert_y = (attck->dir == 3) ? 1 : 0;
    if (ms > 30) {
        if (end_of_tab(attck->rects[attck->index])) {
            attck->attack = 0;
            attck->index = 0;
            ani->origins = attck->oldorigins;
            ani->rects = attck->oldrect;
            if (attck->dir >= 2)
                ani->invert_y = ani->invert_y ? 0 : 1;
            else
                ani->invert_y = 0;
            return;
        }
        ani->rects = attck->rects;
        ani->origins = attck->origins;
        attck->index++;
        sfClock_restart(attck->att_clock);
    }
}
