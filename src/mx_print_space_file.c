#include "uls.h"

void mx_print_space_file(int max_elem, char* str) {
    for(int j = 0; j < max_elem - mx_strlen(str); j++) {
        mx_printchar(' ');
    }
}
