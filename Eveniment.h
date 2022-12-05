#pragma once
#include <string>
using namespace std;

class Eveniment 
{
private:
	const string data;
	const string ora;
	char* denumire;

public:
	Eveniment();
	Eveniment(string data, string ora, char* denumire);
	Eveniment(const Eveniment& e);
	~Eveniment();

	string getData();
	string getOra();
	char* getDenumire();
	void setDenumire(const char* denumire);
};
