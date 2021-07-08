//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
#endif
#include "Queue.h"


class List : public queue
{
	private:

	node *head, *tail;

	public:
	List()
	{
		head = tail;
		tail = head;
	}

	void AddNote(TFileOpenDialog*FileOpenDialog, TListBox*ListBox);

	void GetNode(TMemo*Memo);

	void DeleteElement(int pos = 0);

	void Scroll(TMemo*Memo, int &pos);

	void Peek(TListBox*ListBox);

};