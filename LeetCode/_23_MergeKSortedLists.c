#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
// #define DEBUG
// #define USE
#ifdef USE

struct ListNode {
	int val;
	struct ListNode* next;
};

// �ҵ���������СԪ�ص��±�
int findMinIndex(int* arr, int size) {
	int index = 0;
	int min = arr[index];

#ifdef DEBUG
	printf("arr[0] = %d\n", arr[0]);
	system("pause");
#endif // DEBUG

	for (int i = 1; i <= size - 1; i++) {

#ifdef DEBUG
		printf("arr[%d] = %d\n", i, arr[i]);
		system("pause");
#endif // DEBUG
		
		if (arr[i] < min) {
			index = i;
			min = arr[index];
		}
	}

	return index;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

	int count = 0;  // ��¼�Ѿ������������ĸ����������������

	// �������Ƚ�����
	int* arr = (int *)malloc(sizeof(int) * listsSize);
	for (int i = 0; i < listsSize; i++) {
		if (lists[i] == NULL) {
			arr[i] = INT_MAX;
			count++;
		}			
		else {
			arr[i] = lists[i]->val;
		}
	}

	if (count == listsSize)  // �����������ȫ���ǿ���������NULL
		return NULL;
		

	// Ϊÿ��������ָ��
	struct ListNode** ptrList = lists;

	// ����Ҫ���صĽ��ָ��
	struct ListNode* res = 
		(struct ListNode *)malloc(sizeof(struct ListNode));
	res->next = NULL;
	struct ListNode* ptr = res;

	// ��ʼ�Ƚ�
	int index;
	while (1) {
		// �ҳ�����������С����������
		index = findMinIndex(arr, listsSize);

#ifdef DEBUG
		printf("index = %d\n", index);
		system("pause");
#endif // DEBUG

		// ������ڵ����res��
		ptr->next = ptrList[index];
		ptr = ptr->next;

		// ����С�����ڵ������ָ������ƣ�Ҫ�������ǲ��ǵ�ǰ��������һ���ڵ�
		// ��������һ���ڵ㣬��Ѷ�Ӧ������������Ԫ����ΪINT_MAX
		if (ptrList[index]->next == NULL) {
			arr[index] = INT_MAX;
			count++;

#ifdef DEBUG
			printf("count %d\n", count);
#endif // DEBUG

		}
		else {
			ptrList[index] = ptrList[index]->next;
			arr[index] = ptrList[index]->val;
		}

		if (count == listsSize) {  // ���ȫ�������������ˣ��˳�ѭ��
			ptr->next = NULL;
			break;
		}  
			
#ifdef DEBUG
		printf("count = %d\n", count);
		system("pause");
#endif // DEBUG
	
	}

	return res->next;
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
	int arr1[5] = { 1, 4, 7, 8, 9 };
	int arr2[3] = { 2, 4, 6 };
	int arr3[7] = { 11, 12, 13, 14, 15, 16, 17 };

	struct ListNode* ptr1 = createLL(arr1, sizeof(arr1) / sizeof(int));
	struct ListNode* ptr2 = createLL(arr2, sizeof(arr2) / sizeof(int));
	struct ListNode* ptr3 = createLL(arr3, sizeof(arr3) / sizeof(int));
	struct ListNode** pptr =
		(struct ListNode **)malloc(sizeof(struct ListNode *) * 3);
	pptr[0] = ptr1;
	pptr[1] = ptr2;
	pptr[2] = ptr3;

	struct ListNode* res = mergeKLists(pptr, 3);
	printLL(res);

	system("pause");
	return 0;
}
#endif
