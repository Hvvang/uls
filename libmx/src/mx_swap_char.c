#include "libmx.h"

void mx_swap_char(char *s1, char *s2) {
	char buf = *s1;

	if (!s1 || !s2)
		return;
	*s1 = *s2;
	*s2 = buf;
}
