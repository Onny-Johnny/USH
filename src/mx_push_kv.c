#include "ush.h"

t_kv *mx_push_kv(char *env) { 
    t_kv *p = malloc(sizeof(t_kv));

    p->key = strndup(env, mx_get_char_index(env, '='));
    p->val = strndup(env + mx_get_char_index(env, '=') + 1,
                     strlen(env) - mx_get_char_index(env, '='));
    p->next = NULL;
    return p;
}
