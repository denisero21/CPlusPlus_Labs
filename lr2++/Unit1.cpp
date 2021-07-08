//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int j = 0;
int c = 0;
int p;

Plankton *pl;




//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Form1->Memo1->Lines->Clear();
	Form1->Memo2->Lines->Clear();
}
//---------------------------------------------------------------------------

void GetNamePl(TMemo*Memo, TComboBox*ComboBox)
{

		for (int i = 0; i < j; i++)
		{
			if(!(ComboBox->Text.Compare(pl[i].NamePlankton)))
			{
				Memo->Lines->Add("Название проекта: "+pl[i].NameOfProject);
				Memo->Lines->Add("Описание проекта: "+pl[i].DescriptionOfProject);
				Memo->Lines->Add("Дата выдачи задания: "+pl[i].DateOfDeal);
				Memo->Lines->Add("Срок выполнения: "+pl[i].DateOfPass);
				Memo->Lines->Add("Дата сдачи задания: "+pl[i].DateOfRealPass);
				Memo->Lines->Add("\n");
			}
		}


}

void GetNameOffer(TMemo*Memo, TComboBox*ComboBox)
{

		for (int i = 0; i < j; i++)
		{
			if(!(ComboBox->Text.Compare(pl[i].NameOffer)))
			{
				Memo->Lines->Add("ФИО исполнителя: "+pl[i].NamePlankton);
				Memo->Lines->Add("Название проекта: "+pl[i].NameOfProject);
				Memo->Lines->Add("Описание проекта: "+pl[i].DescriptionOfProject);
				Memo->Lines->Add("Дата выдачи задания: "+pl[i].DateOfDeal);
				Memo->Lines->Add("Срок выполнения: "+pl[i].DateOfPass);
				Memo->Lines->Add("Дата сдачи задания: "+pl[i].DateOfRealPass);
				Memo->Lines->Add("\n");
			}
		}
}

void GetPlOfSameProject(TMemo*Memo, TComboBox*ComboBox)
{

		for (int i = 0; i < j; i++)
		{
			if(!(ComboBox->Text.Compare(pl[i].NameOfProject)))
			{
				Memo->Lines->Add("ФИО исполнителя: "+pl[i].NamePlankton);
				//Memo->Lines->Add("\n");
			}
		}
}

void GetOutProject(TMemo*Memo, TComboBox*ComboBox)
{
		Memo->Lines->Add("ФИО исполнителя: "+pl[ComboBox->ItemIndex].NamePlankton);
		Memo->Lines->Add("ФИО руководителя: "+pl[ComboBox->ItemIndex].NameOffer);
		Memo->Lines->Add("Описание проекта: "+pl[ComboBox->ItemIndex].DescriptionOfProject);
		Memo->Lines->Add("Дата выдачи задания: "+pl[ComboBox->ItemIndex].DateOfDeal);
		Memo->Lines->Add("Срок выполнения: "+pl[ComboBox->ItemIndex].DateOfPass);
		Memo->Lines->Add("Дата сдачи задания: "+pl[ComboBox->ItemIndex].DateOfRealPass);
		Memo->Lines->Add("\n");
}
//----------------------------------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if (j == 0)
		{
			pl = new Plankton[j + 1];
		}

		else
		{
			Plankton* plank = new Plankton[j + 1];
			for (int i = 0; i < j; i++) {
				plank[i] = pl[i];
			}
			delete[]pl;
			pl = plank;
		}

		pl[j].NamePlankton = Edit1->Text;
		pl[j].NameOffer = Edit2->Text;
		pl[j].NameOfProject = Edit6->Text;
		pl[j].DescriptionOfProject = Edit7->Text;
		pl[j].DateOfDeal = DateToStr(DateTimePicker1->Date);
		pl[j].DateOfPass = DateToStr(DateTimePicker2->Date);
		pl[j].DateOfRealPass = DateToStr(DateTimePicker3->Date);

		c = 0;
		bool a = true;
		if(j == 0) ComboBox1->Items->Add(pl[j].NamePlankton);
		else
		{
			for (int i = 0; i < j; i++){
				if(pl[j].NamePlankton.Compare(pl[i].NamePlankton)) a = true;
				else{a = false; break;}
			}
			if(a){
				ComboBox1->Items->Add(pl[j].NamePlankton);
				c++;
			}
		}

		c = 0;
		bool b = true;
		if(j == 0) ComboBox2->Items->Add(pl[j].NameOffer);
		else
		{
			for (int i = 0; i < j; i++){
				if(pl[j].NameOffer.Compare(pl[i].NameOffer)) b = true;
				else{b = false; break;}
			}
			if(b){
				ComboBox2->Items->Add(pl[j].NameOffer);
				c++;
			}
		}

		c = 0;
		bool d = true;
		if(j == 0) ComboBox3->Items->Add(pl[j].NameOfProject);
		else
		{
			for (int i = 0; i < j; i++){
				if(pl[j].NameOfProject.Compare(pl[i].NameOfProject)) d = true;
				else{d = false; break;}
			}
			if(d){
				ComboBox3->Items->Add(pl[j].NameOfProject);
				c++;
			}
		}

		if(StrToDate(pl[j].DateOfPass) > StrToDate(pl[j].DateOfRealPass)) ComboBox4->Items->Add(pl[j].NameOfProject);

		Memo1->Lines->Add(pl[j].NamePlankton);
		Memo1->Lines->Add(pl[j].NameOffer);
		Memo1->Lines->Add(pl[j].NameOfProject);
		Memo1->Lines->Add(pl[j].DescriptionOfProject);
		Memo1->Lines->Add(pl[j].DateOfDeal);
		Memo1->Lines->Add(pl[j].DateOfPass);
		Memo1->Lines->Add(pl[j].DateOfRealPass);

		Edit1->Clear();
		Edit2->Clear();
		Edit6->Clear();
		Edit7->Clear();
		j++;



}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	 if(FileSaveDialog1->Execute())
	 Memo1->Lines->SaveToFile(FileSaveDialog1->FileName);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
	OpenDialog1->Filter = "Text files (*.txt)|*.TXT";
	if(FileOpenDialog1->Execute())
	{
		TFileStream *tfile = new TFileStream(FileOpenDialog1->FileName,fmOpenReadWrite);
		TStringList *ts = new TStringList();

		ts -> LoadFromStream(tfile);

		for (int i = 0; i < ts->Count;)
		{
            if (j == 0){ pl = new Plankton[j + 1]; }
			else{
				Plankton* plank = new Plankton[j + 1];
				for (int i = 0; i < j; i++) {
					plank[i] = pl[i];
				}
				delete[]pl;
				pl = plank;
			}
			pl[j].NamePlankton = ts->Strings[i++];
			pl[j].NameOffer = ts->Strings[i++];
			pl[j].NameOfProject = ts->Strings[i++];
			pl[j].DescriptionOfProject = ts->Strings[i++];
			pl[j].DateOfDeal = StrToDate(ts->Strings[i++]);
			pl[j].DateOfPass = StrToDate(ts->Strings[i++]);
			pl[j].DateOfRealPass = StrToDate(ts->Strings[i++]);
			bool a = true;
			if(j == 0) ComboBox1->Items->Add(pl[j].NamePlankton);
			else
			{
				for (int i = 0; i < j; i++){
					if(pl[j].NamePlankton.Compare(pl[i].NamePlankton)) a = true;
					else{a = false;break;}
				}
				if(a){
					ComboBox1->Items->Add(pl[j].NamePlankton);
					c++;
				}
			}

			c = 0;
			bool b = true;
			if(j == 0) ComboBox2->Items->Add(pl[j].NameOffer);
			else
			{
				for (int i = 0; i < j; i++){
					if(pl[j].NameOffer.Compare(pl[i].NameOffer)) b = true;
					else{ b = false; break;}
				}
				if(b){
					ComboBox2->Items->Add(pl[j].NameOffer);
					c++;
				}
			}

			c = 0;
			bool d = true;
			if(j == 0) ComboBox3->Items->Add(pl[j].NameOfProject);
			else
			{
				for (int i = 0; i < j; i++){
					if(pl[j].NameOfProject.Compare(pl[i].NameOfProject)) d = true;
					else{d = false;break;}
				}
				if(d){
					ComboBox3->Items->Add(pl[j].NameOfProject);
					c++;
				}
			}

			if(StrToDate(pl[j].DateOfPass) > StrToDate(pl[j].DateOfRealPass)) ComboBox4->Items->Add(pl[j].NameOfProject);

			Memo1->Lines->Add(pl[j].NamePlankton);
			Memo1->Lines->Add(pl[j].NameOffer);
			Memo1->Lines->Add(pl[j].NameOfProject);
			Memo1->Lines->Add(pl[j].DescriptionOfProject);
			Memo1->Lines->Add(pl[j].DateOfDeal);
			Memo1->Lines->Add(pl[j].DateOfPass);
			Memo1->Lines->Add(pl[j].DateOfRealPass);
			j++;
		}
		delete tfile;
		delete ts;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int n = 0;
	while(ComboBox1->Text != pl[n].NamePlankton) {
		n++;
	}

	for (int i = 0; i < j; i++) {
		if(!pl[n].NameOffer.Compare(pl[i].NameOffer)) {ComboBox2->Items->Delete(i);}
		if(!pl[n].NameOfProject.Compare(pl[i].NameOfProject)){ComboBox3->Items->Delete(i);}
        if(!pl[n].NameOfProject.Compare(pl[i].NameOfProject)){ComboBox4->Items->Delete(i);}
	}
	ComboBox1->Items->Delete(n);

	for (int i = n+1; i < j; i++) {
		Plankton tmp = pl[i];
		pl[i] = pl[i-1];
		pl[i-1] = tmp;
	}

	j--;
	if (j < 0) {
		Memo1->Lines->Clear();
		Memo1->Lines->Add("There is no elements.");
	}
	else
	{
		Plankton *temp = new Plankton[j];
		temp = pl;
		pl = new Plankton[j];
		pl = temp;
	}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Memo2->Lines->Clear();
	for (int i = 0; i < j; i++)
	{
		if (!(ComboBox1->Text.Compare(pl[i].NamePlankton)))
		{
			GetNamePl(Memo2, ComboBox1);
			break;
		}
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo2->Lines->Clear();
	for (int i = 0; i < j; i++)
	{
		if (!(ComboBox2->Text.Compare(pl[i].NameOffer)))
		{
			GetNameOffer(Memo2, ComboBox2);
			break;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Memo2->Lines->Clear();
	for (int i = 0; i < j; i++)
	{
		if (!(ComboBox3->Text.Compare(pl[i].NameOfProject)))
		{
			GetPlOfSameProject(Memo2, ComboBox3);
			break;
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	Memo2->Lines->Clear();
	for (int i = 0; i < j; i++)
	{
		if (ComboBox4->ItemIndex == i)
		{
			GetOutProject(Memo2, ComboBox4);
		}
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	for (int i = 0; i < j; i++) {
		Memo1->Lines->Add(pl[i].NamePlankton);
		Memo1->Lines->Add(pl[i].NameOffer);
		Memo1->Lines->Add(pl[i].NameOfProject);
		Memo1->Lines->Add(pl[i].DescriptionOfProject);
		Memo1->Lines->Add(pl[i].DateOfDeal);
		Memo1->Lines->Add(pl[i].DateOfPass);
		Memo1->Lines->Add(pl[i].DateOfRealPass);
	}
}
//---------------------------------------------------------------------------

