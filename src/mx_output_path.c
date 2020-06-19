
#include "ush.h"


static char **get_arr(char *dir) {
    char **arr = NULL;
    int i = 0;

    arr = mx_strsplit_local(dir, '/');
    while (arr[i] != NULL) {
        if (strcmp(arr[i], ".") == 0) {
            free(arr[i]);
            arr[i] = mx_strnew(1);
        }
        if (strcmp(arr[i], "..") == 0) {
            free(arr[i]);
            arr[i] = mx_strnew(1);
            for (int j =i; j >= 0; j--) {
                if(strcmp(arr[j], "") != 0) {
                    free(arr[j]);
                    arr[j] = mx_strnew(1);
                    break ;
                }
            }
        }
        i++;
    }
    return arr;
}

static char *directory_path(char **array) {
    int i = 0;
    char *directory_path = NULL;

    while (array[i] != NULL) {
        if (strcmp(array[i], "") != 0) {
            char *tmp = mx_strjoin(directory_path, "/");
            if (directory_path)
                free(directory_path);
            directory_path = mx_strjoin(tmp, array[i]);
            free(tmp);
        }
        i++;
    }
    if (!directory_path)
        directory_path = strdup("/");

    return directory_path;
}

char *mx_output_path(char *path, char *move_to) {
    char *current_diratory = strdup(path);
    char *directory = NULL;
    char **arr = NULL;

    if (move_to[0] == '/') {
        directory = strdup(move_to);
    }
    else {
        char *tmp = mx_strjoin(current_diratory, "/");
        free(directory);
        directory = mx_strjoin(tmp, move_to);
        free(tmp);
    }
    arr = get_arr(directory);
    free(directory);
    directory = directory_path(arr);
    mx_del_strarr(&arr);
    free(current_diratory);
    return directory;
}
