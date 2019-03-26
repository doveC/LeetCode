#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Solution 1
int lengthOfLongestSubstring_1(char* s) {
	char* tmp = s;  // tmp指针指向当前子序列的头字符
	char* ptr = tmp;
	int arr[128] = { 0 };
	int res = 0, dummyRes = 0;

	for (; *tmp != '\0'; tmp++, dummyRes = 0) {
		for (ptr = tmp; (arr[*ptr] != 1) && (*ptr != '\0'); ptr++) {
			arr[*ptr] = 1;
			dummyRes += 1;
		}
		if (dummyRes > res)
			res = dummyRes;
		for (int i = 0; i < 128; i++)
			arr[i] = 0;
	}

	return res;
}
// end solution 1


// Solution 2
int lengthOfLongestSubstring_2(char* s) {
	char* left = s;
	char* right = s;
	int res = 0, dummyRes = 0;
	int arr[128] = { 0 };

	while (*right) {
		if (!arr[*right]) {
			arr[*right++] = 1;
			dummyRes += 1;
			res = (res >= dummyRes) ? res : dummyRes;
		}
		else {
			arr[*left++] = 0;
			dummyRes -= 1;
		}
	}
	return res;
}
// end solution 2

//int main() {
//
//
//	system("pause");
//	return 0;
//}