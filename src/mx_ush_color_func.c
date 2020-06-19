#include "ush.h"

void mx_help_color_bg(t_shell *shell) {
    printf("Regular colors : ");
    for (int i = 0; shell->bg_color_reg[i] != NULL; i++) {
        printf("%s, ", shell->bg_color_reg[i]);
    }
    printf("\n");
    printf("Regular intensive colors : ");
    for (int i = 0; shell->bg_color_high[i] != NULL; i++)
        printf("%s, ", shell->bg_color_reg[i]);
    printf("\n");
    printf("Bold colors : ");
    for (int i = 0; shell->bg_color_bold[i] != NULL; i++)
        printf("%s, ", shell->bg_color_reg[i]);
    printf("\n");
    printf("Underline colors : ");
    for (int i = 0; shell->bg_color_inten[i] != NULL; i++)
        printf("%s, ", shell->bg_color_reg[i]);
    printf("\n");
}
