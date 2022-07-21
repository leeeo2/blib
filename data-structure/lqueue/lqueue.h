#ifndef _LQUEUE_H_
#define _LQUEUE_H_

#include <stddef.h>
#include <iostream>

namespace lx{
	class lqueue{
	public:
		lqueue();//Ĭ�Ϲ���
		explicit lqueue(int cap); //��������Ϊcap�Ķ���
		virtual ~lqueue();//����
		void clear();//���
		bool empty() const;//�п�
		bool full() const;//����
		int getLength() const;//��ȡ����
		bool push(const int &in);//���
		bool pop();//����
		void print();//������ӡ

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