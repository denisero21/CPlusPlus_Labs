//---------------------------------------------------------------------------

#ifndef NodeH
#define NodeH
#include "Project.h"

class node
{
	node *left;
	node *right;
	Project data;
	int height;

	public:

	node(Project data)
	{
		this->left = NULL;
		this->right = NULL;
		this->data = data;
		height = 0;
	}

	node(){}

	void SetLeft(node *left) { this->left = left; }

	void SetRight(node *right) { this->right = right; }

	void SetData(Project data) { this->data = data; }

	node *GetLeft() { return left; }

    Project GetData() { return data; }

	node *GetRight() { return right; }

	int GetHeight() { return height; }

    void SetHeight(int height) { this->height = height; }
};
//---------------------------------------------------------------------------
#endif
