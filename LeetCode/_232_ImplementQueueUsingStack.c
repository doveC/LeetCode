#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0

// --------- implement stack ----------

typedef struct Stack {
	int* arr;
	int capacity;
	int top;
} Stack;

void StackInit(Stack* ps) {
	assert(ps);

	int* tmp = (int *)malloc(sizeof(int) * 10);
	if (tmp == NULL) {
		assert(0);
	}

	ps->arr = tmp;
	ps->capacity = 10;
	ps->top = 0;
}

void StackDestroy(Stack* ps) {
	assert(ps);

	free(ps->arr);
	ps = NULL;
}

void CheckCap(Stack* ps) {
	assert(ps);

	if (ps->capacity == ps->top) {  // full
		int* tmp = (int *)realloc(ps->arr, ps->capacity * 2);
		assert(tmp);

		ps->arr = tmp;
		ps->capacity *= 2;
	}
}

void StackPush(Stack* ps, int data) {
	assert(ps);

	CheckCap(ps);

	ps->arr[ps->top++] = data;
}

void StackPop(Stack* ps) {
	assert(ps);

	if (ps->top != 0) {
		ps->top--;
	}
}

int StackTop(Stack* ps) {
	assert(ps);
	assert(ps->top);

	return ps->arr[ps->top - 1];
}

int StackEmpty(Stack* ps) {
	assert(ps);

	return ps->top == 0;
}

int StackSize(Stack* ps) {
	assert(ps);

	return ps->top;
}

// ------------ implement queue ------------
typedef struct {
	Stack* s1;
	Stack* s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* res = (MyQueue *)malloc(sizeof(MyQueue));
	res->s1 = (Stack *)malloc(sizeof(Stack));
	res->s2 = (Stack *)malloc(sizeof(Stack));
	StackInit(res->s1);
	StackInit(res->s2);

	return res;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(obj->s2)) {
		while (!StackEmpty(obj->s1)) {
			StackPush(obj->s2, StackTop(obj->s1));
			StackPop(obj->s1);
		}
	}

	int res = StackTop(obj->s2);
	StackPop(obj->s2);
	return res;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(obj->s2)) {
		while (!StackEmpty(obj->s1)) {
			StackPush(obj->s2, StackTop(obj->s1));
			StackPop(obj->s1);
		}
	}

	int res = StackTop(obj->s2);

	return res;
}

/** Returns whether the queue is empty. */
typedef int bool;
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(obj->s1) && StackEmpty(obj->s2);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(obj->s1);
	StackDestroy(obj->s2);
}
#endif