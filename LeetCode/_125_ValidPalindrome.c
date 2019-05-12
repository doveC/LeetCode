#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#if 0

typedef int bool;
#define true 1
#define false 0

bool isPalindrome(char * s) {
	int left = 0;
	int right = strlen(s) - 1;
	char leftC, rightC;

	while (left < right) {
		while (!isalnum(s[left]) && left < right) left++;
		while (!isalnum(s[right]) && left < right) right--;

		if (left < right) {
			leftC = isupper(s[left]) ? tolower(s[left]) : s[left];
			rightC = isupper(s[right]) ? tolower(s[right]) : s[right];

			if (leftC == rightC) {
				left++;
				right--;
			}
			else {
				return false;
			}
		}
	}

	return true;
}

int main() {
	char* s = "race a car";
	printf("%d\n", isPalindrome(s));

	system("pause");
	return 0;
}
#endif