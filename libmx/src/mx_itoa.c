#include "libmx.h"

static bool mx_isNegative(int number);
static char *mx_parser(int i, bool isNegative, int number, char *str);

char* mx_itoa(int number) {
    char str[12];
    int i = 0;
    bool isNegative = mx_isNegative(number);
    char *res;

    if (number == 0) {
        str[i++] = '0';
        str[i] = '\0';
    }
    if (isNegative) {
      if (number == -2147483648) {
        str[i++] = -1 * (number % 10) + 48;
        number /= 10;
      }
      number = -number;
    }
    mx_parser(i, isNegative, number, str);
    res = mx_strdup(str);
    return res;
}

static bool mx_isNegative(int number) {
    if (number < 0) {
        return true;
    }
    return false;
}

static char *mx_parser(int i, bool isNegative, int number, char *str) {
    while (number != 0) {
        str[i++] = number % 10 + 48;
        number /= 10;
    }
    if (isNegative)
        str[i++] = '-';
    str[i] = '\0';
    mx_str_reverse(str);
    return str;
}
