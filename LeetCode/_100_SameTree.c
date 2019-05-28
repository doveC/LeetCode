#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef int bool;
#define true 1
#define false 0

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL) {
		return true;
	}
	if (p == NULL || q == NULL) {
		return false;
	}

	if (p->val == q->val) {
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	else {
		return false;
}

int main() {


	system("pause");
	return 0;
}
#endif