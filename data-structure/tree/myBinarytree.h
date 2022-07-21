#pragma once

#include <vector>

typedef _Node Node;

typedef struct _Node {
	int data;
	Node *parent;
	Node *lChild;
	Node *rChild;
}Node;


class myBinarytree
{
public:
	myBinarytree(std::vector<int> src);
	~myBinarytree();

	//访问函数
	void print(int data);

	/*顺序存储*/
	//先序遍历
	void  PreOrder(int index);

	//中序遍历
	void InOrder(int index);

	//后续遍历
	void PostOrder(int index);

	//层次遍历（队列）
	void LevelOrder1();

	//非递归先序遍历（栈）
	void NRPreOrder();

	//非递归中序遍历（栈）
	void NRPreOrder();

	//非递归后序遍历（栈）
	void NRPreOrder();

	/***************************************************/

	/*链式存储*/
	//顺序存储转链式存储
	Node *link(Node* parent, int index);
	Node* linkStorage();

	//先序遍历
	void  PreOrder(Node *root);

	//中序遍历
	void InOrder(Node *root);

	//后续遍历
	void PostOrder(Node *root);

	//层次遍历
	void LevelOrder1();

	//非递归先序遍历（栈）
	void NRPreOrder();

	//非递归中序遍历（栈）
	void NRPreOrder();

	//非递归后序遍历（栈）
	void NRPreOrder(Node *root);

	/***************************************/
	//排序
	void Sort();


private:
	std::vector<int> m_srcData;  //源数据
	Node* m_root;
};

