#include "ush.h"

void mx_pushb_kv(t_kv **ptr, char *env) {
    t_kv *node = NULL;
    t_kv *tmp = NULL;

    if (!*ptr)
        return;
    node = mx_push_kv(env);
    tmp = *ptr;
    if (!*ptr) {
        *ptr = node;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
    return;
}
