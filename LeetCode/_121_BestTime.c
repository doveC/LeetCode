#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
	int min = INT_MIN;
	int maxProfit = 0;

	for (int i = 0; i < pricesSize; i++) {
		if (prices[i] < min) {
			min = prices[i];
		}
		else if (prices[i] - min > maxProfit) {
			maxProfit = prices[i] - min;
		}
	}

	return maxProfit;
}