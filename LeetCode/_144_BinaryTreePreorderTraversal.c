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

void preorder(struct TreeNode* root, int* res, int* usedSize, int* totalSize) {
	if (root == NULL) {
		return;
	}

	if (*totalSize == *usedSize) {
		res = (int *)realloc(res, sizeof(int) * (*totalSize) * 2);
		*totalSize *= 2;
	}

	res[*usedSize] = root->val;
	*usedSize += 1;
	preorder(root->left, res, usedSize, totalSize);
	preorder(root->right, res, usedSize, totalSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int* res = (int *)malloc(sizeof(int) * 10000);
	int* totalSize = (int *)malloc(sizeof(int));
	*totalSize = 10000;
	*returnSize = 0;
	preorder(root, res, returnSize, totalSize);

	return res;
}

int main() {


	system("pause");
	return 0;
}
#endif