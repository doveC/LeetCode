#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

int lengthOfLastWord(char * s) {
	int len = -1;
	char* cur = s;

	// ������ͷ�Ŀո�
	while (*cur == ' ') {
		cur++;
	}
	if (*cur == '\0') {
		return 0;
	}
	
	while (1) {
		len = 0;
		while (*cur != ' ' && *cur != '\0') {
			cur++;
			len++;
		}

		// �����ʼ�ո�
		while (*cur == ' ') {
			cur++;
		}
		if (*cur == '\0') {
			return len;
		}
	}
}

int main() {
	char* str = "Hello  World! ";
	printf("%d\n", lengthOfLastWord(str));

	system("pause");
	return 0;
}
#endif