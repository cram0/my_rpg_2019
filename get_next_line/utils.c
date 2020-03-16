#include "get_next_line.h"

int gnl_string_contains(char c, char *str)
{
    while (*str) {
        if (*str == c)
            return (1);
        str++;
    }
    return (0);
}

int gnl_match_position(char *str, char *delim, int *found)
{
    int i = 0;
    for (; str[i]; i++)
        if (gnl_string_contains(str[i], delim)) {
            *found = 1;
            return (i);
        }
    *found = 0;
    return (i);
}

int gnl_lshift_string(char *str, int size, int n)
{
    if (size < n || n <= 0)
        return (size);

    for (int i = n; i < size; i++)
        str[i - n] = str[i];
    str[size - n] = '\0';

    return (size - n);
}

char *gnl_realloc_and_append(char **dest, int *dest_size, char *src,
                                                        int src_size)
{
    char *new_string = malloc(*dest_size + src_size + 1);
    if (!new_string)
        return (NULL);

    for (int i = 0; i < *dest_size; i++)
        new_string[i] = (*dest)[i];

    if (*dest)
        free(*dest);

    for (int i = 0; i < src_size; i++)
        new_string[*dest_size + i] = src[i];
    new_string[*dest_size + src_size] = '\0';

    *dest_size += src_size;
    return ((*dest = new_string));
}