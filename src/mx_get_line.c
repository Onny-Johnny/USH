#include "ush.h"

char *mx_get_line(void) {
    char *line = NULL;
    size_t bufsize = 0;

    getline(&line, &bufsize, stdin);
    line[strlen(line) - 1] = '\0';
    return line;
}
