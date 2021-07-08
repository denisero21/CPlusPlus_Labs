//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo;
	TButton *Add;
	TButton *Delete;
	TButton *Search;
	TEdit *Field;
	TButton *Print;
	TButton *Sort;
	TFileSaveDialog *FileSaveDialog1;
	TFileOpenDialog *FileOpenDialog1;
	TListBox *ListBox1;
	void __fastcall AddClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall PrintClick(TObject *Sender);
	void __fastcall SortClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	void clear()
	{
		TFileStream *tfile = new TFileStream("Sort.txt",fmOpenWrite);
		TStringList *ts = new TStringList();
		ts -> LoadFromStream(tfile);

		for (int i = 0; i < ts->Count; i++)
		{
			ts->Strings[i] = "";
		}

		delete tfile;
		delete ts;
	}
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
