#ifndef XXXXX_DECORATOR_H
#define XXXXX_DECORATOR_H

#ifdef DECORATE
#undef DECORATE
#endif

#define DECORATE(name) \
    xxxxx##_##name

#endif