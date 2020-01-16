#include "libmx.h"

static void mx_fill_null(int i, char *str);
static void elif_one(char *str, wchar_t c);
static void elif_two(char *str, wchar_t c);
static void elif_three(char *str, wchar_t c);

void mx_print_unicode(wchar_t c) {
    char str[5];

    if (c < 0x80) {
        str[0] = ((c>>0)  & 0x7F) | 0x00;
        mx_fill_null(1, str);
    }
    else if (c<0x0800) {
        elif_one(str, c);
    }
    else if (c<0x010000) {
        elif_two(str, c);
    }
    else if (c<0x110000) {
        elif_three(str, c);
    }
    write(1, str, mx_strlen(str));
}

static void mx_fill_null(int i, char *str) {
    for (;i < 5; i++){
        str[i] = '\0';
    }
}

static void elif_one(char *str, wchar_t c) {
    str[0] = ((c>>6)  & 0x1F) | 0xC0;
    str[1] = ((c>>0)  & 0x3F) | 0x80;
    mx_fill_null(2, str);
}

static void elif_two(char *str, wchar_t c) {
    str[0] = ((c>>12) & 0x0F) | 0xE0;
    str[1] = ((c>>6)  & 0x3F) | 0x80;
    str[2] = ((c>>0)  & 0x3F) | 0x80;
    mx_fill_null(3, str);
}

static void elif_three(char *str, wchar_t c) {
    str[0] = ((c>>18) & 0x07) | 0xF0;
    str[1] = ((c>>12) & 0x3F) | 0x80;
    str[2] = ((c>>6)  & 0x3F) | 0x80;
    str[3] = ((c>>0)  & 0x3F) | 0x80;
    mx_fill_null(4, str);
}
