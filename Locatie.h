#pragma once
#include <string>
using namespace std;

class Locatie
{
private:
	string denumire;
	long nrMAXlocuri;
	long nrRanduri;
	int** locuri;

public:
	Locatie();															//constructor implicit

	Locatie(long nrRanduri, long nrMAXlocuri);							//constructor cu parametri
	
	Locatie(const Locatie& l);											//constructor de copiere
	
	~Locatie();															//destructor

	string getDenumire();												//getter pentru denumire
	
	void setDenumire(string denumire);									//setter pentru denumire
	
	long getNrMAXlocuri();												//getter pentru nrMAXlocuri

	void setNrMAXlocuri(long nrMAXlocuri);								//setter pentru nrMAXlocuri
	
	long getNrRanduri();												//getter pentru nrRanduri

	void setNrRanduri(long nrRanduri);									//setter pentru nrRanduri
	
	int** getLocuri();													//getter pentru locuri
	
	void setLocuri(int** locuri, long nrRanduri, long nrColoane);		//setter pentru locuri

	friend istream& operator>>(istream& in, Locatie& l);				//supraincarcarea operatorului de citire
	
	friend ostream& operator<<(ostream& out, Locatie l);				//supraincarcarea operatorului de afisare

	int* operator[](int index);											//supraincarcarea operatorului []

	Locatie& operator++();												//supraincarcarea operatorului ++

	Locatie& operator--();												//supraincarcarea operatorului --
		
	virtual bool checkLoc();													//metoda verifica loc

	bool Rezervare(long locuriRez);										//metoda rezerva locuri
};

