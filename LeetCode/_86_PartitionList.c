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

struct ListNode* partition(struct ListNode* head, int x) {
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode* dummyHead =
		(struct ListNode *)malloc(sizeof(struct ListNode));
	dummyHead->next = head;
	struct ListNode* prev = dummyHead;  // prevָ�����һ����xС��Ԫ��
	struct ListNode* curr = dummyHead;  // currָ����һ��Ҫ�жϵ�Ԫ�ص�ǰһ��Ԫ��
	struct ListNode* tmp;

	while (curr->next != NULL) {
		if (curr->next->val < x) {  // ��һ��Ҫ�жϵ�Ԫ�ر�xС
			tmp = curr->next;
			curr->next = curr->next->next;
			tmp->next = prev->next;
			prev->next = tmp;
			prev = prev->next;
			if (prev == curr->next)  // ������ʱȫ���Ǳ�xС��Ԫ�������������
				curr = prev;
		}
		else {
			curr = curr->next;
		}
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
	int arr[] = { 1, 4, 3, 2, 5, 2 };
	struct ListNode* head = CreatLL(arr, 6);
	printLL(head);
	head = partition(head, 3);
	printLL(head);

	system("pause");
	return 0;
}
#endif