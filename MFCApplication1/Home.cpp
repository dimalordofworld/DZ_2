#include "stdafx.h"

Home::Home(string HomNum, int iH, int Etag, int NumbA)
{
	Home_Number = HomNum;
	iHome = iH;
	EtagCount = Etag;
	NumbApartment = NumbA;
}

Home::Home(string HomNum, int iH)
{
	Home_Number = HomNum;
	iHome = iH;
	EtagCount = 0;
	NumbApartment = 0;
}

Home::Home (const Home & pH)
{
	Home_Number = pH.Home_Number;
	iHome = pH.iHome;
	EtagCount = pH.EtagCount;
	NumbApartment = pH.NumbApartment;

	list<Man> a = pH.MenList;
	list<Man>::iterator It = a.begin();
	do
	{
		MenList.push_back(*It);
		It++;
	}
	while (It != a.end());
}

Home::Home(void)
{
	Home_Number = "";
	iHome = 0;
	EtagCount = 0;
	NumbApartment = 0;
}

Home::~Home(void)
{
}

int Home::getiHome() const
{
	return iHome;
}

void Home::setiHome(int iH)
{
	iHome = iH;
}

int Home::getEtagCount() const
{
	return EtagCount;
}

void Home::setEtagCount(int Etag)
{
	EtagCount = Etag;
}

int Home::getMenCount() const
{
	return MenList.size();
}

void Home::getParam (string HomNum, int & iH, int & Etag, int & NumbA)
{
	HomNum = Home_Number;
	iH = iHome;
	Etag = EtagCount;
	NumbA = NumbApartment;
}

void Home::setAllParam (string HomNum, int iH, int Etag, int NumbA)
{
	Home_Number = HomNum;
	iHome = iH;
	EtagCount = Etag;
	NumbApartment = NumbA;
	/*
	cout << "\nSimvol doma: ";
	cin >> HomNum;
	cout << "\nNomer doma: ";
	cin >> iH;
	cout << "\nKolichestvo Itagei: ";
	cin >> Etag;
	cout << ".\nKolichestvo gitelei: ";
	cin >> Men;
	cout << "\nKolichestvo kvartir a dome: ";
	cin >> NumbA;
	*/
}

void Home::AddMan(const Man &s)
{
	MenList.insert(MenList.end(), s);
};

bool Home::operator == (const Home &s)
{
	if (iHome == s.getiHome())
		return true;
	return false;
}

Home  Home::operator = (Home &s)
{
	return Home(s);
}

void operator + (list<Man> &Ma, const Man &M)
{						
	Ma.push_back(M);
};

bool Home::GetNext(Man &m)
{
	if (Iter == MenList.end())
		return false;
	m = *Iter;
	Iter++;
	return true;
};

void Home::StartIterator()
{
	Iter = MenList.begin();
};