#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#if 0

struct ListNode {
	int val;
	struct ListNode* next;
};

typedef struct {
	struct ListNode* head;
} Solution;

/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */

Solution* solutionCreate(struct ListNode* head) {
	Solution* sl = (Solution *)malloc(sizeof(Solution));
	sl->head = head;
	srand((unsigned int)time(NULL));

	return sl;
}

/** Returns a random node's value. */
int solutionGetRandom(Solution* obj) {
	// ���Ƚ������ʼ���ɵ�һ��Ԫ��
	int res = obj->head->val;

	// �������
	struct ListNode* cur = obj->head->next;
	int count = 2;
	int tmp;
	
	while (cur != NULL) {
		tmp = rand() % count;  // 0 ~ count-1
		if (tmp == 0) {  // �����0��������һ��0 ~ count-1�������У�ѡ���ĸ��ʶ���һ����
			res = cur->val;
		}
		cur = cur->next;
		count++;
	}

	return res;
}

void solutionFree(Solution* obj) {
	free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);

 * solutionFree(obj);
*/

int main() {


	system("pause");
	return 0;
}
#endif