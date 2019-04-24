#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#if 0

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}

	// 计算两个链表长度的差值
	struct ListNode* ptrA = headA;
	struct ListNode* ptrB = headB;
	int lenA = 0;
	int lenB = 0;

	while (ptrA) {
		lenA++;
		ptrA = ptrA->next;
	}
	while (ptrB) {
		lenB++;
		ptrB = ptrB->next;
	}
	ptrA = headA;
	ptrB = headB;

	// 让较长的链表先向后移动差值步
	for (int i = 0; i < abs(lenA - lenB); i++) {
		if ((lenA - lenB) < 0) {
			ptrB = ptrB->next;
		}
		else {
			ptrA = ptrA->next;
		}
	}

	while (1) {
		if (ptrA == ptrB) {
			return ptrA;
		}
		else if (ptrA == NULL || ptrB == NULL) {
			return NULL;
		}
		else {
			ptrA = ptrA->next;
			ptrB = ptrB->next;
		}
	}
}

struct ListNode* CreatLL(int* arr, int size) {
	struct ListNode* dummyHead =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->val = 0;
	dummyHead->next = NULL;
	struct ListNode* ptr = dummyHead;
	struct ListNode* tmp;

	for (int i = 0; i < size; i++) {
		tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->next = NULL;
		tmp->val = arr[i];
		ptr->next = tmp;
		ptr = ptr->next;
	}

	return dummyHead->next;
}

void printLL(struct ListNode* head) {
	struct ListNode* ptr = head;
	while (ptr) {
		printf("%d -> ", ptr->val);
		ptr = ptr->next;
	}
	putchar('\n');
}

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	struct ListNode* headA = CreatLL(arr, sizeof(arr) / sizeof(arr[0]));
	struct ListNode* headB =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	headB->val = 0;
	headB->next = headA;

	system("pause");
	return 0;
}
#endif