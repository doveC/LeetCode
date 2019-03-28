#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define USE
#ifdef USE

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int carry = 0, sum = 0;
	int val1 = 0, val2 = 0;
	struct ListNode* ptr1 = l1;
	struct ListNode* ptr2 = l2;
	struct ListNode* dummyRes = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* curr = dummyRes;
	dummyRes->val = 0;

	while (ptr1 || ptr2) {
		val1 = (ptr1) ? (ptr1->val) : (0);
		val2 = (ptr2) ? (ptr2->val) : (0);
		sum = val1 + val2 + carry;
		carry = sum / 10;
		curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		curr->next->val = sum % 10;
		curr = curr->next;
		if (ptr1) ptr1 = ptr1->next;
		if (ptr2) ptr2 = ptr2->next;
	}
	if (carry) {
		curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		curr->next->val = carry;
		curr->next->next = NULL;
	}
	else {
		curr->next = NULL;
	}
	return dummyRes->next;
}

int main() {
	struct ListNode* l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode* l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode* tmp;

	l1->val = 2;
	l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->next->val = 4;
	l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->next->next->val = 3;
	l1->next->next->next = NULL;
	l2->val = 5;
	l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->next->val = 6;
	l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->next->next->val = 4;
	l2->next->next->next = NULL;
	tmp = addTwoNumbers(l1, l2);
	printf("%d %d %d\n", tmp->val, tmp->next->val, tmp->next->next->val);

	system("pause");
	return 0;
}
#endif