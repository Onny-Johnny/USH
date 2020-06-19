#include "ush.h"

t_li *mx_create_forest(char *line) {
    char **tokcoma = NULL;
    t_li *forest = NULL;

    tokcoma = mx_tokcoma(line);
    if (tokcoma)
        for (int i = 0; tokcoma[i]; i++) {
            if (forest == NULL) {
                forest = malloc(sizeof(t_li));
                forest->command = mx_treefill(tokcoma[i]);
                forest->next = NULL;
            }
            else
                mx_pushtree(&forest, tokcoma[i]);
        }
    return forest;
}
