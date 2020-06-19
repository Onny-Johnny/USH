#include "ush.h"

static void tokenize(char *line, char ***tokens, int bufsize, int position) {
    char *token = NULL;
    char *line_cp = line;

    token = mx_token_line(&line_cp, ';');
    while(token != NULL) {
        (*tokens)[position++] = mx_trim_token(token);
        if (position >= bufsize) {
            bufsize += 64;
            *tokens = realloc(tokens, bufsize * sizeof(char *));
        }
        (*tokens)[position] = NULL;
        token = mx_token_line(&line_cp, ';');
    }
}

char **mx_tokcoma(char *line) {
    int bufsize = 64;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));

    *tokens = NULL;
    if (!tokens) {
        fprintf(stderr, "u$h: allocation error\n");
        exit(EXIT_FAILURE);
    }
    tokenize(line, &tokens, bufsize, position);
    if (tokens[0] == NULL) {
        mx_del_strarr(&tokens);
        return NULL;
    }
    return tokens;
}
