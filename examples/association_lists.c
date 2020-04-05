#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/alist.h"

void destroy_pair(void *pair)
{
    assoc_pair *tmp = pair;
    free(tmp->data);
    free(tmp->key);
    free(pair);
}

int main(void)
{
    alist list;
    alist_init(&list, strcmp, destroy_pair);

    alist_insert(&list, strdup("hello"), strdup("world"));
    alist_insert(&list, strdup("new york"), strdup("USA"));
    alist_insert(&list, strdup("new york"), strdup("USB"));

    printf("%s\n", (char *)alist_search(&list, "hello"));
    printf("%s\n", (char *)alist_search(&list, "new york"));

    alist_destroy(&list);

    return (0);
}
