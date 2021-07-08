//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Tree.h"
#include "Project.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Tree tree;
int count=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Book->Cells[0][0]= "Key";
	Book->Cells[1][0]= "Word";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PlusClick(TObject *Sender)
{
	Book->RowCount++;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CreateClick(TObject *Sender)
{
	try{
		if (tree.GetSize() == 0)
		{
			String word; int key;
			bool flag = false;
			for (int i = 1; i < Book->RowCount; i++) {
				for (int j = 0; j < 2; j++) {
					if (Book->Cells[j][i] == "") {
						flag = true;
					}
				}
				if (flag) break;
				key = StrToInt(Book->Cells[0][i]);
				word = Book->Cells[1][i];
				Project newWord(word,key);
				tree.Add(newWord);
			}
			count = tree.GetSize();
		}
	}catch(EConvertError &ex)
	{
		ShowMessage("Wrong key");
	}
	
}
//---------------------------------------------------------------------------


void __fastcall TForm1::AddClick(TObject *Sender)
{
	try{
		if (tree.GetSize() != 0)
		{
			String word; int key;
			bool flag = false;
			for (int i = count; i < Book->RowCount; i++) {
				for (int j = 0; j < 2; j++) {
					if (Book->Cells[j][i] == "") {
						flag = true;
					}
				}
				if (flag) break;
				key = StrToInt(Book->Cells[0][i]);
				word = Book->Cells[1][i];
				Project newWord(word,key);
				tree.Add(newWord);
			}
			count = tree.GetSize();
		}
	}catch(EConvertError &ex)
	{
		ShowMessage("Wrong key");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PrintClick(TObject *Sender)
{
	Board->Clear();
	Board->Lines->Add("PreOrder");
	tree.PreOrder();
	Board->Lines->Add("InOrder");
	tree.InOrder();
	Board->Lines->Add("PostOrder");
	tree.PostOrder();

	TreeView->Items->Clear();
	tree.PrintTreeView();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DeleteClick(TObject *Sender)
{
	tree.Remove(StrToInt(DSEdit->Text));
	for (int i = 1; i < Book->RowCount; i++) {
		if (Book->Cells[0][i] == DSEdit->Text) {
			if (i+1 != Book->RowCount) {
				for (int j = i+1; j < Book->RowCount; j++) {
					Book->Cells[0][i] = Book->Cells[0][j];
					Book->Cells[1][i] = Book->Cells[1][j];
					i=j;
				}
			}
			Book->Cells[0][i] = "";
			Book->Cells[1][i] = "";
			break;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SearchClick(TObject *Sender)
{
	Board->Clear();
	tree.Search(StrToInt(DSEdit->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TaskClick(TObject *Sender)
{
	Board->Clear();
	Board->Lines->Add(tree.GetNumOfNodes());
}
//---------------------------------------------------------------------------

