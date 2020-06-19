#include "ush.h"

char *mx_token_line(char **line, char delim) {
    int len = 0;
    int delim_len = 0;
    int flag_delim = 0;
    int flag_quote = 0;
    int flag_dquote = 0;
    int flag_sub_quoted = 0;
    int flag_sub = 0;
    char *token = NULL;

    if ((*line) != NULL && delim) {
        flag_delim = (*line)[0] == delim ? 1 : 0;
        for(; (*line)[len]; len++) {
            if ((*line)[len + 1] && (*line)[len] == '$' && (*line)[len+1] == '(') {
                if (len > 0 && (*line)[len-1] == '\\')
                    continue;
                flag_sub++;
            }
            if ((*line)[len] == ')') {
                if (len > 0 && (*line)[len-1] == '\\')
                    continue;
                flag_sub--;
            }
            if ((*line)[len] == '`') {
                if (len > 0 && (*line)[len-1] == '\\')
                    continue;
                if (flag_sub_quoted == 0 || flag_sub_quoted % 2 == 0)
                    flag_sub_quoted++;
                else
                    flag_sub_quoted--;
            }
            if ((*line)[len] == '"' || (*line)[len] == '\'') {
                if (len > 0 && (*line)[len-1] == '\\')
                    continue;
                if ((*line)[len] == '\'' && flag_dquote == 0)
                    flag_quote = flag_quote == 0 ? 1 : 0;
                if ((*line)[len] == '"' && flag_quote == 0)
                    flag_dquote = flag_dquote == 0 ? 1 : 0;
                continue;
            }
            if (flag_quote == 1 || flag_dquote == 1 || flag_sub != 0 || flag_sub_quoted != 0)
                continue;
            if ((*line)[len] == delim) {
                while((*line)[len] == delim && flag_delim == 1) {
                    delim_len++;
                    if ((*line)[len+1] == delim)
                        len++;
                    else
                        break;
                }
                if (flag_delim == 1) {
                    flag_delim = 0;
                    continue;
                }
                if ((len > 0 && (*line)[len-1] == '\\') || len == 0)
                    continue;
                (*line) += delim_len;
                token = mx_strndup((*line), len-delim_len);
                (*line) += len;
                return token;
            }
        }
        if ((*line)[len] == '\0' && len - delim_len > 0) {
            (*line) += delim_len;
            token = mx_strndup((*line), len-delim_len);
            (*line) = NULL;
        }
    }
    return token;
}
