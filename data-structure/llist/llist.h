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
		int at(int index);//返回第index个元素
		int r_at(int index);//返回倒数第index个元素
		int front();//返回第一个元素
		int back();//返回最后一个元素
		bool push_front(int item);//将item插入到链表开头
		void pop_front();//将第一个元素弹出
		bool push_back(int item);//将item插入到链表尾
		void pop_back();//将链表尾元素弹出

		bool insert(int index, int item);//将item插入到index位置
		bool erase(int index);//删除第index个元素
		void reverse();//逆序链表
		//void remove(int item);//删除链表中的所有item元素
		void clear();//清空链表

		void print();


	private:
		_node *head;
	};

}


void test_llist();


#endif