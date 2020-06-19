#include "ush.h"

void mx_error_path(char* str) {
    write (2, "cd: no such file or directory: ", 31);
    write (2, str, strlen(str));
    write (2, "\n", 1);
}
