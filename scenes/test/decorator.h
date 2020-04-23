#ifndef TEST_DECORATOR_H
#define TEST_DECORATOR_H

#ifdef DECORATE
#undef DECORATE
#endif

#define DECORATE(name) \
    test##_##name

#endif