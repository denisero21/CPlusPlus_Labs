//---------------------------------------------------------------------------

#ifndef QueueH
#define QueueH
//---------------------------------------------------------------------------
#endif
#include "Node.h"

class queue
{
	node *head, *tail;

	public:

	queue()
	{
		tail = NULL;
		head = NULL;
	}

	void Add(project value);

	void Pop();

	void Peek(TListBox*ListBox);

};