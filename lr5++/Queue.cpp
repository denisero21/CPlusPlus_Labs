//---------------------------------------------------------------------------

#pragma hdrstop

#include "Queue.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void queue :: Add(project value)
{
	node *temp = new node(value);
	if(head == NULL)
	{
		head = temp;
		tail = head;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void queue :: Pop()
{
	if(head == NULL)
		return;
	node *temp = head;
	head = head->next;
	delete head;
}

void queue :: Peek(TListBox*ListBox)
{
	node *temp = head;
}
