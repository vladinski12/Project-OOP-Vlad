#include<iostream>
#include<string>
#include "Locatie.h"
using namespace std;

Locatie::Locatie()
{
	nrRanduri=10;
	nrMAXlocuri = 100;
	long nrColoane = nrMAXlocuri / nrRanduri;
	locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
}

Locatie::Locatie(long nrRanduri, long nrMAXlocuri)
{
	this->nrRanduri = nrRanduri;
	this->nrMAXlocuri =nrMAXlocuri;
	long nrColoane = nrMAXlocuri / nrRanduri;
	this->locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) this->locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
}

Locatie::Locatie(const Locatie& l) {
	this->nrRanduri = l.nrRanduri;
	this->nrMAXlocuri = l.nrMAXlocuri;
	long nrColoane = nrMAXlocuri / nrRanduri;
	this->locuri = new int* [l.nrRanduri];
	for (int i = 0; i < nrRanduri; i++) this->locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			this->locuri[i][j] = 0;
}


Locatie::~Locatie() {
	if (locuri != nullptr) {
			for (int i = 0; i < nrRanduri; i++) {
				delete[] locuri[i];
			}
		delete[] locuri;
	}
}

string Locatie::getDenumire() {
	return denumire;
}
void Locatie::setDenumire(string denumire) {
	if (denumire != "") {
		this->denumire = denumire;
	}
}
long  Locatie::getNrMAXlocuri() {
	return nrMAXlocuri; 
}
void  Locatie::setNrMAXlocuri(long nrMAXlocuri) {
	if (nrMAXlocuri >= 0){
		this->nrMAXlocuri = nrMAXlocuri; 
	}
}
long  Locatie::getNrRanduri() {
	return nrRanduri; 
}
void  Locatie::setNrRanduri(long nrRanduri) {
	if (nrRanduri >= 0) {
		this->nrRanduri = nrRanduri;
	}
}
int** Locatie::getLocuri() {
	return locuri;
}
	
void  Locatie::setLocuri(int** locuri, long nrRanduri, long nrColoane){
	if (locuri != nullptr) {
		if (this->locuri != nullptr) {
			for (int i = 0; i < nrRanduri; i++) {
				delete[] this->locuri[i];
			}
			delete[] this->locuri;
		}
		this->locuri = new int* [nrRanduri];
		for (int i = 0; i < nrRanduri; i++) this->locuri[i] = new int[nrColoane];
		for (int i = 0; i < nrRanduri; i++)
			for (int j = 0; j < nrColoane; j++)
				this->locuri[i][j] = locuri[i][j];
	}
}

istream& operator>>(istream& in, Locatie& l) {
	cout << "Denumire locatie: ";
	in >> l.denumire;
	cout << "Numar randuri: ";
	in >> l.nrRanduri;
	cout << "Numar locuri: ";
	in >> l.nrMAXlocuri;
	long nrColoane = l.nrMAXlocuri / l.nrRanduri;
	l.locuri = new int* [l.nrRanduri];
	for (int i = 0; i < l.nrRanduri; i++) l.locuri[i] = new int[nrColoane];
	for (int i = 0; i < l.nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			l.locuri[i][j] = 0;
	return in;
}

ostream& operator<<(ostream& out, Locatie l) {
	out << "Denumire locatie: " << l.denumire << endl;
	out << "Numar randuri: " << l.nrRanduri << endl;
	out << "Numar locuri: " << l.nrMAXlocuri << endl;
	long nrColoane = l.nrMAXlocuri / l.nrRanduri;
	for (int i = 0; i < l.nrRanduri; i++) {
		for (int j = 0; j < nrColoane; j++) {
			out << l.locuri[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

int* Locatie::operator[](int index) {
	if (index >= 0 && index < nrRanduri) {
		return locuri[index];
	}
}

Locatie& Locatie::operator++() {
	if (locuri != nullptr) {
		for (int i = 0; i < nrRanduri; i++) {
			delete[] locuri[i];
		}
		delete[] locuri;
	}
	nrRanduri++;
	long nrColoane = nrMAXlocuri / nrRanduri;
	locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
	return *this;
}

Locatie& Locatie::operator--() {
	if (locuri != nullptr) {
		for (int i = 0; i < nrRanduri; i++) {
			delete[] locuri[i];
		}
		delete[] locuri;
	}
	nrRanduri--;
	long nrColoane = nrMAXlocuri / nrRanduri;
	locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
	return *this;
}

bool Locatie::checkLoc() {

	int nrLocuri = 0;
	for (int i = 0; i < nrRanduri; i++) {
		for (int j = 0; j < nrMAXlocuri/nrRanduri; j++) {
			if (locuri[i][j] == 1) {
				nrLocuri++;
			}
		}
	}
	if (nrLocuri < nrMAXlocuri) {
		return true;
	}
	else {
		return false;
	}
}

bool Locatie::Rezervare(long locuriRez) {
	int locPosibile = 0;
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrMAXlocuri / nrRanduri; j++) {
			if (locuri[i][j] ==0) {
				locPosibile++;
				}
			}
	if (locPosibile<locuriRez)return false;
	else {
		for (int i = 0; i < nrRanduri; i++)
			for (int j = 0; j < nrMAXlocuri / nrRanduri; j++) {
				if (locuri[i][j] != 1) {
					locuri[i][j] = 0;
				}
			}
	}
	return true;
}

	