//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
#include<vcl.h>
using namespace std;
//---------------------------------------------------------------------------


/*class MyException: public exception
{
	UnicodeString ErrorName;
	int ErrLine;
	UnicodeString ErrFile;

	public:

	MyException(UnicodeString Error, int Line, UnicodeString File) : exception(UnicodeString)
	{
		ErrorName = Error;
		ErrLine = Line;
		ErrFile = File;
	}

	const char*what()
	{
		ShowMessage(ErrorName + "Line: " + IntToStr(ErrLine) + "in" + ErrFile);
    }

};    */

class MFException : public Exception
{
	public:

	String s;
	MFException(String s) : Exception(s)
	{
		this->s = s;
	}

	void FError()
	{
        ShowMessage("TRY AGAIN");
    }
};
#endif
