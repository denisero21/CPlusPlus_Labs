//---------------------------------------------------------------------------

#ifndef HashTableH
#define HashTableH

#include <List.h>
#include "Main.h"


class HashTable {
protected:
	int size;
	int count;
	List* table;
public:
	HashTable(int size) {
		this->size = size;
		table = new List[size];
		count = 0;
	}

	int GetSize(){return size;}

	void Add(int data) {
		int key = GetHashKey(data);
		if (!table[key].Search(data))
		{
			table[key].Push(data);
		}
	}

	void Remove(int data) {
		int key = GetHashKey(data);
		table[key].RemoveById(data);
	}

	int Search(int data) {
		int key = GetHashKey(data);
		if (table[key].Search(data))
		{
			return table[key].Search(data)->data;
		}
		else
		{
			return -8321341;
		}
	}

	int GetHashKey(int data) {
		int fKey = size;
		return data % fKey;
	}

	int GetPrimeNumber(int size) {
		if (size > 3)
		{
			do
			{
				size--;
			} while ((size * size) % 24 != 1 && size > 3);
		}
		return size;
	}

	void Print() {
        Form1->ListBox1->Clear();
		for (int i = 0; i < size; i++)
		{
			for (int j = 1; j <= table[i].GetSize(); j++)
			{
				Form1->Memo->Lines->Strings[Form1->Memo->Lines->Count-1] += IntToStr(table[i].Pick(j)) + " ";
				Form1->ListBox1->Items->Add(IntToStr(table[i].Pick(j)));
				if (j == table[i].GetSize())
					Form1->Memo->Lines->Add("");
			}
		}
	}

    void DeleteKeys(int k1)
	{
		table[GetHashKey(k1)].RemoveById(k1);
	}

	~HashTable() {
		delete[]table;
	}

	void Sort()
	{
		TFileStream *tfile = new TFileStream("Sort.txt",fmOpenReadWrite);
		TStringList *ts = new TStringList();
		ts -> LoadFromStream(tfile);

		int Out[ts->Count];
		for (int i = 0; i < ts->Count; i++)
		{
			Out[i] = StrToInt(ts->Strings[i]);
		}

		for (int i = 0; i < ts->Count-1; i++)
		{
			for (int j = i+1; j < ts->Count; j++)
			{
				if(Out[i] > Out[j])
				{
					int b = Out[j];
					Out[j] = Out[i];
					Out[i] = b;
                }
			}
		}

		Form1->Memo->Lines->Clear();
		for (int i = 0; i < ts->Count; i++) {
			Form1->Memo->Lines->Add(Out[i]);
		}

		delete tfile;
		delete ts;
	}



};

//---------------------------------------------------------------------------
#endif
