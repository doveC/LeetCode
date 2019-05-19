#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#if 0

typedef struct QueueNode {
	struct QueueNode *next;
	int data;
} Node;

typedef struct Queue {
	Node *head;
	Node *rear;
} Queue;

// ---------- implement queue -------------

void QueueInit(Queue *pQ) {
	assert(pQ);

	pQ->head = NULL;
	pQ->rear = NULL;
}

void QueueDestroy(Queue *pQ) {
	assert(pQ);

	Node *cur, *tmp;
	cur = pQ->head;
	while (cur) {
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	pQ = NULL;
}

Node* getNode(int data) {
	Node* res = (Node *)malloc(sizeof(Node));
	res->next = NULL;
	res->data = data;

	return res;
}

void QueuePush(Queue *pQ, int data) {
	assert(pQ);

	Node* newNode = getNode(data);
	if (pQ->head == NULL) {  // empty queue
		pQ->head = pQ->rear = newNode;
		
	}
	else {
		pQ->rear = pQ->rear->next = newNode;
	}
}

void QueuePop(Queue *pQ) {
	assert(pQ);

	if (pQ->head != NULL) {  // if not empty queue
		Node *tmp = pQ->head;
		if (pQ->head == pQ->rear) {  // only one node
			pQ->head = pQ->rear = NULL;
		}
		else {
			pQ->head = pQ->head->next;
		}
		free(tmp);
	}
}

int QueueHead(Queue *pQ) {
	assert(pQ);
	assert(pQ->head);

	return pQ->head->data;
}

int QueueRear(Queue *pQ) {
	assert(pQ);
	assert(pQ->rear);

	return pQ->rear->data;
}

int QueueEmpty(Queue *pQ) {
	assert(pQ);

	return pQ->head == NULL;
}

int QueueSize(Queue *pQ) {
	assert(pQ);

	Node* cur = pQ->head;
	int count = 0;

	while (cur) {
		cur = cur->next;
		count++;
	}

	return count;
}

// ----------- implement stack ------------

typedef struct {
	Queue *qFull;
	Queue *qEmpty;
} MyStack;

typedef int bool;
#define true 1;
#define false 0;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	Queue *pFull = (Queue *)malloc(sizeof(Queue));
	Queue *pEmpty = (Queue *)malloc(sizeof(Queue));
	QueueInit(pFull);
	QueueInit(pEmpty);

	MyStack *myStack = (MyStack *)malloc(sizeof(MyStack));
	myStack->qFull = pFull;
	myStack->qEmpty = pEmpty;

	return myStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	QueuePush(obj->qFull, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	while (QueueSize(obj->qFull) != 1) {
		QueuePush(obj->qEmpty, QueueHead(obj->qFull));
		QueuePop(obj->qFull);
	}
	int res = QueueHead(obj->qFull);
	QueuePop(obj->qFull);
	
	Queue *tmp = obj->qFull;
	obj->qFull = obj->qEmpty;
	obj->qEmpty = tmp;

	return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	while (QueueSize(obj->qFull) != 1) {
		QueuePush(obj->qEmpty, QueueHead(obj->qFull));
		QueuePop(obj->qFull);
	}
	int res = QueueHead(obj->qFull);
	QueuePush(obj->qEmpty, QueueHead(obj->qFull));
	QueuePop(obj->qFull);

	Queue *tmp = obj->qFull;
	obj->qFull = obj->qEmpty;
	obj->qEmpty = tmp;

	return res;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueSize(obj->qFull) == 0;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(obj->qEmpty);
	QueueDestroy(obj->qFull);
}

int main() {
	MyStack* m = myStackCreate();
	myStackPush(m, 1);
	myStackPush(m, 2);

	printf("%d\n", myStackTop(m));
	printf("%d\n", myStackPop(m));

	system("pause");
	return 0;
}
#endif
