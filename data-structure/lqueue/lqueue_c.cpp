#include <malloc.h>
#include <stdio.h>
#include "lqueue_c.h"


void initQueue(queue_c *q,const int cap) {
	q->elements = (int *)malloc(cap * sizeof(int));
	q->capacity = cap;
	q->head = 0;
	q->tail = 0;
	q->length = 0;
}
void destoryQueue(queue_c *q) {
	free(q->elements);
	q->capacity = 0;
}

void clearQueue(queue_c *q) {
	q->head = 0;
	q->tail = 0;
	q->length = 0;
}

bool emptyQueue(const queue_c *q) {
	return q->length == 0 ? true : false;
}

bool fullQueue(const queue_c *q) {
	return q->length >= q->capacity ? true : false;
}

bool push_c(queue_c *q, const int ele) {
	if (fullQueue(q)) {
		return false;
	}
	q->elements[q->tail] = ele;
	q->tail = (q->tail++) % q->capacity;
	q->length++;
	return true;
}

bool pop_c(queue_c *q) {
	if (emptyQueue(q)) {
		return false;
	}

	q->head = (q->head++) % q->capacity;
	q->length--;
	return true;
}

void print_lqueue_c(const queue_c *q) {
	printf("information of the queue now:\n");
	printf("empty? %d\n", emptyQueue(q));
	printf("full? %d\n", fullQueue(q));
	printf("capacity: %d\n", q->capacity);
	printf("length: %d\n", q->length);
	printf("head: %d\n", q->head);
	printf("tail: %d\n", q->tail);
	printf("elements: ");

	for (int i = q->head; i < q->length + q->head; i++) {
		printf("%d ", q->elements[i]);
	}
	printf("\n\n");
}

void test_lqueue_c() {
	printf("----------------------test lqueue version c--------------------\n\n");
	queue_c q;
	printf("create a queue,capacity: 16\n");
	initQueue(&q,16);
	print_lqueue_c(&q);

	printf("push 16 elements to the queue,");
	for (int i = 0; i < 16; i++){
		push_c(&q, i);
	}
	print_lqueue_c(&q);

	printf("pop 8 elements,");
	for (int i = 0; i < 8; i++){
		pop_c(&q);
	}
	print_lqueue_c(&q);

	printf("clear the queue,");
	clearQueue(&q);
	print_lqueue_c(&q);

	printf("destory the queue,");
	destoryQueue(&q);
	print_lqueue_c(&q);

	printf("try to push some elements now:\n");
	if (push_c(&q, 12345)) {
		printf("push successfully:12345\n");
	}
	else {
		printf("push failed\n");
	}	
}