#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#if 0

typedef struct {
	int* nums;
	int numsSize;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
	Solution* sl = (Solution *)malloc(sizeof(Solution));
	sl->nums = nums;
	sl->numsSize = numsSize;
	srand((unsigned int)time(NULL));

	return sl;
}

int solutionPick(Solution* obj, int target) {
	int res, tmp;
	int count = 1;

	int index = 0;
	while (index < obj->numsSize) {
		if (obj->nums[index] == target) {
			tmp = rand() % count;
			if (tmp == 0) {
				res = index;
			}
			count++;
		}
		index++;
	}
	
	return res;
}

void solutionFree(Solution* obj) {
	free(obj);
}

int main() {
	int arr[] = { 1, 2, 2, 3, 3, 3 };
	Solution* sl = solutionCreate(arr, 6);
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	for (int i = 0; i < 1000; i++) {
		int res = solutionPick(sl, 3);
		if (res == 3) {
			count1++;
		}
		else if (res == 4) {
			count2++;
		}
		else if (res == 5) {
			count3++;
		}
	}

	printf("%d %d %d\n", count1, count2, count3);

	system("pause");
	return 0;
}
#endif