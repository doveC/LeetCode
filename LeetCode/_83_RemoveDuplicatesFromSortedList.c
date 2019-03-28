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

struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode* ptr = head;

	while (ptr) {
		if (ptr->next != NULL && ptr->next->val == ptr->val)
			ptr->next = ptr->next->next;
		else
			ptr = ptr->next;
	}

	return head;
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
	int arr[] = { 1, 1 };
	struct ListNode* head = CreatLL(arr, 2);
	printLL(head);
	head = deleteDuplicates(head);
	printLL(head);

	system("pause");
	return 0;
}
#endif