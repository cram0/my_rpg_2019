#include "get_next_line.h"

char *get_next_token_select(int fd, char *delim, int (*select)(char *tok))
{
    char *tok = get_next_token(fd, delim);
    if (!tok || (select && select(tok)))
        return (tok);
    else {
        free(tok);
        return (NULL);
    }
}