#include "boomerang.h"

void normal_move(boomerang *boomr, float speed)
{
    if (boomr->launch == 0) {
        sfSprite_move(boomr->sprite, (sfVector2f){0.0, -speed});
    }
    if (boomr->launch == 1) {
        sfSprite_move(boomr->sprite, (sfVector2f){0.0, speed});
    }
    if (boomr->launch == 2) {
        sfSprite_move(boomr->sprite, (sfVector2f){-speed, 0.0});
    }
    if (boomr->launch == 3) {
        sfSprite_move(boomr->sprite, (sfVector2f){ speed, 0.0});
    }
}

void back_move(boomerang *boomr, float speed)
{
    sfVector2f vector_back;
    sfVector2f pt1 = boomr->old_origine;
    sfVector2f pt2 = sfSprite_getPosition(boomr->sprite);

    float mag = sqrt(pow(pt2.x - pt1.x, 2) + pow(pt2.y - pt1.y, 2));

    vector_back.x = (pt2.x - pt1.x) * (-1);
    vector_back.y = (pt2.y - pt1.y) * (-1);

    vector_back.x /= mag / speed;
    vector_back.y /= mag / speed;

    sfSprite_move(boomr->sprite, vector_back);
    if (!distance(pt1, pt2, 20)) {
        boomr->back = 0;
        boomr->launch = -1;
        sfSprite_setRotation(boomr->sprite, 0);
        sfSprite_setPosition(boomr->sprite, boomr->origine);
    }
}

void move_boomrang(boomerang *boomr)
{
    float speed = 10;
    sfSprite_rotate(boomr->sprite, 45);
    if (boomr->back == 0) {
        normal_move(boomr, speed);
    } else {
        back_move(boomr, speed);
    }

}