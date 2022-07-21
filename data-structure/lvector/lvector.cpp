#include <memory>
#include <iostream>
//#include <new>
#include "lvector.h"


lx::lvector::lvector():cap(16),length(0) {
	data = new int[cap];
}


lx::lvector::~lvector() {
	delete[]data;
}


void lx::lvector::clear() {
	memset(data, 0, cap);
	length = 0;
}


bool lx::lvector::empty() {
	return length == 0 ? true : false;
}


int lx::lvector::size() {
	return length;
}


int lx::lvector::capacity() {
	return cap;
}


int lx::lvector::at(int index) {
	return data[index];
}


bool lx::lvector::resize(int new_cap) {
		int *tmp;
		try {
			tmp = new int[new_cap];
		}
		catch (std::bad_alloc &e) {
			std::cerr << e.what() << std::endl;
			return false;
		}
		memcpy(tmp, data, length * sizeof(int));
		delete[]data;
		cap = new_cap;
		data = tmp;
		return true;
}

bool lx::lvector::push_back(int item) {
	if ((length == cap) && (!resize(cap * 2))) {
		return false;
	}
	data[length] = item;
	length++;
	return true;
}


void lx::lvector::pop_back() {
	if (empty()) {
		return;
	}
	data[length] = 0;
	length--;
	if (length <= (cap >> 2)) {
		resize(cap >> 1);
	}
}


bool lx::lvector::insert(int index, int item) {
	if ((index > length)||((length == cap) && (!resize(cap * 2)))){
		return false;
	}
	memcpy(&data[index + 1], &data[index], (length - index)*sizeof(int));
	data[index] = item;
	length++;
	return true;
}


bool lx::lvector::_delete(int index) {
	if (index >= length) {
		return false;
	}
	memcpy(&data[index], &data[index + 1], (length - index - 1)*sizeof(int));
	length--;
	if (length <= (cap >> 2)) {
		resize(cap >> 1);
	}
	return true;
}


int lx::lvector::find(int item) {
	for (int i = 0; i < length; i++) 
		if (data[i] == item) 
			return i;
	return -1;
}

void lx::lvector::remove(int item) {
	for (int i = 0; i < length; i++) 
		if (data[i] == item) {
			_delete(i);
			i--;
		}
 }

void print_lvector_Info_cpp(lx::lvector &lv) {
	std::cout << "information of this vector now:\n";
	std::cout << "capacity: " << lv.capacity() << std::endl;
	std::cout << "length: " << lv.size() << std::endl;
	std::cout << "elements: ";
	for (int i = 0; i < lv.size(); i++) {
		std::cout << lv.at(i) << "  ";
	}
	std::cout << std::endl;

}

void test_lvector() {
	std::cout << "---------------------test lvector verison c++ -----------------------\n\n";
	std::cout << "create a vector ,initial capacity:16\n";
	lx::lvector lv;
	print_lvector_Info_cpp(lv);

	std::cout << "push back 0~9:" << std::endl;
	for (int i = 0; i < 10; i++) {
		lv.push_back(i);
	}
	print_lvector_Info_cpp(lv);

	std::cout << "\npush back 10~17:" << std::endl;
	for (int i = 10; i < 18; i++) {
		lv.push_back(i);
	}
	print_lvector_Info_cpp(lv); 

	std::cout << "\ndelete index 0 two times:" << std::endl;
	lv._delete(0);
	lv._delete(0);
	print_lvector_Info_cpp(lv);

	std::cout << "\nfind item 2: index " << lv.find(2) << std::endl;
	std::cout << "\ninsert three 12 to index 1:" << std::endl;
	lv.insert(1,12);
	lv.insert(1,12);
	lv.insert(1,12);
	print_lvector_Info_cpp(lv);

	std::cout << "find index of the first 12: "<<lv.find(12);

	std::cout << "\nremove all 12:" << std::endl;
	lv.remove(12);
	print_lvector_Info_cpp(lv);

	std::cout << "\npop back 15 elements:" << std::endl;
	for (int i = 0; i < 15; i++) {
		lv.pop_back();
	}
	print_lvector_Info_cpp(lv);
}
