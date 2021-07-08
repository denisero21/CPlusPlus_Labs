//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

void list :: AddNote(project value)
{
		node *temp = new node;
		temp->data = value;
		temp->next = NULL;
		if(head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
}

void list :: GetNode(TMemo*Memo)
{
	Memo->Lines->Clear();
	node *temp = new node;
	temp = head;
	while(temp != NULL)
	{
		Memo->Lines->Add("ID: " + IntToStr(temp->data.ID));
		Memo->Lines->Add("Author: " + temp->data.Author);
		Memo->Lines->Add("Title: " + temp->data.Title);
		Memo->Lines->Add("Date: " + IntToStr(temp->data.Date));
		Memo->Lines->Add("Publishing house: " + temp->data.Publish);
		Memo->Lines->Add("Amount of pages: " + IntToStr(temp->data.AmountOfPages));
        Memo->Lines->Add("");
		temp = temp->next;
	}
}

void list :: InsertElement(int pos, project value)
{
	node *pre = new node;
	node *cur = new node;
	node *temp = new node;
	cur = head;
	for(int i = 1; i < pos; i++)
	{
	  pre = cur;
	  cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
}

void list :: DeleteElement(TComboBox*ComboBox, TMemo*Memo)
{
	bool c = false;
	if(ComboBox->ItemIndex == 0)
	{
		node *temp;
		temp = head;
		head = head->next;
		ComboBox->Items->Delete(0);
		Memo->Lines->Add("The book was deleted.");
		delete temp;
	}
	else{
		node *current;
		node *previous;
		current = head;

		if (current != NULL && !IntToStr(current->data.ID).Compare(ComboBox->Text))
		{
			current = current->next;
		}
		else
		{
			while (current != NULL && IntToStr(current->data.ID).Compare(ComboBox->Text)){
				previous = current;
				current = current->next;
				c = true;
			}
		}
	
		if(c)
		{
			Memo->Lines->Add("The book was deleted.");
			ComboBox->Items->Delete(ComboBox->ItemIndex);
		}

		previous->next = current->next;
	}
  }

void list :: FindID(TMemo*Memo, TEdit*Edit)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = new node;
	temp = head;

	while(temp != NULL){
		if(!(Edit->Text.Compare(temp->data.ID))){
			Memo->Lines->Add("Author: " + temp->data.Author);
			Memo->Lines->Add("Title: " + temp->data.Title);
			Memo->Lines->Add("Date: " + IntToStr(temp->data.Date));
			Memo->Lines->Add("Publishing house: " + temp->data.Publish);
			Memo->Lines->Add("Amount of pages: " + IntToStr(temp->data.AmountOfPages));
			c = true;
		}
		temp = temp->next;
	}

	if((temp == NULL) && (!c)){
		Memo->Lines->Add("The book isn't found.");
	}
	Edit->Clear();
}

void list :: FindAuthor(TMemo*Memo, TEdit*Edit)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = new node;
	temp = head;

	while(temp != NULL){
		if(!(Edit->Text.Compare(temp->data.Author))){
			Memo->Lines->Add("ID: " + IntToStr(temp->data.ID));
			Memo->Lines->Add("Title: " + temp->data.Title);
			Memo->Lines->Add("Date: " + IntToStr(temp->data.Date));
			Memo->Lines->Add("Publishing house: " + temp->data.Publish);
			Memo->Lines->Add("Amount of pages: " + IntToStr(temp->data.AmountOfPages));
			Memo->Lines->Add("");
			c = true;
		}
		temp = temp->next;
	}

	if((temp == NULL) && (!c)){
		Memo->Lines->Add("The author isn't found.");
	}
	Edit->Clear();
}

void list :: FindBook(TMemo*Memo, TEdit*Edit9, TEdit*Edit10)
{
	bool c = false;
	Memo->Lines->Clear();
	node *temp = new node;
	temp = head;

	while(temp != NULL){
		if((!(Edit9->Text.Compare(temp->data.Title))) && (!(Edit10->Text.Compare(temp->data.Date)))){
			Memo->Lines->Add("The book is exist.\n");
			Memo->Lines->Add("ID: " + IntToStr(temp->data.ID));
			Memo->Lines->Add("Title: " + temp->data.Title);
			Memo->Lines->Add("Publishing house: " + temp->data.Publish);
			Memo->Lines->Add("Amount of pages: " + IntToStr(temp->data.AmountOfPages));
			Memo->Lines->Add("");
			c = true;
		}
		temp = temp->next;
	}

	if((temp == NULL) && (!c)){
		Memo->Lines->Add("The book isn't found.");
	}
    Edit10->Clear();
	Edit9->Clear();
}


