#pragma once

#include "define.h"

/**
  *  单链表模板类，提供模板元素的数组基本操作
  *  其中ElementType必须有拷贝构造方法、重构相等==运算符
**/

template<class ElementType>
struct Node {
	ElementType data;
	Node *next;
};

//第一个版本，不带length的版本
template<class ElementType>
class MySingleLinkedList1
{
public:
	/*构造函数*/
	MySingleLinkedList1();

	/*构造函数*/
	MySingleLinkedList1(ElementType elems[], int size);

	/*析构函数*/
	~MySingleLinkedList1();

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



//第二个版本，带length的
//在纯C语言实现的单链表中，由于只用一个头指针表示链表
//没有办法加长度(其实也是可以的,用结构体封装一层就行了，
//不知道为什么教科书上都没有这种说法），实现起来确实有点憋足，在这里就体现出了
//面向对象的优越性，两个版本对比一下

template<class ElementType>
class MySingleLinkedList2
{
public:
	/*构造函数*/
	MySingleLinkedList2();

	/*构造函数*/
	MySingleLinkedList2(ElementType elems[], int size);

	/*析构函数*/
	~MySingleLinkedList2();

	/*清空*/
	Status Clear();

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

