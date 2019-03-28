#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HTCAPACITY 50000
// #define USE
#ifdef USE

// Solution 1
int* twoSum_1(int* nums, int numsSize, int target) {
	int* arr = NULL;
	arr = (int *)malloc(8);
	int i = 0, j = 0;

	for (; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (*(nums + i) + *(nums + j) == target) {
				*arr = i;
				*(arr + 1) = j;
				return arr;
			}
		}
	}
	return NULL;
}
// end of Solution1


// Solution 2
int hash(int key) {
	int ret = key % HTCAPACITY;
	return (ret < 0) ? (ret + HTCAPACITY) : (ret);
}

void htInsert(int *keys, int *values, int key, int value) {
	int index = hash(key);

	while (values[index] >= 0)
		index = (index + 1) % HTCAPACITY;
	keys[index] = key;
	values[index] = value;
}

int htSearch(int *keys, int *values, int key) {
	int index = hash(key);

	while (values[index] >= 0) {
		if (keys[index] == key)
			return values[index];
		index = (index + 1) % HTCAPACITY;
	}
	return -1;
}

int* twoSum_2(int* nums, int numsSize, int target) {
	int keys[HTCAPACITY] = { 0 };
	int values[HTCAPACITY];
	memset(values, -1, sizeof(int)*HTCAPACITY);
	int *indices = (int *)malloc(sizeof(int) * 2);
	int value = -1, i = 0, complement;

	for (i = 0; i < numsSize; i++) {
		complement = target - nums[i];
		if ((value = htSearch(keys, values, complement)) != -1) {
			indices[0] = value;
			indices[1] = i;
			return indices;
		}
		else {
			htInsert(keys, values, nums[i], i);
		}
	}
	return NULL;
}
// end of Solution2

int main(int argc, char const *argv[])
{
	int nums[] = { 0, 1, 2, 0 };
	int *res = twoSum_1(nums, 4, 0);
	printf("%d %d\n", res[0], res[1]);

	system("pause");
	return 0;
}
#endif
