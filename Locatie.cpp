#include "Locatie.h"

Locatie::Locatie()
{
	nrRanduri=10;
	nrMAXlocuri = 100;
	double nrColoane = nrMAXlocuri / nrRanduri;
	locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
}

Locatie::Locatie(double nrRanduri, double nrMAXlocuri, int** locuri)
{
	this->nrRanduri = nrRanduri;
	this->nrMAXlocuri =nrMAXlocuri;
	double nrColoane = nrMAXlocuri / nrRanduri;
	this->locuri = new int* [nrRanduri];
	for (int i = 0; i < nrRanduri; i++) this->locuri[i] = new int[nrColoane];
	for (int i = 0; i < nrRanduri; i++)
		for (int j = 0; j < nrColoane; j++)
			locuri[i][j] = 0;
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
double  Locatie::getNrMAXlocuri() {
	return nrMAXlocuri; 
}
void  Locatie::setNrMAXlocuri(double nrMAXlocuri) {
	if (nrMAXlocuri >= 0){
		this->nrMAXlocuri = nrMAXlocuri; 
	}
}
double  Locatie::getNrRanduri() {
	return nrRanduri; 
}
void  Locatie::setNrRanduri(double nrRanduri) {
	if (nrRanduri >= 0) {
		this->nrRanduri = nrRanduri;
	}
}
int** Locatie::getLocuri() {
	return locuri;
}
	
void  Locatie::setLocuri(int** locuri, double nrRanduri, double nrColoane){
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