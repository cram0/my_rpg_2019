#ifndef INTERACTIONS_H_
#define INTERACTIONS_H_

#include <SFML/Graphics.h>

#include "../state.h"
#include "../../../objects/objects.h"

void interaction_event(sfEvent event, link *lnk, object *objects, map *maps);
void link_interaction(link *lnk, object *objects, map *maps);
void link_throw_object(link *lnk);

#endif