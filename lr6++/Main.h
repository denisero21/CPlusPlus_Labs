//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *Book;
	TButton *Add;
	TTreeView *TreeView;
	TButton *Create;
	TButton *Plus;
	TButton *Print;
	TMemo *Board;
	TButton *Delete;
	TEdit *DSEdit;
	TButton *Search;
	TButton *Task;
	void __fastcall PlusClick(TObject *Sender);
	void __fastcall CreateClick(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall PrintClick(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
	void __fastcall SearchClick(TObject *Sender);
	void __fastcall TaskClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
