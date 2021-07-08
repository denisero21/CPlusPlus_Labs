//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void List :: AddNote(TFileOpenDialog*FileOpenDialog, TListBox*ListBox)
{
	if(FileOpenDialog->Execute())
	{
		TFileStream *tfile = new TFileStream(FileOpenDialog->FileName,fmOpenReadWrite);
		TStringList *ts = new TStringList();

		ts -> LoadFromStream(tfile);

		for (int i = 0; i < ts->Count; i++)
		{
			node *temp = new node(ts->Strings[i]);
			ListBox->Items->Add(ts->Strings[i]);

			if(head == NULL)
			{
				head = temp;
				tail = head;
				temp->next = head;
				temp->prev = tail;
			}
			else
			{
				temp->prev = tail;
				temp->next = head;
				tail->next = temp;
				tail = tail->next;
			}
		}
	}
}

void List :: GetNode(TMemo*Memo)
{
	Memo->Lines->Clear();
	bool c = false;
	node *temp;
	temp = head;
	while(temp != tail)
	{
		Memo->Lines->Add(temp->data.string);
		temp = temp->next;
		c = true;
	}
	if(c)
	{
		Memo->Lines->Add(temp->data.string);
	}
}

void List :: DeleteElement(int pos)
{
	node *temp = head;
	node *ptr;
	for (int i = 1; i < pos; i++) {
		temp = temp->next;
	}
	if (temp == head)
	{
		queue::Pop();

		head = head->next;
		delete head->prev;
		temp->prev= tail;
	}
	else if(temp == tail)
	{
		temp->prev->next = nullptr;
	}
	else
	{
		ptr = temp->next;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		temp = ptr;
	}
}

void List :: Scroll(TMemo*Memo, int &pos)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp;
	node *prev1;
	temp = tail;
	temp = temp->next;
	for (int i = 0; i < pos; i++)
	{
		prev1 = temp;
		temp = temp->next;

	}
	while(temp != prev1)
	{
		Memo->Lines->Add(temp->data.string);
		temp = temp->next;
		c = true;
	}
	if(c)
	{
		Memo->Lines->Add(temp->data.string);
	}
}

void List :: Peek(TListBox*ListBox)
{
	queue::Peek(ListBox);
    ListBox->Items->Add(head->data.string);
}
