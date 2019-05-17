#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

typedef int bool;
#define true 1;
#define false 0;

typedef struct {
	int *arr;
	int size;
	int capacity;
	int head;
	int rear;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* res = 
		(MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	res->arr = (int *)malloc(sizeof(int) * k);
	res->size = 0;
	res->capacity = k;
	res->head = 0;
	res->rear = 0;

	return res;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj->size == obj->capacity) {
		return false;
	}

	obj->arr[obj->rear] = value;
	obj->rear = (obj->rear + 1) % obj->capacity;
	obj->size++;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->size == 0) {
		return false;
	}

	obj->head = (obj->head + 1) % obj->capacity;
	obj->size--;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->size == 0) {
		return -1;
	}
	return obj->arr[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->size == 0) {
		return -1;
	}
	return obj->arr[obj->rear == 0 ? obj->capacity - 1 : obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->size == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {

}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

int main() {


	system("pause");
	return 0;
}
#endif