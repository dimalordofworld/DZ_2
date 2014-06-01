#include "stdafx.h"

Man::Man(string N, string S, int A)
{
	Name = N;
	SurName = S;
	BirthYear = A;
}

Man::Man(void)
{
	Name = "";
	SurName = "";
	BirthYear = 0;
}

Man::~Man(void)
{
}

string Man::FullName()
{
	
	if (SurName.length()==0) 
		return Name;
	if (Name.length()==0)
		return SurName;
	string tmp = " ";
	string FName = Name;
	FName += tmp;
	FName += SurName;
	return FName;
}

bool Man::IsElector(int A)
{
	if (BirthYear==0)
		return false;
	if (A-BirthYear>=18)
		return true;
	else
		return false;
}

