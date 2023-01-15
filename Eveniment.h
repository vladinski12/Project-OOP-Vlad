#pragma once
#include <iostream>
#include <string>
#include "Locatie.h"
using namespace std;

class Eveniment : public Locatie
{
private:
	string data;
	string ora;
	char* denumire;

public:
	Eveniment();													//constructor implicit
	
	Eveniment(string data, string ora, const char* denumire);		//constructor cu parametrii
	
	Eveniment(const Eveniment& e);									//constructor de copiere
	
	~Eveniment();													//destructor
	
	string getData();												//getter pentru data
	
	void setData(string data);										//setter pentru data
	
	string getOra();												//getter pentru ora
	
	void setOra(string ora);										//setter pentru ora

	char* getDenumire();											//getter pentru denumire

	void setDenumire(const char* denumire);							//setter pentru denumire

	friend istream& operator>>(istream& in, Eveniment& e);			//supraincarcarea operatorului de citire

	friend ostream& operator<<(ostream& out, const Eveniment e);	//supraincarcarea operatorului de afisare

	Eveniment& operator=(const Eveniment& e);						//supraincarcarea operatorului de atribuire

	bool operator==(const Eveniment& e);							//supraincarcarea operatorului de egalitate

	bool operator!=(const Eveniment& e);							//supraincarcarea operatorului de inegalitate
		
	bool checkData();												//verificarea corectitudinii datei

	bool checkOra();												//actualizarea datei
	
};
