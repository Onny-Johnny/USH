#include "ush.h"

void mx_check_flags(char** args, t_cd *cd_flags, int count_flags) {
    for (int i = 1; i <= count_flags; i++) {
        for (int j = 0; args[i][j] != '\0'; j++) {
            if (args[i][j] == 's')
                cd_flags->s = 1;
            if (args[i][j] == 'P')
                cd_flags->P = 2;
        }
    }
}
