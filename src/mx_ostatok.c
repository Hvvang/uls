#include "uls.h"

int mx_ostatok(int kb, int summ) {
	kb = (kb * 1000) / 1024;
	if (kb > 499 && summ > 9)
		return 1000;
	if (kb < 50)
		return 0;
	if (kb > 949 && summ < 10)
		return 1000;
	if (kb % 100 > 49 && kb / 100 != 9)
		return kb / 100 + 1;
	else if (kb / 100 == 9)
		return kb / 100;
	else
		return kb / 100;
	return kb / 100;
}
