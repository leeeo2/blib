#pragma once

/**
  *  双向链表模板类，提供模板元素的数组基本操作
  *  其中ElementType必须有拷贝构造方法、重构相等==运算符
**/

template<class ElementType>
struct Node {
	ElementType data;
	Node *prior;
	Node *next;
};

template<class ElementType>
class myDoubleLinkedList
{
public:
	myDoubleLinkedList();

	/*构造函数*/
	myDoubleLinkedList(ElementType elems[], int size);

	/*析构函数*/
	~myDoubleLinkedList();

	/*清空*/
	Status Clear();

	/*获取长度*/
	int Size();

	/*定位：返回pos的节点*/
	Status Locate(Node<ElementType>** ptr, int pos);

	/*按址查找*/
	Status At(int pos, ElementType &elem);

	/*按值查找*/
	Status Locate(const ElementType &elem, int &pos);

	/*插入*/
	Status Insert(const ElementType &elem, int pos);

	/*删除*/
	Status Delete(int pos);

	/*查找前驱*/
	Status Prior(int pos, ElementType &elem);

	/*查找后继*/
	Status Next(int pos, ElementType &elem);

private:
	Node *head;
};

