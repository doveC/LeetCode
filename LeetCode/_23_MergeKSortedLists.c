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

// 找到数组中最小元素的下标
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

	int count = 0;  // 记录已经遍历完的数组的个数，方便结束程序

	// 建立待比较数组
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

	if (count == listsSize)  // 如果传进来的全部是空链表，返回NULL
		return NULL;
		

	// 为每个链表建立指针
	struct ListNode** ptrList = lists;

	// 建立要返回的结果指针
	struct ListNode* res = 
		(struct ListNode *)malloc(sizeof(struct ListNode));
	res->next = NULL;
	struct ListNode* ptr = res;

	// 开始比较
	int index;
	while (1) {
		// 找出所有数中最小的数的索引
		index = findMinIndex(arr, listsSize);

#ifdef DEBUG
		printf("index = %d\n", index);
		system("pause");
#endif // DEBUG

		// 将这个节点接在res上
		ptr->next = ptrList[index];
		ptr = ptr->next;

		// 将最小数所在的链表的指针向后移，要考虑这是不是当前链表的最后一个节点
		// 如果是最后一个节点，则把对应这个链表的数组元素置为INT_MAX
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

		if (count == listsSize) {  // 如果全部链表都遍历完了，退出循环
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
