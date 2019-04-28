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

	// ����һ��sign������¼�ҵ���Ԫ���Ƿ����ظ��ģ��ظ���Ϊ1�����ظ�Ϊ0
	int sign = 0;

	while (i < numsSize && j < numsSize) {
		if (nums[i] != nums[j]) {
			if (sign == 1) {  // ���iָ���Ԫ�����ظ��ģ����i�����Ԫ��Ҳ���Ϊi��Ԫ��
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
	if (sign == 1) {  // �����ʱsign����1˵��������󼸸�Ԫ�����ظ��ģ�Ҫ�����ﵥ������һ��
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