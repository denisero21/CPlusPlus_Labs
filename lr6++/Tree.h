//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH
#include "Node.h"
#include "Main.h"

class Tree
{

	node *root;
	int size;
	int numOfNodes;

	public:

	Tree()
	{
		root = NULL;
		size = 0;
		numOfNodes = 0;
	}

	int GetSize() { return size; }

	void Add(Project value);

	node *Add(node *Node, Project value);

	void PreOrder();

	void PreOrder(node *Node);

	void InOrder();

	void InOrder(node *Node);

	void PostOrder();

	void PostOrder(node *Node);

	void Print(node *Node);

	void Search(int temp);

	void Search(node *Node, int temp);

	void Remove(int temp);

	node *Remove(node *Node, int temp1);

	int GetBFactor(node *Node);

	void UpdateHeight(node *nnode);

	node *Balance(node *nnode);

	node *RotateLeft(node *nnode);

	node *RotateRight(node *nnode);

	void Swap(node *node1, node *node2);

	int GetNumOfNodes();

	void GetNumOfNodes(node *nnode);

	void TreeView(node *nnode,int kl);

    void PrintTreeView();

	void DestroyTree(node *Node);

	~Tree()
	{
        DestroyTree(root);
    }
};

//---------------------------------------------------------------------------
#endif
