#include "ush.h"

int mx_check_color(char** array, char* str) {
    int index = 0;
    int find = -1;

    for (; array[index] != NULL; index++) {
        if (strcmp(array[index], str) == 0) {
            find = 1;
            return index;
        }
    }
    return find;
}
