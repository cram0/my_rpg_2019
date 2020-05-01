#ifndef INTRO_DECORATOR_H
#define INTRO_DECORATOR_H

#ifdef DECORATE
#undef DECORATE
#endif

#define DECORATE(name) \
    intro##_##name

#endif