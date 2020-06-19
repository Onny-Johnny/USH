#include "ush.h"

void mx_ch_dir(char *res_path, char* path, t_shell *shell) {
    chdir(res_path);
    setenv("OLDPWD", path, 1);
    shell->pwd = strdup(getenv("OLDPWD"));
    setenv("PWD", res_path, 1);
}
