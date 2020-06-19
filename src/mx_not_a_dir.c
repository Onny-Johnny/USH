#include "ush.h"

void mx_not_a_dir(char* str) {
    char* str_err = "cd: not a directory: ";
    write(2, str_err, strlen(str_err));
    write(2, str, strlen(str));
    write(2, "\n", 1);
}
