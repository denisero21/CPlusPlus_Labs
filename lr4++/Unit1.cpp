//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

UnicodeString TForm1::InfToPost(UnicodeString inf)
{
	Stack symbols;
	UnicodeString result= "";
	for(int i = 1; i <= inf.Length(); i++)
	{
		if(inf[i] == ')')
		{
			while(symbols.head->Symbol() != '(')
			{
				result += symbols.head->Symbol();
				symbols.Delete();
			}
			symbols.Delete();
		}
		else if(inf[i] == '(')
		{
			symbols.Insert(inf[i]);
		}
		else if(inf[i] == '+' || inf[i] == '-' ||
		   inf[i] == '/' || inf[i] == '*')
		{
			if(symbols.head && (symbols.head->Symbol() == '*'
			|| symbols.head->Symbol() == '/'))
			{
				result += symbols.head->Symbol();
				//result.append(symbols.head->Symbol());
				symbols.Delete();
			}
			symbols.Insert(inf[i]);
		}
		else
		{
			result += inf[i];
		}
    }
    if(symbols.head)
    {
        result += symbols.head->Symbol();
		symbols.Delete();
    }
    return result;
}

float TForm1::Calc(UnicodeString post)
{
    float result = 0;
    float temp[100]{0};
    int counter = 0;
    Stack symbols;
	for(int i = 1; i <= post.Length(); i++)
	{
		if(post[i] != '+' && post[i] != '-'
				&& post[i] != '/' && post[i] != '*')
		{
			symbols.Insert(post[i]);
		}
		else
		{
			char x = symbols.head->Symbol();
			symbols.Delete();
			char y = symbols.head->Symbol();
			symbols.Delete();
			float x1 = 0, y1 = 0;
			switch (x)
			{
			case 'a': x1 = a;
				break;
			case 'b': x1 = b;
				break;
			case 'c': x1 = c;
				break;
			case 'd': x1 = d;
				break;
			case 'e': x1 = e;
				break;
			default: x1 = temp[x - '0'];
				break;
			}
			switch (y)
			{
			case 'a': y1 = a;
				break;
			case 'b': y1 = b;
				break;
			case 'c': y1 = c;
				break;
			case 'd': y1 = d;
				break;
			case 'e': y1 = e;
				break;
			default: y1 = temp[y - '0'];
				break;
			}
			switch (post[i])
			{
			case '+': temp[counter] = y1 + x1;
				break;
			case '-': temp[counter] = y1 - x1;
				break;
			case '*': temp[counter] = y1 * x1;
				break;
			case '/': temp[counter] = y1 / x1;
				break;
			}
			symbols.Insert(char(counter + '0'));
			counter++;
		}
	}
	result = temp[counter - 1];
	return result;
}

bool TForm1 :: IsCorrect(UnicodeString inf)
{
	int counter = 0;
	for(int i = 1; i <= inf.Length(); i++)
	{
		if(inf[i] != '+' && inf[i] != '-' && inf[i] != '/'
		&& inf[i] != '*' && inf[i] != '(' && inf[i] != ')'
	    && (inf[i] < 'a' || inf[i] > 'e'))
        {
			MessageDlg("Ucorrect expression.\nTryAgain.", mtError, mbOKCancel, 0);
            return false;
        }
        if(inf[i] == '(')
            counter++;
		else if(inf[i] == ')')
            counter--;
	}
    if(!counter)
		return true;
	MessageDlg("Ucorrect expression.\nTryAgain.", mtError, mbOKCancel, 0);
	return false;
}


bool TForm1 :: Input()
{
	try {
		this->a = StrToFloat(a_edit->Text);
		this->b = StrToFloat(b_edit->Text);
		this->c = StrToFloat(c_edit->Text);
		this->d = StrToFloat(d_edit->Text);
		this->e = StrToFloat(e_edit->Text);

	} catch (...) {
		a_edit->Clear();
		b_edit->Clear();
		c_edit->Clear();
		d_edit->Clear();
		e_edit->Clear();
		MessageDlg("Ucorrect input in VALUES.", mtError, mbOKCancel, 0);
		return false;
	}
	return true;
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    UnicodeString expression = ex_edit->Text;
	float result = 0;
	if(IsCorrect(expression) && Input())
	{
		expression = InfToPost(expression);
		resex_edit->Text = expression;
		result = Calc(expression);
        res_edit->Text = FloatToStr(result);
	}
}
//---------------------------------------------------------------------------

