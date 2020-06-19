#include "ush.h"

t_cmd *mx_create_cmd(char *cmd, int i) {
    t_cmd *tr = malloc(sizeof(t_cmd));
    char *temp = NULL;

    if (cmd) {
        temp = mx_strndup(cmd, i);
        tr->cmd = mx_trim_token(temp);
        free(temp);
        temp = NULL;
    }
    else
        tr->cmd = NULL;
    tr->or = NULL;
    tr->and = NULL;
    return tr;
}
