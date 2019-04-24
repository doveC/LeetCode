#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}

	struct ListNode* dummyHead =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->next = head;
	struct ListNode* curr = dummyHead;

	while (curr->next) {
		if (curr->next->val == val) {
			curr->next = curr->next->next;
		}
		else {
			curr = curr->next;
		}	
	}

	return dummyHead->next;
}

struct ListNode* removeElements1(struct ListNode* head, int val) {
	if (head == NULL) return NULL;
	head->next = removeElements1(head->next, val);
	return head->val == val ? head->next : head;
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
	int arr[] = { 1, 2, 6, 3, 4, 5, 6 };
	struct ListNode* head = CreatLL(arr, sizeof(arr) / sizeof(arr[0]));
	printLL(head);

	head = removeElements1(head, 6);
	printLL(head);

	system("pause");
	return 0;
}
#endif