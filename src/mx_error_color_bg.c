#include "ush.h"

int mx_error_color_bg(t_shell *shell, char** args, char* str) {
    int bg_reg = mx_check_color(shell->bg_color_reg, str);
    int bg_bold = mx_check_color(shell->bg_color_bold, str);
    int bg_high = mx_check_color(shell->bg_color_high, str);
    int bg_inten = mx_check_color(shell->bg_color_inten, str);

    if (bg_reg == -1 && bg_bold == -1 && bg_high == -1 && bg_inten == -1) {
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
