#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}
};

Node* getNewNode(int val) {
	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	newNode->random = NULL;

	return newNode;
}

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) {
			return NULL;
		}

		// 1. 遍历链表，往每个节点后面插入一个复制节点
		Node* curr = head;
		Node* newNode = NULL;
		
		while (curr) {
			newNode = getNewNode(curr->val);
			newNode->next = curr->next;
			curr->next = newNode;
			curr = newNode->next;
		}

		// 2. 复制random指针
		curr = head;
		while (curr) {
			curr->next->random = curr->random ? curr->random->next : NULL;
			curr = curr->next->next;
		}

		// 3. 分离出新链表
		Node* res = head->next;
		Node* p1 = head;
		Node* p2 = head->next;

		while (p2) {
			p1->next = p2->next;
			p1 = p2;
			p2 = p2->next;
		}

		return res;
	}
};

int main() {
	Node* n1 = getNewNode(1);
	Node* n2 = getNewNode(2);
	Node* n3 = getNewNode(3);
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	n1->random = n3;
	n2->random = n1;
	n3->random = NULL;

	Solution s;
	Node* res = s.copyRandomList(n1);
	printf("\n");

	system("pause");
	return 0;
}

#endif