#include <stdio.h>
#include <stdlib.h>

#include "../lib/dlist.h"

int **range(int end)
{
    int **tab = malloc(sizeof(int *) * (end + 1));

    for (int i = 0; i < end; i++) {
        tab[i] = malloc(sizeof(int));
        *tab[i] = i + 1;
    }

    tab[end] = NULL;

    return (tab);
}

int main(void)
{
    dlist list;
    dlist_init(&list, free);

    int **tab = range(7);

    for (int i = 0; tab[i]; i++) {
        dlist_ins_prev(&list, list.head, tab[i]);
        printf("succesfully inserted %d\n", *(int *)list.head->data);
    }

    puts("---");

    int *data;
    for (int i = 0; tab[i]; i++) {
        dlist_remove(&list, list.head, (void **)&data);
        printf("succesfully removed %d\n", *data);
        free(data);
    }

    free(tab);
}