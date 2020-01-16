#include "libmx.h"

void mx_str_reverse(char *s) {
	int i;
	int j;

	if (!s)
		return;
	for (i = 0; i < mx_strlen(s) - 1; i++) {
		for (j = 0; j < mx_strlen(s) - 1 - i; j++)
			mx_swap_char(&s[j], &s[j+1]);
	}
}
