#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Á½²ãÑ­»·
int maxArea(int* height, int heightSize) {
	int maxArea = 0;
	int newArea = 0;
	int i, j;

	for (i = 0; i < heightSize; i++) {
		for (j = i + 1; j < heightSize; j++) {
			newArea = (j - i) * MIN(height[i], height[j]);
			maxArea = MAX(newArea, maxArea);
		}
	}

	return maxArea;
}

int maxArea_ON(int* height, int heightSize) {
	int left = 0, right = heightSize - 1;
	int maxArea = 0, newArea = 0;

	while (left != right) {
		newArea = (right - left) * MIN(height[left], height[right]);
		maxArea = MAX(newArea, maxArea);
		(height[left] < height[right]) ? ++left : --right;
	}

	return maxArea;
}

int main() {
	int arr[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	printf("%d\n", maxArea_ON(arr, 9));

	system("pause");
	return 0;
}
#endif