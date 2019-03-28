#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
//	struct ListNode* res = (struct ListNode *)malloc(sizeof(struct ListNode));
//	res->next = NULL;
//	struct ListNode* ptr = res;
//
//	while (l1 && l2) {
//		if (l1->val < l2->val) {
//			ptr->next = l1;
//			ptr = ptr->next;
//			l1 = l1->next;
//		}
//		else {
//			ptr->next = l2;
//			ptr = ptr->next;
//			l2 = l2->next;
//		}
//	}
//	ptr->next = l1 ? l1 : l2;
//
//	return res->next;
//}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	
	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

//int main() {
//
//
//	system("pause");
//	return 0;
//}