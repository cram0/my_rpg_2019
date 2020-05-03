#include "equiped_stuff.h"

void synchro_boomrang(boomerang *boomr, items *item)
{
    if (item->equiped == 1) {
        boomr->equiped = 1;
    } else {
        boomr->equiped = 0;
    }
}

void synchro_level(equipment *stuff, items *item)
{
    stuff->max_health = 10 + item->level * 2;
}