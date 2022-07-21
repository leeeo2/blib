#include "lqueue.h"

lx::lqueue::lqueue() :capacity(10), length(0), head(0), tail(0){}

lx::lqueue::lqueue(int cap) : capacity(cap), length(0), head(0), tail(0){
	q = new int[capacity];
}

lx::lqueue::~lqueue(){
	delete[]q;
	q = NULL;
}

void lx::lqueue::clear(){
	length = 0;
	head = 0;
	tail = 0;
}

bool lx::lqueue::empty() const{
	return length == 0 ? true : false;
}

bool lx::lqueue::full() const{
	return length == capacity ? true : false;
}

int lx::lqueue::getLength() const{
	return length;
}

bool lx::lqueue::push(const int &in){
	if (full()){
		return false;
	}
	else{
		q[tail] = in;
		tail = (++tail) % capacity; 
		length++;
		return true;
	}
}

bool lx::lqueue::pop(){
	if (empty()){
		return false;
	}
	else{
		head = (++head) % capacity;
		length--;
		return true;
	}

}

void lx::lqueue::print(){
	int i = head;
	std::cout << "information of this queue now:" << std::endl;
	std::cout << "empty? " << empty() << std::endl;
	std::cout << "full? " << full() << std::endl;
	std::cout << "capacity: " << capacity << std::endl;
	std::cout << "length: " << length << std::endl;
	std::cout << "head: " << head << std::endl;
	std::cout << "tail: " << tail << std::endl;
	std::cout << "elements: ";
	for (int i = 0; i < length;i++){
		std::cout << q[(i + head) % capacity] << " ";
	}
	std::cout << "\n\n";
}


void test_lqueue(){
	std::cout << "-----------------------test my queue-----------------------\n" << std::endl;
	std::cout << "create a queue,capacity: 16,";
	lx::lqueue q(16);
	q.print();

	std::cout << "push 16 elements to the queue,";
	for (int i = 0; i < 16; i++){
		q.push(i);
	}
	q.print();

	std::cout << "pop three elements,";
	for (int i = 0; i < 8; i++){
		if (!q.pop()){
			std::cout << "pop failed!" << std::endl;
		}
	}
	q.print();

	std::cout << "clear queue,";
	q.clear();
	q.print();
}