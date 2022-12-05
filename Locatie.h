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

	string getDenumire();
	void setDenumire(string denumire);
	double getNrMAXlocuri();
	void setNrMAXlocuri(double nrMAXlocuri);
	double getNrRanduri();
	void setNrRanduri(double nrRanduri);
	int** getLocuri();
	void setLocuri(int** locuri,double nrRanduri,double nrColoane);
};

