#include <stdlib.h>
#include <string.h>

char *substring(char *str, int start, int end)
{
    if (start < 0 || end < start || start > strlen(str))
        return (NULL);

    char *result = malloc(sizeof(char) * (end - start + 1));
    if (!result)
        return (NULL);

    for (int i = start, j = 0; i < end; i++, j++)
        result[j] = str[i];
    result[end - start] = '\0';

    return (result);
}
