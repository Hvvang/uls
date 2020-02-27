#include "uls.h"

static void print_byte(int ost) {
	if (ost > 999)
		mx_printstr("1.0K");
	else {
		char *buf = mx_itoa(ost);

		if (mx_strlen(buf) + 1 < 4)
			for (int i = mx_strlen(buf) + 1; i < 4; i++)
				mx_printchar(' ');
		mx_printint(ost);
		mx_printchar('B');
		mx_strdel(&buf);
	}
}

static void once(int kb, int delim) {
	if (mx_ostatok(kb, delim) == 1000)
		mx_printint(delim + 1);
	else
		mx_printint(delim);
	mx_printchar('.');
	if (mx_ostatok(kb, delim) > 949)
		mx_printchar('0');
	else
		mx_printint(mx_ostatok(kb, delim));
	mx_printstr("M");
}

static void hund(int kb, int delim) {
	if (mx_ostatok(kb, delim) == 1000)
		mx_printint(delim + 1);
	else
		mx_printint(delim);
	mx_printchar('M');
}

static void print_mb(int summ) {
	int delim = summ / 1024;
	int kb = summ - (delim * 1024);

	if (delim > 99)
		hund(kb, delim);
	else if (delim > 9) {
		mx_printchar(' ');
		if (mx_ostatok(kb, delim) == 1000)
			mx_printint(delim + 1);
		else
			mx_printint(delim);
		mx_printchar('M');
	}
	else
		once(kb, delim);
}

void mx_size_h(char *file_size) {
	int summ = mx_atoi(file_size) / 1024;
	int ost = mx_atoi(file_size) % 1024;
	int file_s = mx_atoi(file_size);

	mx_printchar(' ');
	if (mx_atoi(file_size) > 1048576)
		print_mb(summ);
	else if (mx_atoi(file_size) > 1024)
		mx_print_kb(summ, ost);
	else
		print_byte(file_s);
}
