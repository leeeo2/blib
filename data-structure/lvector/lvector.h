#pragma once

#ifndef _LVECTOR_H_
#define _LVECTOR_H_

namespace lx {
	class lvector {
	public:
		lvector();
		~lvector();

		//status function
		void clear();
		bool empty();
		int size();
		int capacity();
		//operator
		int at(int index);
		bool push_back(int item);
		void pop_back();
		bool insert(int index, int item);
		bool _delete(int index);  //删除指定索引的元素
		int find(int item);   //查找指定值的第一个索引
		void remove(int item);   //删除指定值的元素

	private:
		bool resize(int new_cap);

		//bool operator==(lvector &right);
		//lvector& operator=(lvector &right);

	private:
		int *data;
		int length;
		int cap;

	};
}


void test_lvector();

#endif