#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define USE
#ifdef USE

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* swapPairs(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {  // 空链表或者只有一个节点就直接返回
		return head;
	}

	struct ListNode* dummyHead =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->val = 0;
	dummyHead->next = head;

	struct ListNode *prev, *curr;
	prev = dummyHead;
	curr = head;

	while (curr && curr->next) {
		prev->next = curr->next;
		prev = prev->next;
		curr->next = prev->next;
		prev->next = curr;
		prev = curr;
		curr = curr->next;
	}

	return dummyHead->next;
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
	int arr[] = { 1, 3, 5, 7, 9 };
	struct ListNode* head = CreatLL(arr, 5);
	printLL(head);
	head = swapPairs(head);
	printLL(head);

	system("pause");
	return 0;
}
#endif