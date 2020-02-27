#include "uls.h"

static void add_tabs(int max_size, int size) {
    int count = max_size - size;

    while (count != 0) {
        mx_printstr(" ");
        count--;
    }
}

static void multi_clm_print(t_args *args, char **data, int max_size,
                            int max_d_len, char *dir) {
    int arr_size = mx_arr_size(data);
    int cols = max_size / (max_d_len);
    int rows = (arr_size % cols) ? arr_size / cols + 1 : arr_size / cols;

    for (int i = 0; i < rows; i++) {
        for (int k = i; k < arr_size; k += rows) {
            mx_colored_name(args, data[k], dir);
            if (!(--cols) || k + rows >= arr_size) {
                mx_printstr("\n");
                cols = max_size / (max_d_len);
                break;
            }
            add_tabs(max_d_len, mx_strlen(data[k]));
            if (data[k + 1])
                mx_printstr(" ");
        }
    }
}

static int max_d_namlen(char **data) {
    int max_len = 0;

    while (*data) {
        max_len = (mx_strlen(*data) > max_len) ? mx_strlen(*data) : max_len;
        (data)++;
    }
    return max_len;
}

void mx_print_multy_colomn_g(char **data,  t_args *args, char *dir) {
    int max_size = mx_get_window_size(args);
    int max_d_len = max_d_namlen(data);

    multi_clm_print(args, data, max_size, max_d_len, dir);
}
