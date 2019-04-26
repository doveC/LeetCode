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
	// ���ֲ���
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

	// ��ʱleft��right����left = right + 1����֪�������һ��mid��ѡ��left����right
	// ���ѡ��left��������˵��target��(arr[left - 1], arr[left])����
	// ���ѡ��right��������˵��target��(arr[right], arr[right - 1])����
	// ������뵽Ҫ�����λ�ñ��ǽ�����left����λ��
	return left;
}

int main() {


	system("pause");
	return 0;
}
#endif