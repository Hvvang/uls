#include "uls.h"

static void add_tabs(int max_size, int size) {
    if ((max_size - size) % 8 == 0)
        mx_printstr("\t");
    while ((max_size - size) > 8) {
        mx_printstr("\t");
        size += 8 - (size % 8);
    }
}

static void true_mul(int max_size, int max_d_len, char **data, int arr_size) {
    int cols = max_size / (max_d_len);
    int rows = (arr_size % cols) ? arr_size / cols + 1 : arr_size / cols;

    for (int i = 0; i < rows; i++) {
        for (int k = i; k < arr_size; k += rows) {
            mx_karetka_files(data[i]);
            mx_printstr(data[k]);
            if (!(--cols) || k + rows >= arr_size) {
                mx_printstr("\n");
                cols = max_size / (max_d_len);
                break;
            }
            if (mx_strlen(data[k]) % 8) {
                mx_printstr("\t");
            }
            add_tabs(max_d_len, mx_strlen(data[k]));
        }
    }
}

static void multi_clm_print(char **data, int max_size, int max_d_len) {
    int arr_size = mx_arr_size(data);

    if (max_d_len > max_size) {
        for (int i = 0; i < arr_size; i++) {
            mx_karetka_files(data[i]);
            mx_printstr(data[i]);
            mx_printchar('\n');
        }
    }
    else {
        true_mul(max_size, max_d_len, data, arr_size);
    }
}

static int max_d_namlen(char **data) {
    int max_len = 0;

    while (*data) {
        max_len = (mx_strlen(*data) > max_len) ? mx_strlen(*data) : max_len;
        (data)++;
    }
    if (max_len % 8)
        max_len += 8 - (max_len % 8);
    else
        max_len += 8;
    return max_len;
}

void mx_print_ls_multy_colomn(char **data,  t_args *args, char *dir) {
    int max_size = mx_get_window_size(args);
    int max_d_len = max_d_namlen(data);

    dir = NULL;
    multi_clm_print(data, max_size, max_d_len);
}
