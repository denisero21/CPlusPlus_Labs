//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#endif

class Plankton
{
	public:
	UnicodeString NamePlankton;
	UnicodeString NameOffer;
	UnicodeString NameOfProject;
	UnicodeString DescriptionOfProject;
	UnicodeString DateOfDeal;
	UnicodeString DateOfPass;
	UnicodeString DateOfRealPass;
    UnicodeString Space;
	int GetDay(UnicodeString DateOfPass, UnicodeString DateOfRealPass);
	Plankton();
	Plankton(UnicodeString a, UnicodeString b, UnicodeString c, UnicodeString d, UnicodeString e, UnicodeString f, UnicodeString g);


};
