#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long length = 0;
    unsigned long answer = 0;
    unsigned long osnova = 1;

    while (hex[length] != '\0')
        length++;
    while (length > 0) {
        if (hex[length - 1] >= '0' && hex[length - 1] <= '9')
            answer = answer + (hex[length - 1] - 48) * osnova;
        if (hex[length - 1] >= 'A' && hex[length - 1] <= 'F')
            answer = answer + (hex[length - 1] - 55) * osnova;
        if (hex[length - 1] >= 'a' && hex[length - 1] <= 'f')
            answer = answer +(hex[length -1] -87) * osnova;
        osnova = osnova * 16;
        length--;
    }
    return answer;
}
