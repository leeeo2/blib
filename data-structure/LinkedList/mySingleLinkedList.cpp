#include "pch.h"
#include "mySingleLinkedList.h"




/*构造函数*/
template <class ElementType>
MySingleLinkedList1<ElementType>::MySingleLinkedList1():head(nullptr) {}

/*构造函数*/
template <class ElementType>
MySingleLinkedList1<ElementType>::MySingleLinkedList1(ElementType elems[], int size) {
	for (int i = 0; i > size; i++) {
		Insert(elems[i], i);
	}
}

/*析构函数*/
template <class ElementType>
MySingleLinkedList1<ElementType>::~MySingleLinkedList1() {
	Clear();
}

/*清空*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::Clear() {
	Node<ElementType> *p = nullptr;
	while (head) {
		p = head->next;
		delete head;
		head=p;
	}
}

/*获取长度*/
template <class ElementType>
int MySingleLinkedList1<ElementType>::Size() {
	Node<ElementType> *p = head;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

/*定位：返回pos的节点*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::Locate(Node<ElementType>** ptr, int pos) {
	Node<ElementType> *p = head;
	int i = 0;
	while (p && i < pos) {
		i++;
		p = p->next;
	}
	if (i == pos) {
		*ptr = p;
		return My_Success;
	}
	return My_Range_Error;
}


/*按址查找*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::At(int pos, ElementType &elem) {
	Node<ElementType> *p = nullptr;

	Status status = Locate(&p, pos);
	if (status == My_Success) {
		elem = p->data;
	}
	return status;
}

/*按值查找*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::Locate(const ElementType &elem, int &pos) {
	Node<ElementType> *p = head;
	int i = 0;
	while (p) {
		if (p->data == elem) {
			pos = i;
			return My_Success;
		}
		i++;
	}
	return My_Range_Error;
}

/*插入*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::Insert(const ElementType &elem, int pos) {
	Node<ElementType> *p = nullptr;

	Status status = Locate(&p, pos - 1);
	Node<ElementType> *tmp = new Node<ElementType>;
	tmp->data = elem;
	if (status == My_Success) {
		tmp->next = p->next;
		p->next = tmp;
	}
	else if (pos == 0) {   //插入到头部的情况
		tmp->next = head ? head->next : nullptr;
		head = tmp;
	}
	return status;
}

/*删除*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::Delete(int pos) {
	Node<ElementType> *p = nullptr;
	Status status = Locate(&p, pos - 1) 
	if(status == My_Success){
		if (!p->next) {
			return My_Range_Error;
		}
		Node<ElementType> *tmp = p->next->next;
		delete p->next;
		p->next = tmp;
	}
	return status;
}

/*查找前驱*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::Prior(int pos, ElementType &elem) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(&tmp, pos - 1);
	if (status == My_Success) {
		elem = tmp->data;
	}
	return status;
}

/*查找后继*/
template <class ElementType>
Status MySingleLinkedList1<ElementType>::Next(int pos, ElementType &elem) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(&tmp, pos + 1);
	if (status == My_Success) {
		elem = tmp->data;
	}
	return status;
}








///////////////////////////////////////////////////////////////
/*构造函数*/
template<class ElementType>
MySingleLinkedList2<ElementType>::MySingleLinkedList2():data(nullptr),length(0) {}

/*构造函数*/
template<class ElementType>
MySingleLinkedList2<ElementType>::MySingleLinkedList2(ElementType elems[], int size) {
	for (int i = 0; i < size; i++) {
		Insert(elems[i], i);
	}
}

/*析构函数*/
template<class ElementType>
MySingleLinkedList2<ElementType>::~MySingleLinkedList2() {
	Clear();
}

/*清空*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::Clear() {
	Node<ElementType> *next = nullptr;
	while (head) {
		next = head->next;
		delete head;
		head = next;
	}
	return My_Success;
}

/*定位：返回pos的节点*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::Locate(Node<ElementType>** ptr, int pos) {
	if (!head || pos > length || pos < 0) {
		return My_Range_Error;
	}
	int i = 0;
	Node* tmp = head;
	while (i < pos) {
		i++;
		tmp = tmp->next;
	}
	*ptr = tmp;
	return My_Success;
}

/*按址查找*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::At(int pos, ElementType &elem) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(&tmp, pos);
	if (status == My_Success) {
		elem = tmp->data;
	}
	return status;
}

/*按值查找*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::Locate(const ElementType &elem, int &pos) {
	if (!head || pos > length) {
		return My_Range_Error;
	}

	Node *tmp = head;
	int i = 0;
	while (tmp) {
		if (tmp->data == elem) {
			pos = i;
			return My_Success;
		}
		i++;
		tmp = tmp->next;
	}
	return My_Range_Error;
}

/*插入*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::Insert(const ElementType &elem, int pos) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(&tmp, pos-1);

	Node<ElementType> *p = new Node<ElementType>;
	p->data = elem;

	if (status == My_Success) {
		p->next = tmp->next;
		tmp->next = p;
		length++;
	}
	else if(0 == pos){
		p->next = head ? head->next : nullptr;
		head = p;
	}
	return status;
}

/*删除*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::Delete(int pos) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(&tmp, pos - 1);
	if (status == My_Success) {
		if (!p->next) {
			return My_Range_Error;
		}
		Node<ElementType> *p = tmp->next->next;
		delete tmp->next;
		tmp->next = p;
	}
	return status;
}

/*查找前驱*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::Prior(int pos, ElementType &elem) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(tmp, pos - 1);
	if (status == My_Success) {
		elem = tmp->data;
	}
	return status;
}

/*查找后继*/
template<class ElementType>
Status MySingleLinkedList2<ElementType>::Next(int pos, ElementType &elem) {
	Node<ElementType> *tmp = nullptr;
	Status status = Locate(&tmp, pos + 1);
	if (status == My_Success) {
		elem = tmp->data;
	}
	return status;
}

