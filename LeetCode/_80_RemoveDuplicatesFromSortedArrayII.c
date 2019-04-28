#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0) {
		return numsSize;
	}

	int i = 0, j = 1;

	// 设置一个sign变量记录找到的元素是否是重复的，重复的为1，不重复为0
	int sign = 0;

	while (i < numsSize && j < numsSize) {
		if (nums[i] != nums[j]) {
			if (sign == 1) {  // 如果i指向的元素是重复的，则把i后面的元素也填充为i的元素
				i++;
				nums[i] = nums[i - 1];
			}
			i++;
			nums[i] = nums[j];
			j++;
			sign = 0;
		}
		else {
			sign = 1;
			j++;
		}
	}
	if (sign == 1) {  // 如果此时sign等于1说明数组最后几个元素是重复的，要在这里单独处理一下
		i++;
		nums[i] = nums[i - 1];
	}

	return i + 1;
}

int removeDuplicates1(int* nums, int numsSize) {
	if (numsSize == 0) {
		return numsSize;
	}

	int i = 0;
	for (int n = 0; n < numsSize; n++) {
		if (i < 2 || nums[n] > nums[i - 2]) {
			nums[i++] = nums[n];
		}
	}

	return i;
}

int removeDuplicatesK(int* nums, int numsSize, int k) {
	if (numsSize == 0) {
		return numsSize;
	}

	int i = 0;
	for (int n = 0; n < numsSize; n++) {
		if (i < k || nums[n] > nums[i - k]) {
			nums[i++] = nums[n];
		}
	}

	return i;
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