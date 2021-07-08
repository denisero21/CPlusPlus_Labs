//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include<vcl.h>
#include "Unit3.h"
//---------------------------------------------------------------------------
#endif


class project{
	public:

    int ID;
	UnicodeString Author;
	UnicodeString Title;
	int Date;
	UnicodeString Publish;
	int AmountOfPages;

	project(int ID, UnicodeString Author,UnicodeString Title, int Date, UnicodeString Publish, int AmountOfPages){
		this->ID = ID;
		this->Author = Author;
		this->Title = Title;
		this->Date = Date;
		this->Publish = Publish;
		this->AmountOfPages = AmountOfPages;
	}

	project(){}


};

class list
	{

		private:

		struct node{

            project data;
			node *next;

		};

		node *head, *tail;

		public:
		list(){
			head = NULL;
			tail = NULL;
		}

		void AddNote(project value);

		void GetNode(TMemo*Memo);

		void InsertElement(int pos, project value);

		void DeleteElement(TComboBox*ComboBox, TMemo*Memo);

		void FindID(TMemo*Memo, TEdit*Edit);

		void FindAuthor(TMemo*Memo, TEdit*Edit);

		void FindBook(TMemo*Memo, TEdit*Edit9, TEdit*Edit10);

	};