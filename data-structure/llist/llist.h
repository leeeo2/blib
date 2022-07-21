#pragma once


#ifndef _LLIST_H_
#define _LLIST_H_

#include <iostream>
#include <memory>

typedef struct node{
	int data;
	node *next;
}_node;


namespace lx{
	class llist{
	public:
		llist();
		~llist();

		int size();
		bool empty();
		int at(int index);//���ص�index��Ԫ��
		int r_at(int index);//���ص�����index��Ԫ��
		int front();//���ص�һ��Ԫ��
		int back();//�������һ��Ԫ��
		bool push_front(int item);//��item���뵽����ͷ
		void pop_front();//����һ��Ԫ�ص���
		bool push_back(int item);//��item���뵽����β
		void pop_back();//������βԪ�ص���

		bool insert(int index, int item);//��item���뵽indexλ��
		bool erase(int index);//ɾ����index��Ԫ��
		void reverse();//��������
		//void remove(int item);//ɾ�������е�����itemԪ��
		void clear();//�������

		void print();


	private:
		_node *head;
	};

}


void test_llist();


#endif