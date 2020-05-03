#include "init_music.h"

#include <SFML/Audio.h>

#include "../../lib/map.h"

const char OVERWORLD_MUSIC[] = "audio/musics/rain.ogg";

void init_music(map *m)
{
    m->overworld_music = sfMusic_createFromFile(OVERWORLD_MUSIC);
    sfMusic_setLoop(m->overworld_music, sfTrue);
    sfMusic_setVolume(m->overworld_music, 10.0);
    sfMusic_play(m->overworld_music);
}