#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HTCAPACITY 5000

typedef int bool;
#define true 1
#define false 0

typedef struct _htItem {
	struct _htItem* next;
	int arrayIndex;
	int val;
}htItem;

typedef struct {
	htItem** ht;
	int array[HTCAPACITY];
	int size;  // ��¼array���ж��ٸ���
} RandomizedCollection;

/** Initialize your data structure here. */
RandomizedCollection* randomizedCollectionCreate() {
	RandomizedCollection* rc =
		(RandomizedCollection*)malloc(sizeof(RandomizedCollection));
	rc->ht = (htItem **)malloc(sizeof(htItem *) * HTCAPACITY);
	for (int i = 0; i < HTCAPACITY; i++) {
		rc->ht[i] = (htItem *)malloc(sizeof(htItem));
		rc->ht[i]->next = NULL;
		rc->ht[i]->arrayIndex = -1;
		rc->ht[i]->val = -1;
	}
	memset(rc->array, 0, sizeof(int) * HTCAPACITY);
	rc->size = 0;

	return rc;
}

/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
bool randomizedCollectionInsert(RandomizedCollection* obj, int val) {
	// hash
	int index = (val % HTCAPACITY);
	index = index >= 0 ? index : index + HTCAPACITY;

	// insert
	bool sign = true;
	htItem* ptr = obj->ht[index];
	while (ptr->next != NULL) {
		ptr = ptr->next;
		if (ptr->val == val) {
			sign = false;
		}
	}
	ptr->next = (htItem *)malloc(sizeof(htItem));
	ptr->next->val = val;
	ptr->next->next = NULL;

	// �����������array
	obj->array[obj->size] = val;
	ptr->next->arrayIndex = obj->size;
	obj->size++;

	return sign;
}

/** Removes a value from the collection. Returns true if the collection contained the specified element. */
bool randomizedCollectionRemove(RandomizedCollection* obj, int val) {
	// hash
	int index = (val % HTCAPACITY);
	index = index >= 0 ? index : index + HTCAPACITY;

	// find
	bool sign = false;
	htItem* ptr = obj->ht[index];
	while (ptr->next != NULL && ptr->next->val != val) {  // ������������Ѱ��val
		ptr = ptr->next;
	}
	if (ptr->next == NULL) {  // ���û�ҵ�
		return sign;
	}
	else {  // ptr->next����Ҫɾ����Ԫ��
		htItem* item = ptr->next;

		// �ӹ�ϣ����ɾ�����Ԫ��
		ptr->next = ptr->next->next;  
		
		// ��array��ɾ�����Ԫ��
		if (obj->size == 1) {  // ���������ֻ����һ��Ԫ��
			obj->size--;
		}
		else {
			if (item->arrayIndex == obj->size - 1) {  // ������Ԫ����������ĩβ
				obj->size--;
			}
			else {  // ������Ԫ�ز�����ĩβ��������ĩβԪ�ظ������λ�ã�ͬʱҪ�޸Ĺ�ϣ�������Ԫ�ص�arrayIndex
				obj->array[item->arrayIndex] = obj->array[obj->size - 1];
				int data = obj->array[obj->size - 1];  // data��ĩβԪ�ص���ֵ

				// �ڹ�ϣ������data
				int tmpIndex = (data % HTCAPACITY);
				tmpIndex = tmpIndex >= 0 ? tmpIndex : tmpIndex + HTCAPACITY;
				htItem* tmpPtr = obj->ht[tmpIndex];
				tmpPtr = tmpPtr->next;
				while (tmpPtr->arrayIndex != obj->size - 1) {
					tmpPtr = tmpPtr->next;
				}
				tmpPtr->arrayIndex = item->arrayIndex;  // ���µ������±긳ֵ		

				obj->size--;
				free(item);
			}
		}
		return true;
	}
}

/** Get a random element from the collection. */
int randomizedCollectionGetRandom(RandomizedCollection* obj) {
	int index = rand() % (obj->size);
	return obj->array[index];
}

void randomizedCollectionFree(RandomizedCollection* obj) {
	for (int i = 0; i < HTCAPACITY; i++) {
		free(obj->ht[i]);
	}
	free(obj);
}

/**
 * Your RandomizedCollection struct will be instantiated and called as such:
 * struct RandomizedCollection* obj = randomizedCollectionCreate();
 * bool param_1 = randomizedCollectionInsert(obj, val);
 * bool param_2 = randomizedCollectionRemove(obj, val);
 * int param_3 = randomizedCollectionGetRandom(obj);
 * randomizedCollectionFree(obj);
 */

int main() {
	srand((unsigned int)time(0));
	RandomizedCollection* obj = randomizedCollectionCreate();
	bool sign;
	sign = randomizedCollectionInsert(obj, 3);
	sign = randomizedCollectionInsert(obj, 4);
	sign = randomizedCollectionInsert(obj, 3);
	sign = randomizedCollectionRemove(obj, 3);
	sign = randomizedCollectionRemove(obj, 3);
	printf("\n");

	system("pause");
	return 0;
}
