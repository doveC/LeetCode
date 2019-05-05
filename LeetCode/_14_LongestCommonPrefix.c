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

	for (int i = 0; i < strlen(strs[0]); i++) {  // ����strs[0]��i���ַ�
		char c = strs[0][i];
		for (int j = 1; j < strsSize; j++) {  // �͵�strs[j]���ַ����ĵ�i���ַ��Ƚ�
			if (strs[j][i] != c || strs[j][i] == '\0') {
				strs[0][i] = '\0';
				return strs[0];
			}
		}
	}

	return strs[0];
}

// --------------- Trie --------------------

#define R 26  // 26��Сд��ĸ

typedef struct prefixTreeNode {
	struct prefixTreeNode* links[R];  // ÿ���ڵ�26���ֲ�
	int size;  // ��ǰ�ڵ��м����ǿ��ӽڵ�
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

	while (*str) {  // ȡ��str��ÿ���ַ�
		if (cur->links[*str - 'a'] == NULL) {  // �������ַ�������
			nodeInit(&(cur->links[*str - 'a']));
			cur->size++;
		}
		cur = cur->links[*str - 'a'];  // curǰ������һ��	
		str++;
	}
	cur->isEnd = 1;
}

// ���ص�ǰ�ڵ��м����ǿ��ӽڵ�
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

	// ǰ׺����ʼ��
	Node* root;
	nodeInit(&root);

	// �������ַ�������ǰ׺��
	for (int i = 0; i < strsSize; i++) {
		prefixTreeInsert(root, strs[i]);
	}
	
	// Ѱ�������ǰ׺
	char* res = (char *)malloc(sizeof(char) * 1000);
	char* tmp = res;
	Node* cur = root;

	for (int i = 0; ; i++) {
		char c = strs[0][i];

		// ������������ʾ�Ѿ��ҵ��������ǰ׺��Ҫ����ѭ��
		// 1. cur->isEnd = 1����ʾ��һ���ַ�����ֹ��������ַ�
		// 2. cur���в�ֹһ���ӽڵ�ǿ�
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