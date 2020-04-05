#ifndef ASSOC_H
#define ASSOC_H

#include "dlist.h"

typedef struct {
    void *key;
    void *data;
} assoc_pair;

typedef struct {
    int (*match)(void *key1, void *key2);
    dlist pairs;
} alist;

void alist_init(alist *list, int (*match)(void *key1, void *key2),
                                                void (*destroy)(void *data));
void alist_destroy(alist *list);
int alist_insert(alist *list, void *key, void *data);
void *alist_search(alist *list, void *key);

#endif