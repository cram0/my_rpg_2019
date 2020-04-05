#include <stdlib.h>

#include "alist.h"

void alist_init(alist *list, int (*match)(void *key1, void *key2),
                                                void (*destroy)(void *data))
{
    list->match = match;
    dlist_init(&list->pairs, destroy);
}

void alist_destroy(alist *list)
{
    dlist_destroy(&list->pairs);
}

int alist_insert_assoc_pair(alist *list, assoc_pair *pair)
{
    int inserted = 0;

    dlist_node *current_node = list->pairs.head;
    while (current_node) {
        assoc_pair *current_pair = (assoc_pair *)current_node->data;
        if (!list->match(pair->key, current_pair->key)) {
            if (list->pairs.destroy)
                list->pairs.destroy(current_pair);
            current_node->data = (void *)pair;
            inserted = 1;
        }

        current_node = current_node->next;
    }

    if (!inserted) {
        return (dlist_ins_prev(&list->pairs, list->pairs.head, (void *)pair));
    }

    return (0);
}

int alist_insert(alist *list, void *key, void *data)
{
    assoc_pair *new_element = malloc(sizeof(assoc_pair));
    if (!new_element)
        return (-1);
    
    new_element->key = key;
    new_element->data = data;

    return (alist_insert_assoc_pair(list, new_element));
}

void *alist_search(alist *list, void *key)
{
    dlist_node *current_node = list->pairs.head;
    while (current_node) {
        assoc_pair *current_pair = (assoc_pair *)current_node->data;
        if (!list->match(key, current_pair->key)) {
            return (current_pair->data);
        }

        current_node = current_node->next;
    }

    return (NULL);
}