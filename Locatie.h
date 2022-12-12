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
	Locatie();															//constructor implicit

	Locatie(double nrRanduri, double nrMAXlocuri, int** locuri);	    //constructor cu parametri
	
	Locatie(const Locatie& l);											//constructor de copiere
	
	~Locatie();															//destructor

	string getDenumire();												//getter pentru denumire
	
	void setDenumire(string denumire);									//setter pentru denumire
	
	double getNrMAXlocuri();											//getter pentru nrMAXlocuri

	void setNrMAXlocuri(double nrMAXlocuri);							//setter pentru nrMAXlocuri
	
	double getNrRanduri();												//getter pentru nrRanduri

	void setNrRanduri(double nrRanduri);								//setter pentru nrRanduri
	
	int** getLocuri();													//getter pentru locuri
	
	void setLocuri(int** locuri, double nrRanduri, double nrColoane);	//setter pentru locuri

	friend istream& operator>>(istream& in, Locatie& l);				//supraincarcarea operatorului de citire
	
	friend ostream& operator<<(ostream& out, Locatie l);				//supraincarcarea operatorului de afisare

	int* operator[](int index);											//supraincarcarea operatorului []

	Locatie& operator++();												//supraincarcarea operatorului ++

	Locatie& operator--();												//supraincarcarea operatorului --
		
	bool checkLoc();

	bool Rezervare(double locuriRez);
};

