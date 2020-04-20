#ifndef SAMPLE_SCENE_DECORATOR_H
#define SAMPLE_SCENE_DECORATOR_H

#ifdef DECORATE
#undef DECORATE
#endif

#define DECORATE(name) \
    sample_scene##_##name

#endif