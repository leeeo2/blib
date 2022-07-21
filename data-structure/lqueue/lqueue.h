#ifndef _LQUEUE_H_
#define _LQUEUE_H_

#include <stddef.h>
#include <iostream>

namespace lx{
	class lqueue{
	public:
		lqueue();//默认构造
		explicit lqueue(int cap); //构造容量为cap的队列
		virtual ~lqueue();//析构
		void clear();//清空
		bool empty() const;//判空
		bool full() const;//判满
		int getLength() const;//获取长度
		bool push(const int &in);//入队
		bool pop();//出队
		void print();//遍历打印

	private:
		int *q;
		int length;
		int capacity;
		int head;
		int tail;
	};
}
void test_lqueue();

#endif