#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* dummyHead =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->val = 0;
	dummyHead->next = head;
	struct ListNode* ptrFirst = dummyHead;
	struct ListNode* ptrSecond = dummyHead;
	
	for (int i = 0; i < n + 1; i++) {
		ptrFirst = ptrFirst->next;
	}

	while (ptrFirst) {
		ptrFirst = ptrFirst->next;
		ptrSecond = ptrSecond->next;
	}

	ptrSecond->next = ptrSecond->next->next;

	return dummyHead->next;
}

int main() {


	system("pause");
	return 0;
}