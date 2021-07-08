//---------------------------------------------------------------------------

#ifndef stackH
#define stackH
#include "node.h"
//---------------------------------------------------------------------------
class Stack
{
private:
    int size;
public:
	Node *head;
    Stack();
	void Insert(char a);
	void Delete();
    int Size();
	void Clear();
};
#endif
