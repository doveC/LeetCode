#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
	int prev, curr;
	int max = 0;

	if (pricesSize <= 1) {
		return 0;
	}

	for (int i = 0; i < pricesSize - 1; i++) {
		prev = prices[i];
		curr = prices[i + 1];

		if (curr > prev) {
			max += curr - prev;
		}
	}

	return max;
}

int main() {
	int arr[6] = { 7, 1, 5, 3, 6, 4 };

	printf("%d\n", maxProfit(arr, 6));

	system("pause");
	return 0;
}