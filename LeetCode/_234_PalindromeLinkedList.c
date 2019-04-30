#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

typedef int bool;
#define true 1
#define false 0

struct ListNode* reverseLL(struct ListNode* head) {
	struct ListNode* res = NULL;

	while (head) {
		struct ListNode* tmp = head->next;
		head->next = res;
		res = head;
		head = tmp;
	}

	return res;
}

bool isPalindrome1(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}

	struct ListNode* ptrFast;
	struct ListNode* ptrSlow;
	ptrFast = ptrSlow = head;

	while (ptrFast->next && ptrFast->next->next) {
		ptrFast = ptrFast->next->next;
		ptrSlow = ptrSlow->next;
	}

	// 此时ptrSlow在偏左中间节点
	// 1 2 1
	// 1 2 2 1
	struct ListNode* leftPart = head;
	struct ListNode* rightPart = reverseLL(ptrSlow->next);
	ptrSlow->next = NULL;

	// 比较两个链表
	while (leftPart && rightPart) {
		if (leftPart->val != rightPart->val) {
			return false;
		}
		leftPart = leftPart->next;
		rightPart = rightPart->next;
	}
	
	// 此时要么leftPart是NULL，要么leftPart和rightPart都是NULL，即都是回文数
	return true;
}

struct ListNode* temp;
bool check(struct ListNode* head) {
	if (head == NULL) {
		return true;
	}
	
	bool isPal = check(head->next) & (temp->val == head->val);
	temp = temp->next;

	return isPal;
}

bool isPalindrome(struct ListNode* head) {
	temp = head;
	return check(head);
}

struct ListNode* createLL(int* arr, int size) {
	struct ListNode* res =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	res->next = NULL;
	struct ListNode* ptr = res;
	struct ListNode* tmp;

	for (int i = 0; i < size; i++) {
		tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
		tmp->val = arr[i];
		tmp->next = NULL;
		ptr->next = tmp;
		ptr = ptr->next;
	}

	return res->next;

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
	int arr[] = { 1, 2 };
	struct ListNode* l = createLL(arr, 2);
	printf("%d\n", isPalindrome(l));

	system("pause");
	return 0;
}