#pragma once
#include <string>
using namespace std;

class Locatie 
{
private:
	string denumire;
	double nrMAXlocuri;
	double nrRanduri;
	int** locuri;

public:
	Locatie();
	Locatie(double nrRanduri,double nrMAXlocuri,int** locuri);
	Locatie(const Locatie& l);
	~Locatie();
};

