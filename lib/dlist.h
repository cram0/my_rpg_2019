#ifndef DLIST_H
#define DLIST_H

typedef struct dlist_node {
    void *data;
    struct dlist_node *prev, *next;
} dlist_node;

typedef struct dlist {
    int size;
    dlist_node *head, *tail;

    void (*destroy)(void *data);
} dlist;

void dlist_init(dlist *list, void (*destroy)(void *data));
void dlist_destroy(dlist *list);
int dlist_ins_next(dlist *list, dlist_node *element, void *data);
int dlist_ins_prev(dlist *list, dlist_node *element, void *data);
int dlist_remove(dlist *list, dlist_node *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif