#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#if 0

typedef int bool;
#define true 1
#define false 0

bool isPalindrome(int x) {
	if (x < 0 || (x != 0 && x % 10 == 0)) {
		return false;
	}

	int tmp = 0;
	while(x > tmp) {
		tmp = tmp * 10 + x % 10;
		x /= 10;
	}

	if (x == tmp || x == tmp / 10) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	if (isPalindrome(12321) == true) {
		printf("Bingo\n");
	}

	system("pause");
	return 0;
}
#endif
