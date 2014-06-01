#include "stdafx.h"

string BaseError::GetError()
{
	return error;
}
	
BaseError::BaseError(string str)
{
	error = str;
}

BaseError::BaseError()
{
}



Street::Street(void)
{
	Name_Street = "";
	NumberStreet = 0;
}

Street::Street(string sName , int Num)
{
	Name_Street = sName;
	NumberStreet = Num;
}

Street::~Street(void)
{
}

int Street::GetNumberHome() const
{
	return ListHomes.size();
}

int Street::GetNumberMens() 
{
	int Count = 0;
	list<Home>::iterator i;
	for (i = ListHomes.begin(); i != ListHomes.end(); i++)
	{
		Count += i->getMenCount();
	}
	return Count;
}

string Street::GetNameStreet() const
{
	return Name_Street;
}

void Street::SetNameStreet(string sName)
{
	Name_Street = sName;
}

int Street::GetNumbStreet() const
{
	return NumberStreet;
}

bool Street::Has(const Home &s)
{
	list<Home>::iterator i;

	for ( i = ListHomes.begin(); i != ListHomes.end(); i++)
	{
		if  (s.getiHome() == i->getiHome())
			return true;
	}
	return false;
}

Home Street::Find(int iHome)
{
	list<Home>::iterator i;

	for ( i = ListHomes.begin(); i != ListHomes.end(); i++)
	{
		if (iHome == i->getiHome())
			return *i;
	}
	throw NotFoundException();
}

void Street::Delete(const Home &s)
{
	list<Home>::iterator i;

	for ( i = ListHomes.begin(); i != ListHomes.end(); i++)
	{
		if (s.getiHome() == i->getiHome())
			ListHomes.remove(s);
			return;
	}
	throw NotFoundException();
}

void Street::Append(const Home &s)
{
	if (Has(s))
		throw ValueExistException();
	ListHomes.insert(ListHomes.end(), s);
};
