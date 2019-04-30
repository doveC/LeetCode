#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	for (int index = digitsSize - 1; index >= 0; index--) {
		if (digits[index] < 9) {
			digits[index]++;
			*returnSize = digitsSize;
			return digits;
		}
		
		digits[index] = 0;
	}

	// 如果走到这里，则需要再新malloc一个数组
	int* res = (int *)malloc(sizeof(int) * (digitsSize + 1));

	res[0] = 1;
	for (int i = 0; i < digitsSize; i++) {
		res[i + 1] = digits[i];
	}
	*returnSize = digitsSize + 1;
	return res;
}

int main() {
	int arr[] = { 1, 2, 3 };
	int returnSize = -1;
	plusOne(arr, 3, &returnSize);
	printf("returnSize = %d\n", returnSize);
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);

	system("pause");
	return 0;
}
#endif