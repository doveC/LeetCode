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

struct ListNode* rotateRight(struct ListNode* head, int k) {
	int count = 2;

	if (head == NULL || head->next == NULL) {  // 如果是空链表或者只有一个节点
		return head;
	}

	struct ListNode* prev = head;
	struct ListNode* curr = head->next;

	while (curr->next != NULL) {  // 找到最后两个元素
		curr = curr->next;
		prev = prev->next;
		count++;
	}

	k = k % count;

	for (int i = 0; i < k; i++) {
		prev->next = curr->next;
		curr->next = head;
		head = curr;

		while (curr->next != prev) {
			curr = curr->next;
		}
		prev = curr;
		curr = curr->next;
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
	int arr[] = { 0, 1, 2 };
	struct ListNode* head = CreatLL(arr, 3);
	printLL(head);
	head = rotateRight(head, 4);
	printLL(head);

	system("pause");
	return 0;
}
#endif