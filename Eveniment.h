#pragma once
#include <iostream>
#include <string>
using namespace std;

class Eveniment 
{
private:
	string data;
	string ora;
	char* denumire;

public:
	Eveniment();
	Eveniment(string data, string ora, const char* denumire);
	Eveniment(const Eveniment& e);
	~Eveniment();

	string getData();
	void setData(string data);
	string getOra();
	void setOra(string ora);
	char* getDenumire();
	void setDenumire(const char* denumire);

	friend istream& operator>>(istream& in, Eveniment& e);

	friend ostream& operator<<(ostream& out, const Eveniment e);

};
