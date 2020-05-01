#include "boomerang.h"

void boomerang_launch(boomerang *boomr, int dir, sfEvent event)
{
    if (event.key.code != sfKeyF)
        return;
    if (event.type == sfEvtKeyReleased) {
        DEBUG("DIR= %d", dir);
        if (boomr->equiped == 1 && boomr->launch == -1) {
            boomr->launch = dir;
        }
    }
}