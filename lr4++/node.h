//---------------------------------------------------------------------------

#ifndef nodeH
#define nodeH
//---------------------------------------------------------------------------
class Node
{
private:
	char symbol;
public:
	Node* ptrPrevious;
	Node(char x);
	//Node(){}
	char Symbol();
};
#endif

