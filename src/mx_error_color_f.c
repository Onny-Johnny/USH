#include "ush.h"

 int mx_error_color_f(t_shell *shell, char** args, char* str) {
    int f_reg = mx_check_color(shell->f_color_reg, str);
    int f_bold = mx_check_color(shell->f_color_bold, str);
    int f_underline = mx_check_color(shell->f_color_under, str);

    if (f_reg == -1 && f_bold == -1 && f_underline == -1) {
        mx_printerr(args[1]);
        mx_printerr(" color not found\n");
        mx_printerr("please enter -color help- for color info\n");
        shell->status = 1;
        return shell->status;
    }
    if (args[2]) {
        shell->status = 1;
        mx_printerr("color: too many arguments\n");
        return shell->status;
    }
    return shell->status;
}
