#pragma once
#ifndef _LSTACK_H_
#define _LSTACK_H_

#include <iostream>

namespace lx{
	class stack_cpp {
	public:
		stack_cpp(int cap);
		~stack_cpp();

		void clear();
		bool empty();
		bool full();
		bool push(const int &ele);
		bool pop();
		int getTop();
		int getCap();
		int getLength();
		int getTopIndex();
		int size();
		void traverse();

	private:
		int *elements;
		int capacity;
		int length;
		int top;
	};

}

void print_information_of_lstack(lx::stack_cpp &s);
void test_lstack();

#endif