#include <stdio.h>
#include <malloc.h>

#include "lstack_c.h"


void initStack(stack_c *s,int cap) {
	s->elements = (int *)malloc(cap * sizeof(int));
	s->capacity = cap;
	s->length = 0;
	s->top = -1;
}

void destoryStack(stack_c *s) {
	free(s->elements);
	s->capacity = 0;
}

void clearStack(stack_c *s) {
	s->length = 0;
	s->top = -1;
}

bool emptyStack(stack_c *s) {
	return s->length == 0 ? true : false;
}

bool fullStack(stack_c *s) {
	return s->length == s->capacity ? true : false;
}

bool pushStack(stack_c *s, int ele) {
	if (fullStack(s)) {
		return false;
	}
	else {
		s->elements[++s->top] = ele;
		s->length++;
		return true;
	}
}

bool popStack(stack_c *s) {
	if (emptyStack(s)) {
		return false;
	}
	else {
		s->top--;
		s->length--;
		return true;
	}
}

int getTop(stack_c *s) {
	if (emptyStack(s)) {
		printf("stack now is empty");
		return -1;
	}
	else {
		return s->elements[s->top];
	}
}

void traverse_lstack_c(stack_c *s) {
	for (int i = 0; i < s->length; i++) {
		printf("%d ", s->elements[i]);
	}
}


void print_information_of_lstack_c(stack_c *s) {
	printf("information of this stack now:\n");
	printf("empty? %d\n", emptyStack(s));
	printf("full? %d\n", fullStack(s));
	printf("capacity: %d\n", s->capacity);
	printf("length: %d\n", s->length);
	printf("index of top: %d\n", s->top);
	printf("element in top: %d\n", getTop(s));
	printf("elements:"); traverse_lstack_c(s);
	printf("\n\n");
}


void test_lstack_c() {
	printf("-------------------------test lstack version c ----------------------\n\n");
	printf("create a stack,capacity: 16");
	stack_c s;
	initStack(&s, 16);
	print_information_of_lstack_c(&s);

	printf("push 5 elements to the stack:");
	for (int i = 0; i < 11; i++) {
		pushStack(&s, i);
	}
	print_information_of_lstack_c(&s);

	printf("pop 3 elements");
	for (int i = 0; i < 3; i++) {
		popStack(&s);
	}
	print_information_of_lstack_c(&s);
	
	printf("clear the stack,");
	clearStack(&s);
	print_information_of_lstack_c(&s);

	printf("destory this stack,");
	destoryStack(&s);
	print_information_of_lstack_c(&s);

	printf("try to push some elements to this stack now:\n");
	if (pushStack(&s, 3)) {
		printf("push successfully\n");
	}
	else {
		printf("push failed.\n");
	}
}