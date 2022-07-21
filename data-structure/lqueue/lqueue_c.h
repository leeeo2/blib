#pragma once
#ifndef _QUEUE_C_H_
#define _QUEUE_C_H_

#include <stdbool.h>

#ifdef _cplusplus
extern "C" {
#endif
	typedef struct queue {
		int *elements;
		int length;
		int capacity;
		int head;
		int tail;
	} queue_c;

	void initQueue(queue_c *q,const int cap);//建队
	void destoryQueue(queue_c *q);//销毁队
	void clearQueue(queue_c *q);//清空队
	bool emptyQueue(const queue_c *q);//判空
	bool fullQueue(const queue_c *q);//判满
	bool push_c(queue_c *q, const int ele);//入队
	bool pop_c(queue_c *q);//出队
	void print_lqueue_c(const queue_c *q);//遍历打印

	void test_lqueue_c();

#ifdef _cplusplus
}
#endif
#endif