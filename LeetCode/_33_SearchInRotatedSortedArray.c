#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

int search(int* nums, int numsSize, int target) {
	int left = 0;
	int right = numsSize - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (nums[mid] == target) {
			return mid;
		}

		if (nums[mid] >= nums[left]) {
			if (target >= nums[left] && target <= nums[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		else if (nums[mid] < nums[left]) {
			if (target >= nums[mid] && target <= nums[right]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
	}

	return -1;
}

int main() {
	int arr[] = { 4, 5, 6, 7, 0, 1, 2 };
	printf("%d\n", search(arr, sizeof(arr) / sizeof(arr[0]), 3));

	system("pause");
	return 0;
}
#endif