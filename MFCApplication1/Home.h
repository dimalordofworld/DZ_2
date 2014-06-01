#pragma once
//#include "stdafx.h"
using namespace std;

class Home
{
public:
	Home(void);
	~Home(void);
	Home (const Home & pH);
	Home(string HomNum, int iH);											  // Создание дома с симв. номером 
	Home(string HomNum, int iH, int Etag, int NumbA);			// Создание дома со всеми параметрами

	string getHomeNum();
	int getiHome() const;
	void setiHome(int iH);
	int getEtagCount() const;
	void setEtagCount(int Etag);	
	int getMenCount() const;	
	void getParam (string HomNum, int & iH, int & Etag, int & NumbA);
	void setAllParam (string HomNum, int iH, int Etag, int NumbA);

	void AddMan(const Man &s);

	bool GetNext(Man &m);
	void StartIterator();

	Home operator + (Man A);
	bool operator == (const Home &s);
	Home operator = (Home &s);

private:
	list<Man>::iterator Iter;
	string Home_Number;
	int iHome;
	int EtagCount;
	int NumbApartment;
	list<Man> MenList;
};

