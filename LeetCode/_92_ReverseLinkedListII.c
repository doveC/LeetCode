#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* reverseBetween1(struct ListNode* head, int m, int n) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode *start = NULL, *end = NULL;  // start指向m前一个元素 end指向n后一个元素，方便拼接
	struct ListNode *dummyHead = 
		(struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->next = head;
	dummyHead->val = 0;
	struct ListNode *ptr = dummyHead;
	struct ListNode *res = NULL, *curr = NULL;  // 用于翻转元素
	int count = 0;

	while (count + 1 != m) {  // ptr先找到m前一个元素
		ptr = ptr->next;
		count++;
	}

	start = ptr;
	ptr = ptr->next;  
	count++;

	while (count <= n) {  // 翻转m到n之间的元素
		curr = ptr;
		ptr = ptr->next;
		count++;

		curr->next = res;
		res = curr;
	}

	end = ptr;
	start->next->next = end;
	start->next = res;

	return dummyHead->next;
}

// 递归翻转单链表
struct ListNode* reverse(struct ListNode* head) {
	if (head->next == NULL) return head;
	struct ListNode* last = reverse(head->next);
	head->next->next = head;  // 此时head->next是翻转区域的最后一个元素
	head->next = NULL;
	return last;
}

struct ListNode* successor = NULL;
struct ListNode* reverseN(struct ListNode* head, int n) {
	if (n == 1) {
		successor = head->next;  // successor记录原链表第n个节点的next
		return head;
	}
	struct ListNode* last = reverseN(head->next, n - 1);
	head->next->next = head;
	head->next = successor;
	return last;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
	if (m <= 1) {
		return reverseN(head, n - m + 1);
	}
	head->next = reverseBetween(head->next, m - 1, n - 1);
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
	int arr[] = { 1, 4, 3, 2, 5, 2 };
	struct ListNode* head = CreatLL(arr, 6);
	printLL(head);
	head = reverseBetween1(head, 2, 4);
	printLL(head);

	system("pause");
	return 0;
}