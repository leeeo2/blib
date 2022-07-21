#include "pch.h"
#include "myBinTree.h"


myBinTree::myBinTree(std::vector<int> src):m_srcData(src)
{
}


myBinTree::~myBinTree()
{
}

void myBinTree::Init()
{
	for (auto one : m_srcData) {
		Insert(one);
	}
}

void myBinTree::Insert(int data){
	Node *tmp = new Node;
	tmp->data = data;
	tmp->lChild = tmp->rChild = nullptr;
	
	if (!m_root) {
		m_root = tmp;
		return;
	}

	Node *p = m_root;

	//找叶子节点
	while (1) {
		if (data < p->data){
			if (p->lChild) {
				p = p->lChild;
			}
			else {
				break;
			}
		}
		else{
			if (p->rChild) {
				p = p->rChild;
			}
			else {
				break;
			}
		}
	}

	//插入
	if (data < p->data) {
		p->lChild = tmp;
	}
	else{
		p->rChild = tmp;
	}
}

/*查找节点*/
Node* myBinTree::Search(int key) {
	Node *p = m_root;
	while (p) {
		if (key == p->data) {
			return p;
		}
		else if (key < p->data) {
			p = p->lChild;
		}
		else if (key > p->data) {
			p = p->rChild;
		}
	}
	return nullptr;
}

void myBinTree::Delete(int key) {
	 
}