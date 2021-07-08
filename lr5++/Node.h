//---------------------------------------------------------------------------

#ifndef NodeH
#define NodeH
#include<vcl.h>
//---------------------------------------------------------------------------
#endif

class project
{
	public:
	UnicodeString string;

	project(UnicodeString a)
	{
		string = a;
	}

	project(){}

	UnicodeString GetString(){return string;}
};

struct node
{
	project data;
	node *next;
	node *prev;

	node(project d)
	{
		data = d;
		next = NULL;
		prev = NULL;
	}

	node(){ }

    ~node(){ }
};
