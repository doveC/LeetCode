#include <stdio.h>
#include <stdlib.h>
#if 0

#define R 26  // 26��Сд��ĸ

typedef struct prefixTreeNode {
	struct prefixTreeNode* links[R];  // ÿ���ڵ�26���ֲ�
	int isEnd;  // 0 or 1
} Node;

void nodeInit(Node** pRoot) {
	*pRoot = (Node *)malloc(sizeof(Node));
	for (int i = 0; i < R; i++) {
		(*pRoot)->links[i] = NULL;
	}
	(*pRoot)->isEnd = 0;
}

void prefixTreeInsert(Node* root, char* str) {
	Node* cur = root;

	while (*str) {  // ȡ��str��ÿ���ַ�
		if (cur->links[*str - 'a'] == NULL) {  // �������ַ�������
			nodeInit(&(cur->links[*str - 'a']));
		}
		cur = cur->links[*str - 'a'];  // curǰ������һ��	
		str++;
	}
	cur->isEnd = 1;
}

int prefixTreeSearch(Node* root, char* str) {
	Node* cur = root;

	while (*str) {
		if (cur->links[*str - 'a'] == NULL) {
			return 0;
		}
		else {
			cur = cur->links[*str - 'a'];
			str++;
		}
	}
	return cur->isEnd == 1;
}

int main() {
	Node* root;
	nodeInit(&root);
	prefixTreeInsert(root, "abc");
	printf("%d\n", prefixTreeSearch(root, "ab"));
	
	system("pause");
	return 0;
}
#endif