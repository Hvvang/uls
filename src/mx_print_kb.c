#include "uls.h"

static void hund(int summ, int ost) {
	if (summ > 1000 && summ < 1025) {
		mx_printint(1);
		mx_printchar('.');
		mx_printchar('0');
		mx_printchar('M');
		return;
	}
	if (mx_ostatok(ost, summ) == 1000)
		mx_printint(summ + 1);
	else
		mx_printint(summ);
	mx_printchar('K');
}

static void dec(int summ, int ost) {
	if (mx_ostatok(ost, summ) == 1000){
		if (summ + 1 == 100)
			mx_printint(summ + 1);
		else {
			mx_printchar(' ');
			mx_printint(summ + 1);
		}
	}
	else {
		mx_printchar(' ');
		mx_printint(summ);
	}
	mx_printchar('K');
}

static void digit(int summ, int ost) {
	if (mx_ostatok(ost, summ) == 1000)
		if (mx_ostatok(ost, summ) > 949 && summ + 1 == 10) {
			mx_printchar(' ');
			mx_printint(summ + 1);
			mx_printchar('K');
			return;
		}
		else			
			mx_printint(summ + 1);
	else
		mx_printint(summ);
	mx_printchar('.');
	if (mx_ostatok(ost, summ) > 949)
		mx_printchar('0');
	else
		mx_printint(mx_ostatok(ost, summ));
	mx_printstr("K");
}

void mx_print_kb(int summ, int ost) {
	if (summ > 99)
		hund(summ, ost);
	else if (summ > 9)
		dec(summ, ost);
	else
		digit(summ, ost);
}

