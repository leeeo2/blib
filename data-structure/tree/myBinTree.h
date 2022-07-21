#pragma once
#include <vector>

/*二叉查找树*/

typedef _Node Node;

typedef struct _Node {
	int data;
	Node *parent;
	Node *lChild;
	Node *rChild;
}Node;

class myBinTree
{
public:
	myBinTree(std::vector<int> src);
	~myBinTree();

	/*生成二叉查找树*/
	void Init();

	/*插入节点*/
	void Insert(int data);

	/*查找节点*/
	Node* Search(int key);

	/*删除节点*/
	void Delete(int key);

private:
	std::vector<int> m_srcData;
	Node *m_root;
};

