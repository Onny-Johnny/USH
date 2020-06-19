#include "ush.h"

void mx_help_color_f(t_shell *shell) {
    printf("Regular colors : ");
    for (int i = 0; shell->f_color_reg[i] != NULL; i++)
        printf("%s, ", shell->f_color_reg[i]);
    printf("\n");
    printf("Bold colors : ");
    for (int i = 0; shell->f_color_bold[i] != NULL; i++)
        printf("%s, ", shell->f_color_bold[i]);
    printf("\n");
    printf("Underline colors : ");
    for (int i = 0; shell->f_color_under[i] != NULL; i++)
        printf("%s, ", shell->f_color_under[i]);
    printf("\n");
}
