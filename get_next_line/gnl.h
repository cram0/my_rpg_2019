char *get_next_line(int fd);
char *get_next_token_select(int fd, char *delim, int (*select)(char *tok));
char *get_next_token(int fd, char *delim);