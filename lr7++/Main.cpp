//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "HashTable.h"
#include "Task.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HashTable table(10);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	bool Check = false;
	int d;
	int m = 0;
	int repeat[20];
	for (int i = 0; i < 20; i++)
	{
		d = rand() % 40 + 1;
		for (int j = 0; j < 20; j++)
		{
			if(repeat[j] == d) Check = false;
			else Check = true;
		}
		if(Check)
		{
			table.Add(d);
			repeat[m] = d;
            m++;
		}
	}
	ListBox1->Items->SaveToFile("Sort.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AddClick(TObject *Sender)
{
	table.Add(StrToInt(Field->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
	table.Remove(StrToInt(Field->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchClick(TObject *Sender)
{
	Memo->Clear();
	int searching = table.Search(StrToInt(Field->Text));
	if(searching != ERROR)
		Memo->Lines->Add(searching);
	else
		Memo->Lines->Add("No matching");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PrintClick(TObject *Sender)
{
	Memo->Clear();
	table.Print();
	ListBox1->Items->SaveToFile("Sort.txt");

}
//---------------------------------------------------------------------------


void __fastcall TForm1::SortClick(TObject *Sender)
{
	table.Sort();
}
//---------------------------------------------------------------------------

