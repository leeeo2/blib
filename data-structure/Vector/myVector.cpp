#include "pch.h"
#include "myVector.h"


/*默认构造函数*/
template<class ElementType>
MyVector<ElementType>::MyVector():capacity(DEFAULT_INIT_SIZE),length(0) {}

/*构造函数*/
template<class ElementType>
MyVector<ElementType>::MyVector(ElementType elems[], int size) {
	capacity = size / 2 * 3;//1.5倍
	data = new ElementType[capacity];
	memcpy(data, elems, sizeof(ElementType)*size);
	length = size;
}

/*析构函数*/
template<class ElementType>
MyVector<ElementType>::~MyVector() {
	Clear();
}

/*初始化*/
template<class ElementType>
Status MyVector<ElementType>::Init() {
	data = new ElementType[DEFAULT_INIT_SIZE];
	if (!data) {
		return My_Failed;
	}
	capacity = DEFAULT_INIT_SIZE;
	length = 0;
	return My_Success;
}

/*清空vector*/
template<class ElementType>
Status MyVector<ElementType>::Clear() {
	if (data) {
		delete[]data;
		data = nullptr;
	}
	capacity = 0;
	length = 0;
	return My_Success;
}

/*判空*/
template<class ElementType>
bool MyVector<ElementType>::Empty() {
	return length == 0;
}

/*按址查找*/
template<class ElementType>
Status MyVector<ElementType>::At(int pos, ElementType &ret) {
	if (pos >= length) {
		return My_Range_Error;
	}
	ret = data[pos];
	return My_Success;
}

/*按值查找*/
template<class ElementType>
Status MyVector<ElementType>::Locate(const ElementType &elem,int &pos) {
	for (int i = 0; i < length; i++) {
		if (data[i] == elem) {
			pos = i;
			return My_Success;
		}
	}
	return My_Failed;
}

/*将elem插入到pos位置*/
template<class ElementType>
Status MyVector<ElementType>::Insert(const ElementType &elem, int pos) {
	//扩容
	if (length == capacity-1) {
		capacity += DEFAULT_ADD_STEP;
		ElementType *tmp = new ElementType[capacity];
		if (!tmp) {
			return My_Failed;
		}
		memcpy(tmp, data, sizeof(ElementType)*length);
	}
	if (pos > length) {   
		return My_Range_Error;
	}
	else if (pos == length) {
		data[pos] = elem;
		length++;
		return My_Success;
	}
	else {
		for (int i = length; i != pos; i--) {
			data[i + 1] = data[i];
		}
		data[pos] = elem;
		length++;
		return My_Success;
	}
}

/*删除pos位置的元素*/
template<class ElementType>
Status MyVector<ElementType>::Delete(int pos) {
	//调整容量
	if (capacity / length >= 3) {
		capacity -= DEFAULT_ADD_STEP;
		ElementType *tmp = new ElementType[capacity];
		if (!tmp) {
			return My_Failed;
		}
		memcpy(tmp, data, sizeof(ElementType)*length);
	}
	if (pos >= length) {
		return My_Range_Error;
	}
	else if (pos == length - 1) {
		length--;
		return  My_Success;
	}
	else {
		for (int i = pos; i < length-1; i++) {
			data[i] = data[i + 1];
			length--;
			return My_Success;
		}
	}
}

/*查找pos位置的前驱，存入elem*/
template<class ElementType>
Status MyVector<ElementType>::Prior(int pos, ElementType &elem) {
	if (pos >= length || pos == 0) {
		return My_Range_Error;
	}
	else {
		elem = data[pos - 1];
		return My_Success;
	}
}

/*查找pos位置的后继，存入elem*/
template<class ElementType>
Status MyVector<ElementType>::next(int pos, ElementType &elem) {
	if (pos < 0 || pos >= length - 1) {
		return My_Range_Error;
	}
	else {
		elem = data[pos + 1];
		return My_Success;
	}
}

