#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

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

int** threeSum(int* nums, int numsSize, int* returnSize) {
	if (numsSize < 3) {
		return NULL;
	}
	if (nums == NULL) {
		return NULL;
	}

	quick_sort(nums, numsSize);

	int** res = NULL;
	*returnSize = 0;

	for (int i = 0; i < numsSize; i++) {
		int target = -nums[i];
		int front = i + 1;
		int back = numsSize - 1;

		while (front < back) {
			int sum = nums[front] + nums[back];
			
			if (sum < target) {
				front++;
			}
			else if (sum > target) {
				back--;
			}
			else {  // 找到了
				(*returnSize)++;
				
				res = (int **)realloc(res, sizeof(int*) * (*returnSize));
				res[*returnSize - 1] = (int *)malloc(sizeof(int) * 3);
				res[*returnSize - 1][0] = nums[i];
				res[*returnSize - 1][1] = nums[front];
				res[*returnSize - 1][2] = nums[back];

				// 跳过和nums[front]重复的元素
				while (front < back && nums[front] == res[*returnSize - 1][1]) {
					front++;
				}

				// 跳过和nums[back]重复的元素
				while (front < back && nums[back] == res[*returnSize - 1][2]) {
					back--;
				}
			}
		}

		// 跳过和nums[i]重复的元素
		while (i + 1 < numsSize && nums[i + 1] == nums[i]) {
			i++;
		}
	}

	return res;
}

int main() {
	int nums[] = { -1, 0, 1, 2, -1, -4 };
	int returnSize = -1;
	int** res = threeSum(nums, sizeof(nums) / sizeof(int), &returnSize);

	system("pause");
	return 0;
}
#endif