#ifndef OVERALL_DECORATOR_H
#define OVERALL_DECORATOR_H

#ifdef DECORATE
#undef DECORATE
#endif

#define DECORATE(name) \
    overall##_##name

#endif