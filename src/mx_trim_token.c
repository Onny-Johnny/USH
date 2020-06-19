#include "ush.h"

char *mx_trim_token(char *str) {
    int len;
    char *dst = NULL;

    if (!str)
        return NULL;
    len = mx_strlen(str);
    while (mx_isspace(str[len-1]) && len > 0) {
        if (len > 1 && str[len-2] == '\\')
            break;
        len--;
    }
    while (mx_isspace(*str) && len > 0) {
        str++;
        len--;
    }
    dst = mx_strnew(len);
    mx_strncpy(dst, str, len);
    return dst;
}
