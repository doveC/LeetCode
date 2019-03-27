#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// 判断是否越界
// INT_MAX = 2147483647
// INT_MIN = -2147483648
// 当正数时，当srcNum = 214748364且addNum > 7，或者srcNum > 214748364时越界
// 当负数时，当srcNum = -214748364且addNum > 8，或者srcNum < -214748364时越界
int isOutOfRange(int sign, int srcNum, int addNum) {
	if (sign == 1) {
		if ((srcNum == 214748364) && (addNum > 7))
			return 1;
		else if (srcNum > 214748364)
			return 1;
	}
	else {
		if ((srcNum == -214748364) && (addNum > 8))
			return 1;
		else if (srcNum < -214748364)
			return 1;
	}
	return 0;
}

int myAtoi(char* str) {
	char* ptr = str;
	int sign = 1;  // 默认如果没有符号则是正数
	int srcNum = 0, addNum = 0;

	printf("Original str:%s\n", ptr);

	// 1. 去空格
	while (*ptr == ' ')
		ptr++;
	if (*ptr == '\0')
		return 0;
	printf("After step one:%s\n", ptr);

	// 2. 如果第一个非空格字符不是正负号或者数字
	if ((*ptr != '+') && (*ptr != '-')) {
		if ((*ptr > '9') || (*ptr < '0')) {
			return 0;
		}
	}
	printf("After step two:%s\n", ptr);

	// 3. 解析这个数字，先判断有没有正负号
	if ((*ptr == '+') || (*ptr == '-'))
		sign = (*ptr++ == '+') ? 1 : -1;

	// 4. 解析数字剩余的部分
	while ((*ptr >= '0') && (*ptr <= '9')) {
		addNum = *ptr - '0';
		printf("sign = %d srcNum = %d addNum = %d\n", sign, srcNum, addNum);
		if (isOutOfRange(sign, srcNum, addNum)) {
			return (sign == 1) ? INT_MAX : INT_MIN;
		}
		else {
			if (sign == 1) {
				srcNum = srcNum * 10 + addNum;
			}
			else {
				srcNum = srcNum * 10 - addNum;
			}
			ptr++;
		}
	}
	return  srcNum;
}

//int main() {
//	char str[] = "   -91283472332";
//	printf("%d\n", myAtoi(str));
//
//	system("pause");
//	return 0;
//}