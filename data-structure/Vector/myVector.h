#pragma once
#include "define.h"

/**
  *  向量数组模板类，提供模板元素的数组基本操作
  *  其中ElementType必须有拷贝构造方法、重构相等==运算符
**/

#define DEFAULT_INIT_SIZE 20
#define DEFAULT_ADD_STEP 5

template<class ElementType>
class MyVector
{
public:
	/*默认构造函数*/
	MyVector();

	/*构造函数*/
	MyVector(ElementType elems[], int size);

	/*析构函数*/
	~MyVector();

	/*初始化*/
	Status Init();

	/*清空vector*/
	Status Clear(); 

	/*判空*/
	bool Empty();

	/*按址查找*/
	Status At(int pos, ElementType &ret);

	/*按值查找*/
	Status Locate(const ElementType &elem,int &pos);

	/*将elem插入到pos位置*/
	Status Insert(const ElementType &elem, int pos);

	/*删除pos位置的元素*/
	Status Delete(int pos);

	/*查找pos位置的前驱，存入elem*/
	Status Prior(int pos, ElementType &elem);

	/*查找pos位置的后继，存入elem*/
	Status next(int pos, ElementType &elem);

private:
	ElementType *data;
	uint32_t length;
	uint32_t capacity;
};

