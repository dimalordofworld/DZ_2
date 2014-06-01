#pragma once
#include "stdafx.h"
using namespace std;

class BaseError
{
private:
	string error;
public:
	virtual string GetError();
	BaseError(string str);
	BaseError();
};

class Street
{
public:
	Street(void);
	Street(string sName , int Num);
	Street(Street & S);

	~Street(void);

	bool Has(const Home &s);
	Home Find(int iHome);
	void Append(const Home &s);
	void Delete(const Home &s);
	
	int GetNumberHome() const;
	
	int GetNumberMens();
	
	string GetNameStreet() const;
	void SetNameStreet(string sName);
	
	int GetNumbStreet() const;
	void SetNumbStreet(int Num);

	class ValueExistException : public BaseError 
	{
	public:
		ValueExistException()
		{
			BaseError("Such element already exists");
		}
	};
	class NotFoundException  : public BaseError 
	{
	public:
		NotFoundException()
		{
			BaseError("Such element don't exists");
		}
	};

private:
	string Name_Street;
	int NumberStreet;
	list<Home> ListHomes;
	Home* List;
};



