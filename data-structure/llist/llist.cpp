#include "llist.h"


lx::llist::llist():head(nullptr){}


lx::llist:: ~llist() {
	clear();
}


int lx::llist::size() {
	int length = 0;
	_node *p = head;
	if (p == nullptr) {
		return 0;
	}
	while (p) {
		length++;
		p = p->next;
	}
	return length;
}


bool lx::llist::empty() {
	return head == nullptr ? true : false;
}


int lx::llist::at(int index) {
	if (empty()) {
		std::cerr << "get element in "<<index<<" failed,list is empty." << std::endl;
		return -1;
	}
	
	/*this way will traverse some element twice */
	//if (index >= size()) {
	//	std::cerr << "index out of bound." << std::endl;
	//	exit(-1);
	//}

	_node *p = head;
	_node *q = head->next;
	int i = 0;
	for (; i < index && q; i++) {
		p = q;
		q = p->next;
	}
	if (i != index) {
		std::cerr << "get element in index "<<index<<" failed,index out of bound." << std::endl;
		return -1;
	}
	return p->data;
}

int lx::llist::r_at(int index) {
	if (empty()) {
		std::cerr << "get the bottom "<<index<<" element failed,list is empty." << std::endl;
		return -1;
	}
	//if (index >= size()) {
	//	std::cerr << "index out of bound." << std::endl;
	//	return -1;
	//}

	_node *match = head;
	_node *current = head;
	int i = 0;
	for (; i < index && current; i++) {
		current = current->next;
	}
	if (i != index) {
		std::cerr << "get the bottom " << index << " element faled,index out of bound." << std::endl;
		return -1;
	}
	while (current->next) {
		match = match->next;
		current = current->next;
	}
	return match->data;
}


int lx::llist::front() {
	if (empty()) {
		std::cerr << "get the first element failed,list is empty." << std::endl;
		return -1;
	}
	return head->data;
}


int lx::llist::back() {
	if (empty()) {
		std::cerr << "get the last element failed,list is empty." << std::endl;
		return -1;
	}
	_node *first = head;
	_node *second = head->next;
	while (second) {
		first = second;
		second = second->next;
	}
	return first->data;
}


bool lx::llist::push_front(int item) {
	_node *tmp = nullptr;
	try {
		tmp = new _node;
	}
	catch (std::bad_alloc &e) {
		std::cerr << "bad_alloc:" << e.what() << std::endl;
		return false;
	}
	tmp->data = item;
	tmp->next = head;
	head = tmp;
	return true;
}


void lx::llist::pop_front() {
	if (empty()){
		return;
	}
	_node *tmp = head;
	head = head->next;
	delete tmp;
	tmp = nullptr;
}


bool lx::llist::push_back(int item){
	_node *tmp = nullptr;
	try {
		tmp = new _node;
	}
	catch (std::bad_alloc &e) {
		std::cerr << "bad_alloc:" << e.what() << std::endl;
		return false;
	}
	tmp->data = item;
	tmp->next = nullptr;


	if (empty()){
		head = tmp;
		tmp = nullptr;
		return true;
	}

	_node *first = head;
	_node *second = head->next;
	while (second){
		first = second;
		second = second->next;
	}
	first->next = tmp;
	tmp = nullptr;
	return true;
}


void lx::llist::pop_back() {
	if (empty()) {
		std::cout << "nothing to pop ,list is empty." << std::endl;
		return;
	}

	/*
	error solution:

	_node *first = head;
	_node *second = head->next;
	while (second) {
		first = second;
		second = second->next;
	}
	delete first;
	first = nullptr; //just point local pointer to the NULL
	*/

	if (!head->next) {
		delete head;
		head = nullptr; 
		return;
	}
	_node *first = head;
	_node *second = head->next;
	while (second->next) {
		first = second;
		second = second->next;
	}
	delete second;
	first->next = nullptr;
}


bool lx::llist::insert(int index, int item){
	_node *tmp = nullptr;
	try {
		tmp = new _node;
	}
	catch (std::bad_alloc &e) {
		std::cerr << "bad_alloc:" << e.what() << std::endl;
		return false;
	}
	tmp->data = item;
	tmp->next = nullptr;


	if (empty()){
		if (index != 0){
			std::cout << "index out of bound" << std::endl;
			return false;
		}
		head = tmp;
		tmp = nullptr;
		return true;
	}
	else{
		_node *first = head;
		_node *second = head->next;
		int i = 0;
		for (; i < index-1&&second; i++){
			first = second;
			second = second->next;
		}
		if (i != index-1){
			std::cout << "index out of bound" << std::endl;
			return false;
		}
		if (!second){
			first->next = tmp;
			tmp = nullptr;
			second = nullptr;
			return true;
		}
		else{
			tmp->next = second;
			first->next = tmp;
			tmp = nullptr;
			second = nullptr;
			return true;
		}

	}
}


bool lx::llist::erase(int index){
	if (empty()){
		std::cout << "erase element at index \"" << index << "\" failed,index out of bound,list is empty." << std::endl;
		return false;
	}

	if (!head->next){
		if (index != 0){
			std::cout << "erase element at index \"" << index << "\" failed,index out of bound." << std::endl;
			return false;
		}
		_node *tmp = head;
		head = head->next;
		delete tmp;
		tmp = nullptr;
		return true;
	}

	_node *first = head;
	_node *second = head->next;

	int i = 0;
	for (; i < (index-1)&&second->next; i++){
		first = second;
		second = second->next;
	}
	if (i != index-1){
		std::cout << "erase element at index \"" << index << "\" failed,index out of bound." << std::endl;
		return false;
	}

	first->next = second->next;
	delete second;
	return true;
}


void lx::llist::reverse(){
	if (empty() || !head->next){
		return;
	}
	_node *a = nullptr;
	_node *b = head;
	_node *c = head->next;

	while (c){
		b->next = a;
		a = b;
		b = c;
		c = c->next;
	}
	b->next = a;
	head = b;
}


void lx::llist::clear(){
	if (empty()){
		return;
	}
	_node *first = head;
	_node *second = head->next;

	while (second){
		delete first;
		first = second;
		second = second->next;
	}
	head = nullptr;
}


void lx::llist::print(){
	if (empty()){
		return;
	}

	_node *a = head;
	while (a){
		std::cout << a->data << " ";
		a = a->next;
	}
	std::cout<<std::endl;
}


void test_llist(){
	std::cout << "-------------------------------test llist version c++ -------------------------\n" << std::endl;
	std::cout << "create list." << std::endl;

	lx::llist l;
	l.print();

	std::cout << "push 3 elements to the front of list." << std::endl;
	for (int i = 0; i < 3; i++){
		l.push_front(i);
	}
	l.print();
	std::cout << "get the front element: " << l.front()<< std::endl;
	std::cout << "get the back element: " << l.back() << std::endl;
	std::cout << "push 3 elements to the back of list." << std::endl;
	for (int i = 3; i < 6; i++){
		l.push_back(i);
	}
	l.print();

	std::cout << "get the element of index 3: " << l.at(3) << std::endl;
	std::cout << "r_at(3): " << l.r_at(3) << std::endl;

	std::cout << "insert a element to index 4: " << std::endl;
	l.insert(4, 100);
	l.print();
	std::cout << "erase the element of index 4: " << std::endl;
	l.erase(4);
	l.print();
	std::cout << "pop 2 elements from front." << std::endl;
	l.pop_front();
	l.pop_front();
	l.print();

	std::cout << "pop 2 elements form back." << std::endl;
	l.pop_back(), l.pop_back();
	l.print();

	std::cout << "push 10 elements to front:" << std::endl;
	for (int i = 10; i < 20; i++){
		l.push_front(i);
	}
	l.print();

	std::cout << "reverse list." << std::endl;
	l.reverse();
	l.print();

	std::cout << "empty? " << l.empty() << std::endl;

	std::cout << "clear list." << std::endl;
	l.clear();
	l.print();

	std::cout << "empty? " << l.empty() << std::endl;



	l.print();
}