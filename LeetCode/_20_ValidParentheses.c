#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

typedef int bool;
#define true 1
#define false 0

bool isValid(char * s) {
	char stack[5000] = { 0 };
	int size = 0;
	char* ptr = s;

	while (*ptr) {
		if (*ptr == '(' || *ptr == '{' || *ptr == '[') {
			stack[size++] = *ptr++;
		}
		else {
			if (size == 0) {  // 只有反括号没有正括号
				return false;
			}
			if ((stack[size - 1] == '(' && *ptr == ')') ||
				(stack[size - 1] == '[' && *ptr == ']') ||
				(stack[size - 1] == '{' && *ptr == '}')) {  // 匹配上了
				size--;
				ptr++;
			}
			else {  // 没匹配上
				return false;
			}
		}
	}

	return size == 0 ? true : false;
}

int main() {
	char* str = "()";
	printf("%d\n", isValid(str));

	system("pause");
	return 0;
}
#endif