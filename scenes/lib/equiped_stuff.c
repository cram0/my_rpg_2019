#include "equiped_stuff.h"

void synchro_boomrang(boomerang *boomr, items *item)
{
    if (item->equiped == 1) {
        boomr->equiped = 1;
    } else {
        boomr->equiped = 0;
    }
}