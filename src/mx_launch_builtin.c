#include "ush.h"

void mx_launch_builtin(st_launch *l_inf, t_shell *shell) {
    int (*builtin_f[]) (char **, t_shell *) = {
        &mx_ush_pwd,
        &mx_ush_env,
        &mx_ush_which,
        &mx_ush_echo,
        &mx_ush_unset,
        &mx_ush_export,
        &mx_ush_exit,
        &mx_ush_cd,
        &mx_ush_true,
        &mx_ush_false,
        &mx_ush_alias,
        &mx_ush_return,
        &mx_ush_color_font,
        &mx_ush_color_bg
    };

    for (int i = 0; shell->builtins[i]; i++) {
        if (strcmp(l_inf->cmd_arr[0], shell->builtins[i]) == 0) {
            shell->status_exec = builtin_f[i](l_inf->cmd_arr, shell);
        }
    }
}
