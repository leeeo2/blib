#pragma once

#ifndef _STACK_C_H_
#define _STACK_C_H_

#include <stdbool.h>

#ifdef _cplusplus
extern "C" {
#endif
	typedef struct _stack {
		int *elements;
		int capacity;
		int length;
		int top;
	}stack_c;

	void initStack(stack_c *s,int cap);
	void destoryStack(stack_c *s);
	void clearStack(stack_c *s);
	bool emptyStack(stack_c *s);
	bool fullStack(stack_c *s);
	bool pushStack(stack_c *s, int ele);
	bool popStack(stack_c *s);
	int getTop(stack_c *s);
	void traverse_lstack_c(stack_c *s);

	void print_information_of_lstack_c(stack_c *s);
	void test_lstack_c();


#ifdef _cplusplus
}
#endif
#endif