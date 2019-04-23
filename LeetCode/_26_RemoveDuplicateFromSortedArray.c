#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize < 2) {
		return numsSize;
	}

	int i = 0, j = 1;
	while (j < numsSize) {
		if (nums[i] != nums[j]) {
			i++;
			nums[i] = nums[j];
		}
		j++;
	}

	return i + 1;
}

int main() {
	int arr[] = { 1, 1, 2 };
	int res = removeDuplicates(arr, sizeof(arr) / sizeof(arr[0]));
	printf("res = %d\n", res);
	printf("\n");

	system("pause");
	return 0;
}
#endif