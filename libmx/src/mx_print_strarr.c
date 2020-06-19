#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (delim != NULL || arr != NULL) {
        for (int i = 0; arr[i] != NULL; i++) {
            printf("%s", arr[i]);
            if (arr[i + 1] != NULL)
                printf("%s", delim);
            else 
                mx_printchar('\n');
       }
    }
}
