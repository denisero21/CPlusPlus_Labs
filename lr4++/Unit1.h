//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <vcl.h>
#include "stack.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *ex_edit;
	TEdit *resex_edit;
	TEdit *res_edit;
	TEdit *a_edit;
	TEdit *b_edit;
	TEdit *c_edit;
	TEdit *d_edit;
	TEdit *e_edit;
	TLabel *Label8;
	TLabel *Label9;
	TButton *Button2;
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
	float a, b, c, d, e;
    bool Input();
public:		// User declarations
	UnicodeString InfToPost(UnicodeString inf);
	float Calc(UnicodeString post);
	bool IsCorrect(UnicodeString inf);
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
