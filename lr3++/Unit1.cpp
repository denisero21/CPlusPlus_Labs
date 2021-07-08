//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
list Library;
bool d = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	try{
	   /*	for (int i = 0; i < Edit1->Text.Length(); i++) {
			if(Edit1->Text[i] < 48 || Edit1->Text[i] > 57)
				throw MFException('S');
		} */
		project NewAdd(StrToInt(Edit1->Text), Edit2->Text, Edit3->Text, StrToInt(Edit4->Text), Edit5->Text, StrToInt(Edit6->Text));
		Library.AddNote(NewAdd);
	}
	catch(EConvertError &e)
	{
		ShowMessage("Convert error, please try again.");
	}
	Memo1->Lines->Add("ID: " + Edit1->Text);
	Memo1->Lines->Add("Author: " + Edit2->Text);
	Memo1->Lines->Add("Title: " + Edit3->Text);
	Memo1->Lines->Add("Date: " + Edit4->Text);
	Memo1->Lines->Add("Publishing house: " + Edit5->Text);
	Memo1->Lines->Add("Amount of pages: " + Edit6->Text);
	Memo1->Lines->Add("");
	if (Edit1->Text != "" && !d) ComboBox1->Items->Add(Edit1->Text);
	d = false;
	Edit1->Clear();
	Edit2->Clear();
	Edit3->Clear();
	Edit4->Clear();
	Edit5->Clear();
	Edit6->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Library.GetNode(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Library.FindID(Memo1, Edit7);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Library.FindAuthor(Memo1, Edit8);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Library.FindBook(Memo1, Edit9, Edit10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Library.DeleteElement(ComboBox1, Memo1);
}
//---------------------------------------------------------------------------

