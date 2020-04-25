#include <SFML/Graphics.h>

#include "../../../include/sfml_helpers.h"
#include "../../../include/debug.h"

#include "entity.h"

int entity_load_spritesheet(entity *ent, char *fp)
{
    ent->sprite = sfSprite_create();
    if (!ent->sprite)
        return (-1);
    
    ent->texture = sfTexture_createFromFile(fp, NULL);
    sfSprite_setTexture(ent->sprite, ent->texture, sfFalse);

    return (0);
}

void entity_set_position(entity *ent, sfVector2f pos)
{
    ent->position = pos;
}