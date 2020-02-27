#include "uls.h"

char *mx_strdup_del(char *str) {
	char *buf = NULL;
	int len = 0;

	if (str == NULL)
		return NULL;
	if (*str == '\0') {
		buf = (char*)malloc(sizeof(char) * 1);
		if (buf == NULL)
			return NULL;
	    buf[0] = '\0';
	}
	else {
		len = mx_strlen(str);
		buf = mx_strnew(len);
		mx_strcpy(buf, str);
	}
	mx_strdel(&str);
    return buf;
}
