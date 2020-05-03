#ifndef EQUIPED_STUFF_H
#define EQUIPED_STUFF_H

#include <SFML/Graphics.h>

#include "../lib/inventory.h"
#include "../lib/hud.h"
#include "../lib/boomerang.h"

void synchro_boomrang(boomerang *boomr, items *item);
void synchro_level(equipment *stuff, items *item);

#endif