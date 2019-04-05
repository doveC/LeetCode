#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

struct ListNode {
	int val;
	struct ListNode* next;
};

// 递归方法
struct ListNode* reverseList_re(struct ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		return head;
	}
	
	struct ListNode* newHead = reverseList_re(head->next);

	struct ListNode* ptr = newHead;
	while (ptr->next) {
		ptr = ptr->next;
	}
	ptr->next = head;
	head->next = NULL;

	return newHead;
}

// 非递归方法，头删头插
struct ListNode* reverseList_non1(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode* cur = head;
	struct ListNode* ptr;
	struct ListNode* res = NULL;

	while (cur) {
		ptr = cur;
		cur = cur->next;

		ptr->next = res;
		res = ptr;
	}

	return res;
}

// 非递归方法，指针反转
struct ListNode* reverseList_non2(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode *p1, *p2, *p3;
	p1 = NULL;
	p2 = head;

	while (p2 != NULL) {
		p3 = p2->next;
		p2->next = p1;

		// 指针后移
		p1 = p2;
		p2 = p3;
	}

	return p1;
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
	int arr[] = { 1, 4, 3, 2, 5, 2 };
	struct ListNode* head = CreatLL(arr, 6);
	printLL(head);
	head = reverseList(head);
	printLL(head);

	system("pause");
	return 0;
}
#endif
