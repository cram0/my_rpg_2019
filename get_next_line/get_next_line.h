#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

#include "gnl.h"

#define GNL_READ_SIZE 4096

int gnl_string_contains(char c, char *str);
int gnl_match_position(char *str, char *delim, int *found);
int gnl_lshift_string(char *str, int size, int n);
char *gnl_realloc_and_append(char **dest, int *dest_size, char *src,
                                                        int src_size);