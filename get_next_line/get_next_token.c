#include "get_next_line.h"

char *get_next_token(int fd, char *delim)
{
    static char buf[GNL_READ_SIZE + 1];
    static int in_buf;
    int ss_size = 0, toksize, has_delim;
    char *ss = NULL;

    while (in_buf > 0 || (in_buf = read(fd, buf, GNL_READ_SIZE)) > 0) {
        buf[in_buf] = '\0';

        toksize = gnl_match_position(buf, delim, &has_delim);
        if (!gnl_realloc_and_append(&ss, &ss_size, buf, toksize))
            return (NULL);

        if (has_delim) {
            in_buf = gnl_lshift_string(buf, in_buf, toksize + 1);
            return (ss);
        }
        in_buf = 0;
    }

    return ((ss_size > 0) ? ss : NULL);
}