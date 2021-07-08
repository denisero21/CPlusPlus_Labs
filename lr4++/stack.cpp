//---------------------------------------------------------------------------

#pragma hdrstop

#include "stack.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Stack::Stack()
{
    size = 0;
	head = NULL;
}

void Stack::Insert(char a)
{
    if(!size)
    {
		head = new Node(a);
    }
    else
    {
		Node *temp = new Node(a);
		temp->ptrPrevious = head;
        head = temp;
    }
    size++;
}

void Stack::Delete()
{
    if(!size)
        return;
    Node* temp = head;
    head = head->ptrPrevious;
    delete temp;
    size--;

}

int Stack::Size()
{
    return size;
}

void Stack::Clear()
{
	for(int i = 0; i < size; i++)
	{
        this->Delete();
    }
}
