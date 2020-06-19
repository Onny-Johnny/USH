#include "ush.h"

t_kv *mx_create_kv(char **environ) {
    t_kv *en = mx_push_kv(environ[0]);

    for (int i = 1; environ[i]; i++)
        mx_pushb_kv(&en, environ[i]);
    return en;
}
