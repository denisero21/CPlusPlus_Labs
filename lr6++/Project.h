//---------------------------------------------------------------------------

#ifndef ProjectH
#define ProjectH

class Project
{

	UnicodeString Word;
	int Key;

	public:

	Project(UnicodeString word,int key)
	{
		this->Word = word;
		this->Key = key;
	}

	Project(){}

	int GetKey() {return Key; }
    UnicodeString GetWord() {return Word; }
};
//---------------------------------------------------------------------------
#endif
