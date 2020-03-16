#include "get_next_line.h"

char *get_next_line(int fd)
{
    return (get_next_token(fd, "\n"));
}