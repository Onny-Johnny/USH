#include "ush.h"

void mx_envp_add(t_shell **res, char *data) {
    t_variables *buf = NULL;
    t_variables *head = (*res)->variables;

    if (!data)
        return;
    buf = malloc(sizeof(t_shell));
    buf->name = strndup(data, mx_get_char_index(data, '='));
    buf->value = strndup(data + mx_get_char_index(data, '=') + 1,
                         strlen(data) - mx_get_char_index(data, '='));
    buf->next = NULL;
    if (!*res) {
        (*res)->variables = buf;
        return;
    }
    while (head->next) {
        head = head->next;
    }
    head->next = buf;
}
