//---------------------------------------------------------------------------

#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Tree :: Add(Project value)
	{
		if (!root)
		{
			root = new node(value);
			size++;
			return;
		}
		else if (value.GetKey() < root->GetData().GetKey())
		{
			root->SetLeft(Add(root->GetLeft(), value));
		}
		else if (value.GetKey() > root->GetData().GetKey())
		{
			root->SetRight(Add(root->GetRight(), value));
		}
		UpdateHeight(root);
		root = Balance(root);
	}

	node* Tree :: Add(node *Node, Project value)
	{
		if (!Node)
		{
			node *temp = new node(value);
			size++;
			return temp;
		}
		else if (value.GetKey() < Node->GetData().GetKey())
		{
			Node->SetLeft(Add(Node->GetLeft(), value));
		}
		else if (value.GetKey() > Node->GetData().GetKey())
		{
			Node->SetRight(Add(Node->GetRight(), value));
		}
		UpdateHeight(Node);
		return Balance(Node);
	}

	void Tree :: PreOrder()
	{
		if (!root)
			return;

		Print(root);
		PreOrder(root->GetLeft());
		PreOrder(root->GetRight());
	}

	void Tree :: PreOrder(node *Node)
	{
		if (!Node)
			return;

		Print(Node);
		PreOrder(Node->GetLeft());
		PreOrder(Node->GetRight());
	}

	void Tree :: InOrder()
	{
		if (!root)
			return;

		InOrder(root->GetLeft());
		Print(root);
		InOrder(root->GetRight());
	}

	void Tree :: InOrder(node *Node)
	{
		if (!Node)
			return;

		InOrder(Node->GetLeft());
		Print(Node);
		InOrder(Node->GetRight());
	}

	void Tree :: PostOrder()
	{
		if (!root)
			return;

		PostOrder(root->GetLeft());
		PostOrder(root->GetRight());
		Print(root);
	}

	void Tree :: PostOrder(node *Node)
	{
		if (!Node)
			return;

		PostOrder(Node->GetLeft());
		PostOrder(Node->GetRight());
		Print(Node);
	}

	void Tree :: Print(node *Node)
	{
		Form1->Board->Lines->Add(Node->GetData().GetWord()+ "," +
								 IntToStr(Node->GetData().GetKey()) + "; ");
	}

//	void PrintTree(Node* node){
//		bool flag = true;
//		if (flag) {
//			Form1->TreeView->Items->AddChildFirst(node,node->GetData().GetWord());
//			flag = false;
//		}
//		else
//		{
//			Form1->TreeView->Items->AddChild(node,node->GetData().GetWord());
//        }
//
//	}


	void Tree :: Search(int temp)
	{
		if (!root)
			return;

		if (temp == root->GetData().GetKey())
		{
			Print(root);
			return;
		}
		if (temp < root->GetData().GetKey())
		{
			Search(root->GetLeft(), temp);
		}
		else if (temp > root->GetData().GetKey())
		{
			Search(root->GetRight(), temp);
		}
		return;
	}

	void Tree :: Search(node *Node, int temp)
	{
		if (!Node)
			return;
		if (temp == Node->GetData().GetKey())
		{
			Print(Node);
			return;
		}
		if (temp < Node->GetData().GetKey())
		{
			Search(Node->GetLeft(), temp);
		}
		else if (temp > Node->GetData().GetKey())
		{
			Search(Node->GetRight(), temp);
		}
		return;
	}

	void Tree :: Remove(int temp)
	{
		if (!root)
			return;
		if (temp == root->GetData().GetKey())
		{
			Remove(root, temp);
			return;
		}
		if (temp < root->GetData().GetKey())
		{
			root->SetLeft(Remove(root->GetLeft(), temp));
		}
		else if (temp > root->GetData().GetKey())
		{
			root->SetRight(Remove(root->GetRight(), temp));
		}

	}

	node* Tree :: Remove(node *Node, int temp1)
	{
		if (!Node)
			return NULL;
		if (temp1 < Node->GetData().GetKey())
		{
			Node->SetLeft(Remove(Node->GetLeft(), temp1));
		}
		else if (temp1 > Node->GetData().GetKey())
		{
			Node->SetRight(Remove(Node->GetRight(), temp1));
		}
		else
		{
			size--;
			if (!Node->GetLeft() && !Node->GetRight())
			{
				Node == root ? DestroyTree(root) : delete Node;
				return NULL;
			}
			else if (!Node->GetLeft())
			{
				node *temp = Node->GetRight();
				Node == root ? root = Node->GetRight() : Node;
				delete Node;
				return temp;
			}
			else if (!Node->GetRight())
			{
				node *temp = Node->GetLeft();
				Node == root ? root = root->GetLeft() : Node;
				delete Node;
				return temp;
			}
			else
			{
				node *temp = Node->GetRight();
				node *toDelete = Node;
				while (temp->GetLeft())
                {
					toDelete = temp;
                    temp = temp->GetLeft();
                }
				Swap(Node, temp);
				if (toDelete->GetLeft() == temp)
                {
					toDelete->SetLeft(NULL);
                }
				else
                {
					toDelete->SetRight(NULL);
                }
				delete temp;
				return Node;
            }
		}
		return Node;
	}

	int Tree :: GetBFactor(node *Node)
	{
		int Left;// =  ? node->GetLeft()->GetHeight() : 0;
		if (Node->GetLeft())
		{
			Left = Node->GetLeft()->GetHeight() + 1;
        }
        else
        {
			Left = 0;
        }
		int Right;// = node->GetRight() ? node->GetRight()->GetHeight() : 0;
		if (Node->GetRight())
        {
			Right = Node->GetRight()->GetHeight() + 1;
		}
        else
        {
			Right = 0;
        }
		return Right - Left;
	}

	void Tree :: UpdateHeight(node *nnode)
	{
		int hLeft = nnode->GetLeft() ? nnode->GetLeft()->GetHeight() : 0;
		int hRight = nnode->GetRight() ? nnode->GetRight()->GetHeight() : 0;
		int height = (hLeft > hRight ? hLeft : hRight) + 1;
		nnode->SetHeight(height);
    }

	node* Tree :: Balance(node *nnode)
	{
		if (GetBFactor(nnode) == 2)
		{
			if (GetBFactor(nnode->GetRight()) < 0)
			{
				nnode->SetRight(RotateLeft(nnode->GetRight()));
            }
			return RotateLeft(nnode);
        }
		if (GetBFactor(nnode) == -2)
		{
			if (GetBFactor(nnode->GetLeft()) > 0)
            {
				nnode->SetLeft(RotateRight(nnode->GetLeft()));
			}
			return RotateRight(nnode);
		}
		return nnode;
    }

	node* Tree :: RotateLeft(node *nnode)
	{
		node *newRoot = nnode->GetRight();
		nnode->SetRight(newRoot->GetLeft());
		newRoot->SetLeft(nnode);
		return newRoot;
    }

	node* Tree :: RotateRight(node *nnode)
	{
		node *newRoot = nnode->GetLeft();
		nnode->SetLeft(newRoot->GetRight());
		newRoot->SetRight(nnode);
		return newRoot;
	}

	void Tree :: Swap(node *node1, node *node2)
	{
		Project temp = node1->GetData();
		node1->SetData(node2->GetData());
		node2->SetData(temp);
	}

	int Tree :: GetNumOfNodes()
	{
		numOfNodes = 0;
		GetNumOfNodes(root->GetLeft());
		GetNumOfNodes(root->GetRight());
		return this->numOfNodes;
    }

	void Tree :: GetNumOfNodes(node *nnode)
	{
		if (!nnode)
			return;
		if((nnode->GetLeft() != NULL && nnode->GetRight() == NULL)||(nnode->GetLeft() == NULL && nnode->GetRight() != NULL))
			this->numOfNodes++;
		else if(nnode->GetLeft() == NULL && nnode->GetRight() == NULL)
            return;
		else
		{
			GetNumOfNodes(nnode->GetLeft());
			GetNumOfNodes(nnode->GetRight());
		}
	}

	void Tree :: DestroyTree(node *Node)
	{
		if (!Node)
			return;
		DestroyTree(Node->GetLeft());
		DestroyTree(Node->GetRight());
		delete Node;
		root = NULL;
		size = 0;
	}

	void Tree :: PrintTreeView()
	{
		TreeView(root,-1);
	}

	void Tree :: TreeView(node *nnode,int kl)
	{
		if (!nnode)
			return;
		if (kl == -1)
		{
			Form1->TreeView->Items->AddFirst(nullptr,IntToStr(nnode->GetData().GetKey()) + "," + nnode->GetData().GetWord());
		}
		else
		{
			Form1->TreeView->Items->AddChildFirst(Form1->TreeView->Items->Item[kl],IntToStr(nnode->GetData().GetKey()) + "," + nnode->GetData().GetWord());
		}
		kl++;
		TreeView(nnode->GetLeft(),kl);
		TreeView(nnode->GetRight(),kl);
		kl--;
    }
