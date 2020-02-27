#include "uls.h"

void mx_karetka_files(char* str) {
	if (isatty(1)) {
		for (int i = 0; i < mx_strlen(str); i++) {
			if (str[i] == '\b'
			|| str[i] == '\r'
			|| str[i] == '\t'
			|| str[i] == '\v') {
				str[i] = '?';
			}
		}
	}
}
