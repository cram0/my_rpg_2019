#include "boomerang.h"

void init_sound(boomerang *boomr)
{
    boomr->sound = sfSound_create();
    boomr->sound_buffer = sfSoundBuffer_createFromFile(
                            "./audio/sounds/Boomerang.wav");
    sfSound_setBuffer(boomr->sound, boomr->sound_buffer);
    boomr->sound_clock = sfClock_create();
}

void init_boomerang(boomerang *boomr, float zoom_level,
                    float width, float height, sfVector2f map_pos)
{
    init_sound(boomr);
    boomr->sprite = sfSprite_create();
    boomr->texture = sfTexture_createFromFile("./assets/objects.gif", NULL);
    sfSprite_setTexture(boomr->sprite, boomr->texture, sfFalse);
    sfSprite_setTextureRect(boomr->sprite, object_boomerang_rects[0]);
    sfSprite_setOrigin(boomr->sprite,
                        vec_same((object_boomerang_rects[0].width) / 2));
    sfSprite_setScale(boomr->sprite, vec_same(zoom_level - 1));

    boomr->origine = (sfVector2f){width / 2 - 15, height / 2 - 20};
    boomr->old_origine = (sfVector2f){width / 2 - 15, height / 2 - 20};

    sfSprite_setPosition(boomr->sprite, boomr->origine);
    boomr->old_pos = map_pos;
    boomr->equiped = 1;
    boomr->launch = -1;
    boomr->back = 0;
    boomr->last_mob_id = 0;
}

void new_pos(boomerang *boomr, sfVector2f map_pos)
{
    sfVector2f new_pos = (sfVector2f){0.0, 0.0};

    new_pos.x = (boomr->old_pos.x - map_pos.x) * (-1);
    new_pos.y = (boomr->old_pos.y - map_pos.y) * (-1);

    boomr->old_pos = map_pos;
    boomr->ori_launch.x += new_pos.x;
    boomr->ori_launch.y += new_pos.y;
    sfSprite_move(boomr->sprite, new_pos);
}

int distance(sfVector2f pt1, sfVector2f pt2, int max)
{
    float distance = 0;
    distance = sqrt(pow(pt2.x - pt1.x, 2) + pow(pt2.y - pt1.y, 2));
    if (distance > max) {
        return (1);
    } else {
        return (0);
    }
}

void boomerang_draw(sfRenderWindow *win, boomerang *boomr, sfVector2f map_pos)
{
    int ms = GET_ELAPSED_MSECS(boomr->sound_clock);
    if (boomr->equiped == 1) {
        
        if (boomr->launch != -1) {
            if (ms > 100) {
                sfSound_play(boomr->sound);
                sfClock_restart(boomr->sound_clock);
            }
            new_pos(boomr, map_pos);
            move_boomrang(boomr);
        } else {
            boomr->ori_launch = sfSprite_getPosition(boomr->sprite);
            boomr->old_pos = map_pos;
        }
        if (distance(boomr->ori_launch,
            sfSprite_getPosition(boomr->sprite), 300)
            && boomr->back == 0) {
            boomr->back = 1;
            boomr->last_mob_id = 0;
        }
        sfRenderWindow_drawSprite(win, boomr->sprite, NULL);
    }
}