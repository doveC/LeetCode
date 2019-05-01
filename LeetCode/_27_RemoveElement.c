#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

int removeElement(int* nums, int numsSize, int val) {
	int i = 0, j = 0;
	int count = 0;

	while (j < numsSize) {
		if (nums[j] != val) {
			nums[i++] = nums[j];
			count++;
		}
		j++;
	}

	return count;
}

int main() {


	system("pause");
	return 0;
}
#endif