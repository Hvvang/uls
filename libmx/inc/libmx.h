#ifndef LIBMX_H
#define LIBMX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <wchar.h>
#include <fcntl.h>
#include <malloc/malloc.h>

#define BUF_SIZE 8;



//***************************** Utils pack *******************************

int mx_calc_num(int number);
int mx_count_words(const char *str, char c);
int mx_get_char_index(const char *str, char c);
char *mx_itoa(int number);
char *mx_nbr_to_hex(unsigned long nbr);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
int mx_quicksort(char **arr, int left, int right);
void mx_str_reverse(char *s);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
void mx_strdel(char **str);
char *mx_strdup(const char *s1);
char *mx_strjoin_no_leaks(char *s1, char *s2);
char *mx_strjoin(const char *s1, const char *s2);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strndup(const char *s1, size_t n);
char *mx_strnew(const int size);
char **mx_strsplit(const char *s, char c);
void mx_swap_char(char *s1, char *s2);

#endif
