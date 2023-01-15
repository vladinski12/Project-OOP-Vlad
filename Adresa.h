#pragma once
#include "Locatie.h"
class Adresa :
    public Locatie
{
private:
	string strada;
	string numar;
	string oras;

public:
	Adresa();															//constructor implicit

	Adresa(string strada, string numar, string oras);					//constructor cu parametri

	Adresa(const Adresa& a);											//constructor de copiere		

	string getStrada();													//getter pentru denumire

	void setStrada(string strada);										//setter pentru denumire

	string getNumar();													//getter pentru nrMAXlocuri

	void setNumar(string numar);										//setter pentru nrMAXlocuri

	string getOras();													//getter pentru nrMAXlocuri

	void setOras(string oras);											//setter pentru nrMAXlocuri

	bool checkLoc();
	bool Rezervare(long locuriRez);
};

