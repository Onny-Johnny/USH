#include "ush.h"

void mx_envp_replace(t_shell **res, char *data) {
    t_variables *head = (*res)->variables;
    char *buf_name = strndup(data, mx_get_char_index(data, '='));

    while (head) {
        if (!strcmp(head->name, buf_name)) {
            mx_strdel(&head->value);
            head->value = strndup(data + mx_get_char_index(data, '=') + 1,
                                 strlen(data) - mx_get_char_index(data, '='));
            mx_strdel(&buf_name);
            return;
        }
        head = head->next;
    }
    mx_strdel(&buf_name);
    mx_envp_add(res, data);
}
