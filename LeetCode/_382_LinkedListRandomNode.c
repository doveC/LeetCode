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
	// 首先将结果初始化成第一个元素
	int res = obj->head->val;

	// 依次向后
	struct ListNode* cur = obj->head->next;
	int count = 2;
	int tmp;
	
	while (cur != NULL) {
		tmp = rand() % count;  // 0 ~ count-1
		if (tmp == 0) {  // 这里把0换成任意一个0 ~ count-1的数都行，选到的概率都是一样的
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