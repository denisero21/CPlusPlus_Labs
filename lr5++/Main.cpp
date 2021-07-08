//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
List list;
int pos = 0;
bool tr = false;
bool q = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
	Form1->Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    list.AddNote(FileOpenDialog1, ListBox1);
	q = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if(!q) MessageDlg("Push the button \"Create queue\" please.", mtError, mbOKCancel, 0);
	else
	{
		pos = 0;
		tr = true;
		list.GetNode(Memo1);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(!tr) MessageDlg("Push the button \"Print\" please.", mtError, mbOKCancel, 0);
	else
	{
		pos++;
		list.Scroll(Memo1, pos);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PopClick(TObject *Sender)
{
	list.DeleteElement(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PeekClick(TObject *Sender)
{
	list.Peek(ListBox1);
}
//---------------------------------------------------------------------------

