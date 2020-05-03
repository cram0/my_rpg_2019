#include <SFML/Graphics.h>

#include "../../lib/map.h"
#include "../../../mobs/mob.h"
#include "../../../objects/objects.h"
#include "../../../include/sfml_helpers.h"
#include "../../../include/debug.h"
#include "../state.h"

int map_change(link *link, object *door, map *map)
{
   sfFloatRect link_hb = sfRectangleShape_getGlobalBounds(link->ani.hitbox);
   sfFloatRect door_hb = sfRectangleShape_getGlobalBounds(door->ani.hitbox);

   if (!sfFloatRect_intersects(&link_hb, &door_hb, NULL))
      return (0);

   sfSprite_destroy(map->sprite);
   sfSprite_destroy(map->sprite_color);

   map_init(map, door->mc.map_path, door->mc.color_path, map->zoom);
   map_set_position(map, door->mc.map_position);

   map->mobs = door->mc.mobs;
   map->objects = door->mc.object;

   return (1);
}