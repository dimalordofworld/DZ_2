#pragma once
using namespace std;

class Man
{
public:
	Man();
	Man(string, string, int);
	string FullName();
	bool IsElector(int);
	~Man();
private:
	string Name;
	string SurName;
	int BirthYear;
};


