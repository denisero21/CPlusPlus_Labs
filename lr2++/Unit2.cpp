//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
#include<stdlib.h>
#include<wchar.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Plankton::Plankton()
{
	this->NamePlankton = "";
	this->NameOffer = "";
	this->NameOfProject = "";
	this->DescriptionOfProject = "";
	this->DateOfDeal = "";
	this->DateOfPass = "";
	this->DateOfRealPass = "";
}

Plankton::Plankton(UnicodeString a, UnicodeString b, UnicodeString c, UnicodeString d, UnicodeString e, UnicodeString f, UnicodeString g)
{
	this->NamePlankton = a;
	this->NameOffer = b;
	this->NameOfProject = c;
	this->DescriptionOfProject = d;
	this->DateOfDeal = e;
	this->DateOfPass = f;
	this->DateOfRealPass = g;
}

int Plankton::GetDay(UnicodeString DateOfPass, UnicodeString DateOfRealPass)
{
	int TotalDatePass, TotalDateRealPass;
	int YearPass;
	int MonthPass;
	int DayPass;
	int YearRealPass;
	int MonthRealPass;
	int DayRealPass;

	for (int i = 6, j = 3; i < 10; i++, j--) {
		YearPass += (DateOfPass[i]-48) * std::pow(10, j);
		YearRealPass += (DateOfRealPass[i]-48) * std::pow(10, j);
	}

	for (int i = 4, j = 2; i < 6; i++, j--)
	{
		MonthPass += (DateOfPass[i]-48) * std::pow(10, j);
		MonthRealPass += (DateOfRealPass[i]-48) * std::pow(10, j);
	}

	for (int i = 0, j = 2; i < 2; i++, j--) {
		DayPass += (DateOfPass[i]-48) * std::pow(10, j);
		DayRealPass += (DateOfRealPass[i]-48) * std::pow(10, j);
	}

	TotalDatePass = 365 * YearPass + 30 * MonthPass + DayPass;
	TotalDateRealPass = 365 * YearRealPass + 30 * MonthRealPass + DayRealPass;

    return TotalDatePass - TotalDateRealPass;
}
