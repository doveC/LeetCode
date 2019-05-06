#include <stdio.h>
//#define S1
//#define S2

// -------------------- Solution 1 --------------------------
#ifdef S1
typedef struct {
	int minStack[100000];
	int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* p = (MinStack *)malloc(sizeof(MinStack));
	p->top = 0;

	return p;
}

void minStackPush(MinStack* obj, int x) {
	int min;

	if (obj->top == 0) {  // ��ջ��ֱ����ջ�Ϳ�����
		obj->minStack[obj->top] = x;
		obj->minStack[obj->top + 1] = x;
		obj->top += 2;
	}
	else {
		min = obj->minStack[obj->top - 1];  // ȡ��ջ����СԪ��
		obj->minStack[obj->top] = x;
		obj->minStack[obj->top + 1] = x < min ? x : min;
		obj->top += 2;
	}
}

void minStackPop(MinStack* obj) {
	obj->top -= 2;
}

int minStackTop(MinStack* obj) {
	return obj->minStack[obj->top - 2];
}

int minStackGetMin(MinStack* obj) {
	return obj->minStack[obj->top - 1];
}

void minStackFree(MinStack* obj) {
	free(obj);
}
#endif

// ------------------------- Solution 2 ------------------------
#ifdef S2

typedef struct {
	int stack[100000];
	int minStack[100000];
	int top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* p = (MinStack *)malloc(sizeof(MinStack));
	p->top = 0;

	return p;
}

void minStackPush(MinStack* obj, int x) {
	// �����������ѹ����ͨջ
	obj->stack[obj->top] = x;

	// ����Сֵѹ����Сջ
	if (obj->top == 0) {
		obj->minStack[obj->top] = x;
	}
	else {
		int min = obj->minStack[obj->top - 1];
		obj->minStack[obj->top] = x < min ? x : min;
	}

	// ����top
	obj->top++;
}

void minStackPop(MinStack* obj) {
	obj->top--;
}

int minStackTop(MinStack* obj) {
	return obj->stack[obj->top - 1];
}

int minStackGetMin(MinStack* obj) {
	return obj->minStack[obj->top - 1];
}

void minStackFree(MinStack* obj) {
	free(obj);
}

#endif
