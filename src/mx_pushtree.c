#include "ush.h"

void mx_pushtree(t_li **forest, char *tokcoma) {
    t_li *new = malloc(sizeof(t_li));
    t_li *last = *forest;

    new->command = mx_treefill(tokcoma);
    new->next = NULL;
    if (*forest == NULL) {
        *forest = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
}
