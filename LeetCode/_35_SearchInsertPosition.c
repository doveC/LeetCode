#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

int searchInsert(int* nums, int numsSize, int target) {
	for (int i = 0; i < numsSize; i++)
		if (nums[i] >= target) 
			return i;
	return numsSize;
}

int searchInsert1(int* nums, int numsSize, int target) {
	// 二分查找
	int left = 0, right = numsSize - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] < target) {
			left = mid + 1;
		}
		else if (nums[mid] > target) {
			right = mid - 1;
		}
		else {
			return mid;
		}
	}

	// 此时left和right交错，left = right + 1，可知交错的上一步mid必选在left或者right
	// 如果选在left还交错了说明target在(arr[left - 1], arr[left])区间
	// 如果选在right还交错了说明target在(arr[right], arr[right - 1])区间
	// 则可以想到要插入的位置必是交错后的left所在位置
	return left;
}

int main() {


	system("pause");
	return 0;
}
#endif