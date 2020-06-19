#ifndef LIBMX_H
#define LIBMX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>
#include <malloc/malloc.h>
#include <fcntl.h>

void mx_printerr(const char *s);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_print_strarr(char **arr, const char *delim);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);
int mx_strlen(const char *s);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
void *mx_memchr(const void *s, int c, size_t n);
int mx_count_words(const char *str, char c);

#endif
