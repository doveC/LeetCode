#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

char* longestCommonPrefix(char ** strs, int strsSize) {
	if (strsSize == 0) {
		return "";
	}
	if (strsSize == 1) {
		return strs[0];
	}

	for (int i = 0; i < strlen(strs[0]); i++) {  // 遍历strs[0]第i个字符
		char c = strs[0][i];
		for (int j = 1; j < strsSize; j++) {  // 和第strs[j]个字符串的第i个字符比较
			if (strs[j][i] != c || strs[j][i] == '\0') {
				strs[0][i] = '\0';
				return strs[0];
			}
		}
	}

	return strs[0];
}

// --------------- Trie --------------------

#define R 26  // 26个小写字母

typedef struct prefixTreeNode {
	struct prefixTreeNode* links[R];  // 每个节点26个分叉
	int size;  // 当前节点有几个非空子节点
	int isEnd;  // 0 or 1
} Node;

void nodeInit(Node** pRoot) {
	*pRoot = (Node *)malloc(sizeof(Node));
	for (int i = 0; i < R; i++) {
		(*pRoot)->links[i] = NULL;
	}
	(*pRoot)->isEnd = 0;
	(*pRoot)->size = 0;
}

void prefixTreeInsert(Node* root, char* str) {
	Node* cur = root;

	while (*str) {  // 取出str中每个字符
		if (cur->links[*str - 'a'] == NULL) {  // 如果这个字符不存在
			nodeInit(&(cur->links[*str - 'a']));
			cur->size++;
		}
		cur = cur->links[*str - 'a'];  // cur前进到下一层	
		str++;
	}
	cur->isEnd = 1;
}

// 返回当前节点有几个非空子节点
int getLinks(Node* pNode) {
	return pNode->size;
}

char * longestCommonPrefix1(char ** strs, int strsSize) {
	if (strsSize == 0) {
		return "";
	}
	if (strsSize == 1) {
		return strs[0];
	}

	// 前缀树初始化
	Node* root;
	nodeInit(&root);

	// 将所有字符串插入前缀树
	for (int i = 0; i < strsSize; i++) {
		prefixTreeInsert(root, strs[i]);
	}
	
	// 寻找最长公共前缀
	char* res = (char *)malloc(sizeof(char) * 1000);
	char* tmp = res;
	Node* cur = root;

	for (int i = 0; ; i++) {
		char c = strs[0][i];

		// 有两个条件表示已经找到了最长公共前缀，要跳出循环
		// 1. cur->isEnd = 1，表示有一个字符串终止在了这个字符
		// 2. cur下有不止一个子节点非空
		if (cur->isEnd != 1 && getLinks(cur) == 1) {
			*tmp++ = c;
			cur = cur->links[c - 'a'];
			continue;
		}
		break;
	}
	*tmp = '\0';

	return res;
}

// -----------------------------------------

int main() {
	char** strs = (char**)malloc(sizeof(char*) * 3);
	strs[0] = "flight";
	strs[1] = "flower";
	strs[2] = "fl";

	char* res = longestCommonPrefix1(strs, 3);
	printf("%s\n", res);
	printf("\n");

	system("pause");
	return 0;
}
#endif