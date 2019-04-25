#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int* arr, int left, int right) {
	int l = left, r = left + 1;
	int pivot = arr[left];

	while (r <= right) {
		if (arr[r] < pivot) {
			swap(&arr[r], &arr[l + 1]);
			l++;
		}
		r++;
	}

	swap(&arr[l], &arr[left]);
	return l;
}

void __quick_sort(int* arr, int left, int right) {
	if (left < right) {
		int pivotIndex = partition(arr, left, right);
		__quick_sort(arr, left, pivotIndex);
		__quick_sort(arr, pivotIndex + 1, right);
	}
}

void quick_sort(int* arr, int size) {
	__quick_sort(arr, 0, size - 1);
}

int threeSumClosest(int* nums, int numsSize, int target) {
	int left, right;
	int diff;
	int res;

	// 先对数组排序
	quick_sort(nums, numsSize);

	diff = INT_MAX;

	for (int i = 0; i < numsSize - 2; i++) {
		left = i + 1;
		right = numsSize - 1;

		while (left < right) {
			int newDiff = target - nums[left] - nums[right] - nums[i];

			// 如果这次的结果差值更小
			if (abs(newDiff) < abs(diff)) {  
				res = nums[i] + nums[left] + nums[right];
				diff = newDiff;
			}

			// 移动left和right
			if (newDiff < 0) {
				right--;
			}
			else if(newDiff > 0) {
				left++;
			}
			else {
				break;
			}
		}
	}

	return res;
}

int main() {
	int arr[] = { -1, 2, 1, -4 };
	printf("%d\n", threeSumClosest(arr, sizeof(arr) / sizeof(arr[0]), 1));

	system("pause");
	return 0;
}