#include "init_music.h"

#include <SFML/Audio.h>

#include "../../lib/map.h"

const char OVERWORLD_MUSIC[] = "audio/musics/rain.ogg";
const char RAIN_INSIDE[] = "audio/sounds/Rain_In.wav";
const char RAIN_OUTSIDE[] = "audio/sounds/Rain_Out.wav";

void init_music(map *m)
{
    m->overworld_music = sfMusic_createFromFile(OVERWORLD_MUSIC);
    sfMusic_setLoop(m->overworld_music, sfTrue);
    sfMusic_setVolume(m->overworld_music, 10.0);
    sfMusic_play(m->overworld_music);

    m->rain_sound_inside = sfSound_create();
    m->rain_sound_outside = sfSound_create();

    sfSoundBuffer *buff = sfSoundBuffer_createFromFile(RAIN_INSIDE);
    sfSound_setBuffer(m->rain_sound_inside, buff);

    buff = sfSoundBuffer_createFromFile(RAIN_OUTSIDE);
    sfSound_setBuffer(m->rain_sound_outside, buff);

    sfSound_setLoop(m->rain_sound_inside, sfTrue);
    sfSound_setLoop(m->rain_sound_outside, sfTrue);

    sfSound_setVolume(m->rain_sound_inside, 10.0);
    sfSound_setVolume(m->rain_sound_outside, 10.0);

    sfSound_play(m->rain_sound_inside);
}