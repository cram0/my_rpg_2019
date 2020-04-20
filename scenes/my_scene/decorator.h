#ifndef MY_SCENE_DECORATOR_H
#define MY_SCENE_DECORATOR_H

#ifdef DECORATE
#undef DECORATE
#endif

#define DECORATE(name) \
    my_scene##_##name

#endif